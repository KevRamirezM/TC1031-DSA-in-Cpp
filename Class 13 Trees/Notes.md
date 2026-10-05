## Trees & Binary Search Trees

### Basic Concepts

- The root node in trees is the only node with no parent
- The leaf node is a node that has no children (last)
- If two nodes share a parent they are siblings
- A path is a sequence of nodes that one is parent of the next
- A subtree is a node with everything below it (all nodes below)
- Depth is the length of the path from the root (starts at 0 from the root)
- Height is the longest path from a node to a leaf below it
- Degree is the number of children a node has

#### The three ways to traverse a tree are:

- Inorder is when you visit the left subtree, then the root and then the right subtree
- Preorder is when you visit the root first, then the left subtree and then right subtree
- Postorder is when you visit the left subtree, then the right subtree and then the root.

#### Implementing tree traversal function:
```cpp
void inorder(Node*n) const{
    if(n == nullptr) return;
    inorder(n->left);
    std::cout << n->info << " ";
    inorder(n->right);
}
```
### Binary Trees

In a binary tree no node has more than **TWO** children, a binary tree is either empty or a root with a left subtree or a right subtree

A binary search tree is a tree that has all values in its left subtree are smaller than the root and all the values in its right subtree are greater than the root. 

Each comparison discards a whole subtree, it searches once per depth level. Here is the traversal of a binary search tree:

```cpp
Node* search(Node* n, int x) const{
    if (n == nullptr) return nullptr;
    if (x < n->info) return search(n->left, x);
    if (x > n->info) return search(n->right, x);
    return n;
}
Node* search(int x) const{ return search(root, x); }
```

This function returns a pointer to the node, so the caller can use what is stored there. 

If you want to **insert** a number in a binary search tree you can go to the position using search until you have a nullptr, when this happens you can insert the element in that position.

```cpp
bool insert(Node*& n, int x) {  // n: a reference to a link
    if (n == nullptr) {    // free spot found
        n = new Node{x, nullptr, nullptr};
        return true;
    }
    if (x < n->info) return insert(n->left, x);
    if (x > n->info) return insert(n->right, x);
    return false;    // repeated value: rejected
}
bool insert(int x) { return insert(root, x); }   // public
```

#### Deletion

Deletion has 3 cases:

- Deleting a leaf just deletes the node and the pointer becomes null
- Deleting a child just deletes and shifts the below child to replace the position of the deleted node.
- Deleting two children is when the node stays and recieves a replacement value. Check which number can replace based on one of its two neighbours.