template<typename A> class BTree;

template<typename A> class BTreeNode{
public:
    friend BTree<A>;
    BTreeNode(): m_nMaxSize(0),m_ptr(NULL), m_pparent(NULL){}

    BTreeNode(int size): m_nsize(0), m_nMaxSize(size),m_pparent(NULL){
        // m_pkey = new A[size+1];
        m_pkey = (A*)malloc((size+1)*sizeof(A));
        // m_ptr = new BTreeNode<A> *[size+1];
        m_ptr = (BTreeNode<A>**)malloc((size+1)*sizeof(BTreeNode<A>*));
        for(int i=0; i<=size; i++){
            // m_ptr[i] = NULL;
            *(m_ptr + i) = nullptr;
            // m_pkey[i] = this->m_Infinity;
            *(m_pkey + i) = this->m_Infinity;
        }
    }
    void Destroy(BTreeNode<A> *root);
    ~BTreeNode(){
      if(m_nMaxSize){
        // delete[]m_pkey;
        free(m_pkey);
        for(int i=0; i<=m_nMaxSize; i++){
           *(m_ptr + i) = nullptr;
        }
      }
    }

    bool IsFull(){
        return m_nsize == m_nMaxSize;
    }

    A GetKey(int i){
        if(this){
            return *(this->m_pkey + i);
        }
        return-1;
    }
private:
    int m_nsize;
    int m_nMaxSize;     //theMax Size of key
    A *m_pkey;
    BTreeNode<A>* m_pparent;
    BTreeNode<A>** m_ptr;
    static const A m_Infinity = 10000;

};

template<typename A> struct Triple{
    BTreeNode<A> *m_pfind;
    int m_nfind;
    bool m_ntag;
};

template<typename A> void BTreeNode<A>::Destroy(BTreeNode<A> *root){
    if(NULL == root){
        return;
    }
    for(int i=0; i<root->m_nsize; i++){
        Destroy(*(root->m_ptr + i));
    }

    delete root;

}
