#include "Nodo.h"
#include <iostream>

template<typename A> class BTree{
public:
    BTree(int size): m_nMaxSize(size), m_proot(NULL){}
    ~BTree();
    Triple<A> Search(const A item);
    int Size();
    int Size(BTreeNode<A> *root);
    bool Insert(const A item);   //insert item
    bool Remove(const A item);   //delete item
    void Print();                   //print the BTree
    BTreeNode<A>*GetParent(const A item);   
private:
    void InsertKey(BTreeNode<A> *pinsert, int n, const A item, BTreeNode<A>*pright);
    void PreMove(BTreeNode<A> *root, int n); //move ahead
    void Merge(BTreeNode<A> *pleft, BTreeNode<A> *pparent,BTreeNode<A> *pright, int n);
    void LeftAdjust(BTreeNode<A> *pright, BTreeNode<A> *pparent, int min, int n);
    void RightAdjust(BTreeNode<A> *pleft, BTreeNode<A> *pparent, int min, int n);
    void Print(BTreeNode<A> *start, int n = 0);

private:

    BTreeNode<A> *m_proot;
    const int m_nMaxSize;

};

template<typename A>BTree<A>::~BTree(){
    m_proot->Destroy(m_proot);
}

template<typename A>Triple<A> BTree<A>::Search(const A item){
    Triple<A> result;
    BTreeNode<A> *pmove =m_proot, *parent = NULL;
    int i = 0;
    while(pmove){
        i = -1;
        while(item > pmove->m_pkey[++i]);
        if(*(pmove->m_pkey + i) == item){
            result.m_pfind = pmove;
            result.m_nfind = i;
            result.m_ntag = 1;
            return result;
        }
        parent = pmove;
        pmove =*(pmove->m_ptr + i);   
   }
    result.m_pfind = parent;
    result.m_nfind = i;
    result.m_ntag = 0;
    return result;
}

 

template<typename A> void BTree<A>::InsertKey(BTreeNode<A> *pinsert, int n, const A item, BTreeNode<A> *pright){
    pinsert->m_nsize++;
   for (int i=pinsert->m_nsize; i>n; i--){
        *(pinsert->m_pkey + i) =*(pinsert->m_pkey + i-1);
        *(pinsert->m_ptr + i + 1) = *(pinsert->m_ptr + i);
    }
    *(pinsert->m_pkey + n) = item;
    *(pinsert->m_ptr + n + 1) = pright;
    if(*(pinsert->m_ptr + n+1)){       //change the right child tree's parent
        auto c1 =*(pinsert->m_ptr + n + 1);
        c1->m_pparent = pinsert;
        
        for(int i=0;i<=c1->m_nsize; i++){
            if( *(c1->m_ptr + i) ){
                auto c2 = *(c1->m_ptr + i);
                c2->m_pparent = *(pinsert->m_ptr + n+1);
            }
        }
    }
}

template<typename A> bool BTree<A>::Insert(const A item){
    if(NULL == m_proot){ 
        m_proot = new BTreeNode<A>(m_nMaxSize);
        m_proot->m_nsize = 1;
        *(m_proot->m_pkey + 1) = *(m_proot->m_pkey+0);
        *(m_proot->m_pkey + 0) =item;
        *(m_proot->m_ptr + 0) = *(m_proot->m_ptr + 1) =NULL;
        return 1;
    }
    Triple<A> find = this->Search(item);
    if(find.m_ntag){
        std::cout << "Theitem is exist!" << std::endl;
        return 0;
    }

    BTreeNode<A> *pinsert =find.m_pfind, *newnode;
    BTreeNode<A> *pright =NULL, *pparent;
    A key = item;
    int n = find.m_nfind;
    while(1){
        if(pinsert->m_nsize < pinsert->m_nMaxSize-1){  //There is somespace
            InsertKey(pinsert, n,key, pright);
            return 1;
        }
        int m = (pinsert->m_nsize + 1) / 2;     //get the middle item
        InsertKey(pinsert, n, key,pright);     //insertfirst, then break up
        newnode = new BTreeNode<A>(this->m_nMaxSize);//create the newnode for break up
        //breakup
        for(int i=m+1; i<=pinsert->m_nsize;i++){     
            *(newnode->m_pkey + i-m-1) = *(pinsert->m_pkey + i);
            *(newnode->m_ptr + i-m-1) = *(pinsert->m_ptr + i);
            *(pinsert->m_pkey + i) =pinsert->m_Infinity;

            *(pinsert->m_ptr + i) =NULL;

        }
        newnode->m_nsize =pinsert->m_nsize - m - 1;
        pinsert->m_nsize = m;

        for(int i=0; i<=newnode->m_nsize; i++){    //change theparent
            if(*(newnode->m_ptr + i)){
                auto a2 = *(newnode->m_ptr + i); 
                a2->m_pparent = newnode;
                for (int j=0;j<=a2->m_nsize; j++){
                    if (*(a2->m_ptr + j)){
                        auto a3 = *(a2->m_ptr + j);
                        a3->m_pparent = *(newnode->m_ptr + i);
                    }
                }
            }
        }
        for(int i=0; i<=pinsert->m_nsize; i++){    //change theparent
            if(*(pinsert->m_ptr + i)){
                auto b1 = *(pinsert->m_ptr + i);
                b1->m_pparent = pinsert;
                for (int j=0;j<=pinsert->m_nsize; j++){
                    auto b2 = *(pinsert->m_ptr + i);
                    if (*(b2->m_ptr + j)){
                        auto b3 = *(b1->m_ptr + j);
                        b3->m_pparent = *(pinsert->m_ptr + i);
                    }
                }
            }
        }
        //breakup over
        key = *(pinsert->m_pkey + m);
        pright = newnode;
        if(pinsert->m_pparent){    //insert the key to the parent
            pparent = pinsert->m_pparent;
            n = -1;
            *(pparent->m_pkey + pparent->m_nsize) = pparent->m_Infinity;
            while(key > pparent->m_pkey[++n]);
            newnode->m_pparent =pinsert->m_pparent;
            pinsert = pparent;
        }
        else{              //createnew root
            m_proot = new BTreeNode<A>(this->m_nMaxSize);
            m_proot->m_nsize = 1;
            *(m_proot->m_pkey + 1) = *(m_proot->m_pkey + 0);
            *(m_proot->m_pkey + 0) =key;
            *(m_proot->m_ptr + 0) =pinsert;
            *(m_proot->m_ptr + 1) =pright;
            newnode->m_pparent =pinsert->m_pparent = m_proot;
            return 1;
        }
    }
}

