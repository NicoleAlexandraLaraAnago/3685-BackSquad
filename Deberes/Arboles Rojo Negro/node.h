enum COLOR { RED, BLACK };

class Node {
public:
  int val;
  COLOR color;
  Node *left, *right, *parent;
 
  Node(int val) : val(val) {
    parent = left = right = nullptr;
 
    // Node is created during insertion
    // Node is red at insertion
    color = RED;
  }
 
  // returns pointer to uncle
  Node *uncle() {
    // If no parent or grandparent, then no uncle
    if (parent == nullptr or parent->parent == nullptr)
      return nullptr;
 
    if (parent->isOnLeft())
      // uncle on right
      return parent->parent->right;
    else
      // uncle on left
      return parent->parent->left;
  }
 
  // check if node is left child of parent
  bool isOnLeft() { return this == parent->left; }
 
  // returns pointer to sibling
  Node *sibling() {
    // sibling null if no parent
    if (parent == nullptr)
      return nullptr;
 
    if (isOnLeft())
      return parent->right;
 
    return parent->left;
  }
 
  // moves node down and moves given node in its place
  void moveDown(Node *nParent) {
    if (parent != nullptr) {
      if (isOnLeft()) {
        parent->left = nParent;
      } else {
        parent->right = nParent;
      }
    }
    nParent->parent = parent;
    parent = nParent;
  }
 
  bool hasRedChild() {
    return (left != nullptr and left->color == RED) or
           (right != nullptr and right->color == RED);
  }
};
 