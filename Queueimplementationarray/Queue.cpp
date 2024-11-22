#include <stdexcept> // For exception handling

// Node structure for the linked list
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) {
        data = value;
        next = nullptr;
    }
};

// Queue implementation using a linked list
template <typename T>
class Queue {
private:
    Node<T>* head; // Pointer to the first node
    Node<T>* tail; // Pointer to the last node
    int queueSize; // Variable to track the size of the queue

public:
    // Constructor
    Queue() {
        head = nullptr;
        tail = nullptr;
        queueSize = 0;
    }

    // Enqueue: Add an element to the end of the queue
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail == nullptr) { // If the queue is empty
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        queueSize++;
    }

    // Dequeue: Remove an element from the front of the queue
    T dequeue() {
        if (head == nullptr) {
            throw std::underflow_error("Queue is empty");
        }
        T temp = head->data;
        Node<T>* oldHead = head;
        head = head->next;
        if (head == nullptr) { // If the queue is now empty, update tail
            tail = nullptr;
        }
        delete oldHead;
        queueSize--;
        return temp;
    }

    // Peek: Get the element at the front of the queue without removing it
    T peek() {
        if (head == nullptr) {
            throw std::underflow_error("Queue is empty");
        }
        return head->data;
    }

    // IsEmpty: Check if the queue is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Size: Get the current size of the queue
    int size() {
        return queueSize;
    }

    // Destructor
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
