## Binary Search Trees & AVL Trees

To find the height of a BST step by step:
```cpp
int height() const { return height(root); }

int height(Node* n) const{
    if (n == nullptr) return -1;
    int hl = height(n->left);
    int hr = height(n->right);
    return 1 + std::max(hl, hr);
}
```
Characteristics of height:
- The height is the largest number of edges from the root to a leaf. 
- The height of an empty tree is defined as -1
- The height of a tree with just one node (the root) is 0.

### AVL Trees

- AVL trees are a type of self-balancing binary search tree.
- In an AVL tree, the heights of the two child subtrees of any node differ by at most one. 
- If at any time they differ by more than one, rebalancing is done to restore this property.
- The balance factor is defined as the height of the right subtree minus the height of the left subtree.
- If the balance factor is greater than 1 or -1 the tree is unbalanced

### Rotations:

- For every rotation there are 4 cases which are:
  - right-right (rotate left once) ( + + )
  - right-left (rotate right then left) ( + - )
  - left-left (rotate right once) ( - - )
  - left-right (rotate left then right) ( - + )
