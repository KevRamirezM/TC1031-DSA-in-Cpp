## Splay Trees

A splay tree is a self-adjusting binary search tree with the additional property that recently accessed elements are quick to access again.

Most operations on a splay tree take O(log n) time, where n is the number of nodes in the tree. However, the amortized time for a sequence of m operations is O(m log n).

The main idea is to do an operation that moves the accessed node to the root of the tree using a series of tree rotations. This process is called "splaying".

Characteristics of splay trees:
- Every time you do an operation (insert, delete, search), you splay the accessed node to the root.
- Splay trees do not require any additional memory for balancing information.
- Zig is to the left and zag is to the right. The splay operation consists of six types of rotations: zig, zag, zig-zig, zag-zag, and zig-zag.
- When performing zig-zig and zag-zag rotations rotate first the parent and then the grandparent.

Splay trees are used when some information needs to be faster to use than others, such as in caches, garbage collection, and other applications where the access pattern is non-uniform.

