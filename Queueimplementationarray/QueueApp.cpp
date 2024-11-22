#include <iostream>
#include "Queue.cpp"
#include <string>

int main() {
    Queue<std::string> q1;

    // Testing enqueue
    q1.enqueue("first");
    q1.enqueue("second");
    q1.enqueue("third");

    // Testing size
    std::cout << "Queue size: " << q1.size() << std::endl;

    // Testing peek
    std::cout << "Front element: " << q1.peek() << std::endl;

    // Testing dequeue
    std::cout << "Dequeued: " << q1.dequeue() << std::endl;
    std::cout << "Dequeued: " << q1.dequeue() << std::endl;

    // Testing size after dequeue
    std::cout << "Queue size after dequeues: " << q1.size() << std::endl;

    // Testing isEmpty
    std::cout << "Is queue empty? " << (q1.isEmpty() ? "Yes" : "No") << std::endl;

    // Dequeue remaining element
    std::cout << "Dequeued: " << q1.dequeue() << std::endl;

    // Testing isEmpty after all elements are dequeued
    std::cout << "Is queue empty after all dequeues? " << (q1.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
