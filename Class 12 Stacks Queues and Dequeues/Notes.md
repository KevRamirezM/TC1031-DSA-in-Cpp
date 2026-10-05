## Linear Data Structures

The four data structures are defined by which element leaves next, the newest (stack), the oldest (queue), both ends (dequeue) and by priority (priority queue)

### Stacks

A stack inserts and removes at the same end, the top. The last element is the first one out (LIFO)

- Push(x) adds a new element at the top (x)
- pop() removes the top element
- getTop() reads the top element without removing it.

Push and pop only touches the top element, doesnt matter how many elements are below this. Top is -1 if there are no elements in the stack.

Implementation of a Stack in an Array: 
```cpp
	// members: static const int MAX = 5;  int data[MAX];  int top = -1;
bool push(int x) {
    if (top == MAX - 1) return false;   // full: x is lost
    data[++top] = x;
    return true;
}
bool pop() {
    if (top == -1) return false;        // empty
    --top;                              // no need to erase
    return true;
}
int getTop() const { return data[top]; }   // caller checks first
```

Implementation of a Stack in a Linked List:
```cpp
// struct Node { int info; Node* next; };
// member: Node* head = nullptr;         (the head is the top)
void push(int x) { head = new Node{x, head}; }
bool pop() {
    if (head == nullptr) return false;  // empty
    Node* old = head;
    head = head->next;
    delete old;
    return true;
}
int getTop() const { return head->info; }
~ListStack() { while (pop()) {} }       // free every node
```

| Function | Fixed array | Linked list | `std::vector` |
| :--- | :--- | :--- | :--- |
| **push** | O(1), fails when full | O(1), one `new` | O(1) amortized |
| **pop · getTop** | O(1) | O(1), one `delete` | O(1) |
| **Extra memory** | MAX slots reserved up front | one pointer per element | spare capacity after growth |

### Queues

The queue insets at one end (the back) and removes at the other (removes first element) this means the first element is the first one out (FIFO).

- enqueue(x) adds at the back
- dequeue() removes the fromt
- getFront() reads the element at the front
- front marks the first element to leave
- back marks the last one that entered the queue.

A plain array doesnt work in this data structure because when you remove the front element, all the other elements have to be shifted down.

Circular queue implementation:
```cpp
	// static const int MAX = 5;  int data[MAX];  int front = 0, count = 0;
bool enqueue(int x) {
    if (count == MAX) return false;        // full
    data[(front + count) % MAX] = x;       // the back slot
    ++count;
    return true;
}
bool dequeue() {
    if (count == 0) return false;          // empty
    front = (front + 1) % MAX;             // wrap around
    --count;
    return true;
}
```

Linked list implementation:
```cpp
	// members: Node* head = nullptr;  Node* tail = nullptr;
void enqueue(int x) {                 // at the back: O(1)
    Node* n = new Node{x, nullptr};
    if (tail) tail->next = n; else head = n;
    tail = n;
}
bool dequeue() {                      // at the front: O(1)
    if (!head) return false;
    Node* old = head;
    head = head->next;
    if (!head) tail = nullptr;        // it was the last node
    delete old;
    return true;
}
```

|Function| Array + shifting | Circular array | Linked list (head + tail) |
| :--- | :--- | :--- | :--- |
| **enqueue** | O(1), fails when full | O(1), fails when full | O(1) |
| **dequeue** | O(n): shifts n - 1 elements | O(1) | O(1) |
| **Capacity** | fixed | fixed | only limited by memory |

### Deque

A deque (double ended queue) inserts and removes at the front and the back. It is stored as a doubly linked list with two pointers, front and back, each node knows its previous so popBack is O(1) operation.

popFront implementation: (3 cases)
```cpp
	bool popFront() {
    if (front == nullptr) return false;       // case 1: empty
    DNode* old = front;
    if (front == back) {                      // case 2: one node
        front = back = nullptr;
    } else {                                  // case 3: two or more
        front = front->next;
        front->prev = nullptr;
    }
    delete old;
    return true;
}
```