## Pointers & Dynamic Memory
Pointers are variables that store the memory address of another variable.

Modularity is letting a function reach the caller's variables, it points to a variable and lets you modify it without passing it as an argument.

Dynamic memory is memory that is allocated at runtime using pointers. It allows for flexible memory management.

```cpp
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int z = 5;
int w = 10;
swap(&z, &w);
```

### Automatic vs Dynamic Memory

| Automatic | Dynamic |
|-----------|---------|
| Lives on the stack | Lives on the heap |
| Allocated at compile time | Allocated at runtime |
| Deallocated automatically when the function ends | Must be deleted manually using `delete` |
| Size must be known at compile time | Size can be determined at runtime |

### Arrays and pointers

The new operator is used to allocate memory dynamically, and the delete operator is used to free that memory.

Arrays can be handled with pointers, arr[j] is equivalent to *(arr[j])

Static Array and Dynamic Array:
```cpp
// Static array
int data[200];

for (j = 0; j < 200; j++){
    cin >> data;
}
```

```cpp
// Dynamic Array
int *data, n;
cin >> n;

data = new int[n];  

for (j = 0; j < n; j++){
    cin >> data[j];
}

delete[] data;
```

## Lists

A list is a sequence of elements, it is an abstract data type. Each element has a position, there is a first, second, third, last, etc. Every element knows which one comes after it.

Operations:
- Insert (put an element in)
- Remove (take an element out)
- Size (how many elements)
- Traverse (visit every element in order once)
- Find (in what position is an element)

The main differences between an array and a vector is that the array is a fixed size, whenever the array is full it doubles in size for the next element, copying the array completely. The vector grows while the program runs and doesn't have a fixed size.

### Simple linked list

In order to avoid the linear cost of insertion and deletion, we need to ensure that the list is not being stored contiguously.

Each part of the list has a pointer leading to the next element. A typical linked list keeps links to both ends of the list. The last node's link points to `nullptr` this is how the list knows it is the end.

```cpp
struct Node{
    int data; // element
    Node *next; // link to the next node
}
```

### Double linked list

This is when every node points to the previous and next node, this means that each node now carries two links instead of one and every operation like insertion or removal has to keep both consistent. Each node remembers the one before it.