template<typename A> void BTree<A>::PreMove(BTreeNode<A>*root, int n){
    *(root->m_pkey + root->m_nsize) = root->m_Infinity;
    for(int i=n; i<root->m_nsize; i++){
        *(root->m_pkey + i) = *(root->m_pkey + i + 1);
        *(root->m_ptr + i + 1) = *(root->m_ptr + i+2);
    }
    root->m_nsize--;
}

template<typename A> void BTree<A>::Merge(BTreeNode<A>*pleft, BTreeNode<A> *pparent, BTreeNode<A> *pright, int n){
   *(pleft->m_pkey + pleft->m_nsize) = *(pparent->m_pkey + n);
    BTreeNode<A> *ptemp;
    for(int i=0; i<=pright->m_nsize; i++){ //merge the two child tree and the parent
        *(pleft->m_pkey + pleft->m_nsize+i+1)= *(pright->m_pkey + i);
        *(pleft->m_ptr + pleft->m_nsize+i+1) = *(pright->m_ptr + i);
        ptemp = *(pleft->m_ptr + pleft->m_nsize+i+1);
        if(ptemp){         //changethd right child tree's parent
            ptemp->m_pparent = pleft;
            for(int j=0; j<=ptemp->m_nsize; j++){
                if (*(ptemp->m_ptr +j)){
                    auto g1 = *(ptemp->m_ptr + j);
                    g1->m_pparent = ptemp;
                }
            }
        }
    }
    pleft->m_nsize =pleft->m_nsize + pright->m_nsize + 1;
    delete pright;
    PreMove(pparent, n);   
//   this->Print();
}

template<typename A> void BTree<A>::LeftAdjust(BTreeNode<A> *pright,BTreeNode<A> *pparent, int min, int n){

    BTreeNode<A> *pleft = *(pparent->m_ptr + n-1), *ptemp;

    if(pleft->m_nsize > min-1){

        for(int i=pright->m_nsize+1; i>0; i--){
            *(pright->m_pkey + i) = *(pright->m_pkey + i-1);
            *(pright->m_ptr + i) = *(pright->m_ptr + i-1);
        }
        *(pright->m_pkey + 0) = *(pparent->m_pkey + n-1);
        *(pright->m_ptr + 0) = *(pleft->m_ptr + pleft->m_nsize);
        ptemp = *(pright->m_ptr + 0);
        if(ptemp){     //changethe tree's parent which is moved
            ptemp->m_pparent =pright;
            for(int i=0; i<ptemp->m_nsize; i++){
                if(*(ptemp->m_ptr + i)){
                    auto d1 = *(ptemp->m_ptr + i);
                    d1->m_pparent = ptemp;
                }
            }
        }
        *(pparent->m_pkey + n-1) = *(pleft->m_pkey + pleft->m_nsize-1);
        *(pleft->m_pkey + pleft->m_nsize) = pleft->m_Infinity;
        pleft->m_nsize--;
        pright->m_nsize++;
    }
    else{
        Merge(pleft, pparent,pright, n-1);
    }
//      this->Print();
}

template<typename A> void BTree<A>::RightAdjust(BTreeNode<A> *pleft,BTreeNode<A> *pparent, int min, int n){
    BTreeNode<A> *pright =*(pparent->m_ptr + 1), *ptemp;
    if(pright && pright->m_nsize > min-1){
        *(pleft->m_pkey + pleft->m_nsize) = *(pparent->m_pkey + 0);
        *(pparent->m_pkey + 0) =*(pright->m_pkey + 0);
        *(pleft->m_ptr + pleft->m_nsize+1) = *(pright->m_ptr + 0);
        ptemp = *(pleft->m_ptr + pleft->m_nsize+1);
        if(ptemp){         //changethe tree's parent which is moved
            ptemp->m_pparent =pleft;
            for(int i=0; i<ptemp->m_nsize; i++){
                if (*(ptemp->m_ptr + i)){
                    auto e1 = *(ptemp->m_ptr + i);
                    e1->m_pparent = ptemp;
                }
            }
        }
        *(pright->m_ptr + 0) = *(pright->m_ptr + 1);
        pleft->m_nsize++;
        PreMove(pright,0);
    }
    else{
        Merge(pleft, pparent, pright,0);
    }
}

template<typename A> bool BTree<A>::Remove(const A item){
    Triple<A> result = this->Search(item);
    if(!result.m_ntag){
        return 0;
    }
    BTreeNode<A> *pdel,*pparent, *pmin;
    int n = result.m_nfind;
    pdel = result.m_pfind;
    if(*(pdel->m_ptr + n+1) != NULL){  //change into delete leafnode
        pmin = *(pdel->m_ptr + n+1);
        pparent = pdel;
        while(pmin != NULL){
            pparent = pmin;
            pmin = *(pmin->m_ptr + 0);
        }
        *(pdel->m_pkey + n) = *(pparent->m_pkey + 0);
        pdel = pparent;
        n = 0;
    }

    PreMove(pdel, n); //delete the node
    int min = (this->m_nMaxSize + 1) / 2;
    while(pdel->m_nsize < min-1){  //if it is not a BTree, then adjust
        n = 0;
        pparent = pdel->m_pparent;
        if(NULL == pparent)
        {
            return 1;
        }
        while(n<= pparent->m_nsize && *(pparent->m_ptr + n)!=pdel){
            n++;
        }
        if(!n){
            RightAdjust(pdel,pparent, min, n); //adjust with the parent and theright child tree
        }
        else{
            LeftAdjust(pdel,pparent, min, n); //adjust with the parent and theleft child tree
        }
        pdel = pparent;
        if(pdel == m_proot){
            break;
        }
    }
    if(!m_proot->m_nsize){         //the root is merged
        pdel = *(m_proot->m_ptr + 0);
        delete m_proot;
        m_proot = pdel;
        m_proot->m_pparent =NULL;
        for(int i=0; i<m_proot->m_nsize; i++){
            if(*(m_proot->m_ptr + i)){
                auto f1 = *(m_proot->m_ptr + i);
                f1->m_pparent = m_proot;
            }
        }
    }
    return 1;
}

template<typename A> 
void BTree<A>::Print(BTreeNode<A>*start, int n){
    if(NULL == start){
        return;
    }
    if(start->m_ptr[0]){
        Print(*(start->m_ptr + 0),n+1);   
    }
    else{
        for(int j=0; j<n; j++){
            std::cout << "     ";
        }
        std::cout << "NULL" << std::endl;
    }
    for(int i=0; i<start->m_nsize; i++){   //print the ortherchild tree
        for(int j=0; j<n; j++){
            std::cout << "     ";
        }
        std::cout <<*(start->m_pkey + i) << "--->"<< std::endl;
        if(*(start->m_ptr + i+1)){
           Print(*(start->m_ptr + i+1), n+1);
        }
        else{
            for(int j=0; j<n; j++){
                std::cout << "     ";
            }
            std::cout << "NULL" << std::endl;
        }
    }
}

template<typename A> void BTree<A>::Print(){
    Print(m_proot);
}

template<typename A> int BTree<A>::Size(BTreeNode<A>*root){
    if(NULL == root){
        return 0;
    }
    int size=root->m_nsize;
    for(int i=0; i<=root->m_nsize; i++){
        if(*(root->m_ptr + i)){
            size += this->Size(*(root->m_ptr + i));
        }
    }
    return size;
}

template<typename A> int BTree<A>::Size(){
    return this->Size(this->m_proot);
}

 

template<typename A>BTreeNode<A>* BTree<A>::GetParent( const A item){
    Triple<A> result = this->Search(item);
    return result.m_pfind->m_pparent;
}