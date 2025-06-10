//
// Created by Levi on 2025-06-10.
//

#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
/*Notes:
 * Functions in the queue class:
 * enqueue - Adds a new element to the end of the queue.
 * dequeue - Removes and returns the front element of the queue.
 * getLast - Returns the last element of the queue without removing it.
 * getFirst - Returns the first element of the queue without removing it.
 * getSize - Returns the number of elements in the queue.
 * isEmpty - Checks if the queue is empty.
 */

template<typename T>
class Queue {
public:
    Queue();
    ~Queue();
    void enqueue(const T& value); // Adds a new element to the end of the queue
    T dequeue();                  // Removes and returns the front element of the queue
    T& getFirst() const;          // Returns the first element without removing it
    T& getLast() const;           // Returns the last element without removing it
    int getSize() const;       // Returns the number of elements in the queue
    bool isEmpty() const;         // Checks if the queue is empty
private:
    LinkedList<T> list;           // Linked list to store the elements of the queue
    size_t size;                  // Size of the queue
};

/*
 * Name: Queue constructor
 * Description: Initializes an empty queue.
 * Parameters: None
 * Returns: void - No return value.
 */
template<typename T>
Queue<T>::Queue() : size(0) {};

/*
 * Name: Queue destructor
 * Description: Cleans up the queue by deleting the linked list to prevent memory leaks.
 * Parameters: None
 * Returns: void - No return value.
 */
template<typename T>
Queue<T>::~Queue() {
    // The LinkedList destructor will automatically delete all nodes,
    // so we do not need to manually delete anything here.
    // If you want to reset the size counter for safety:
    size = 0;
}

/*
 * Name: Queue.enqueue
 * Description: Adds a new element to the end of the queue.
 * Parameters: value - The value to be added to the queue.
 * Returns: void - No return value.
 */
template<typename T>
void Queue<T>::enqueue(const T& value) {
    // Use the append method of the linked list to add the element
    list.append(value);
    size++;
}

/*
 * Name: Queue.dequeue
 * Description: Removes and returns the front element of the queue.
 * Parameters: None
 * Returns: T - The value of the removed element.
 */
template<typename T>
T Queue<T>::dequeue() {
    // Check if the queue is empty
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    Node<T>* headNode = list.getHead();
    T value = headNode->data;
    list.remove(value);
    size--;
    return value;
}

/*
 * Name: Queue.getFirst
 * Description: Returns the first element of the queue without removing it.
 * Parameters: None
 * Returns: T& - Reference to the first element.
 */
template<typename T>
T& Queue<T>::getFirst() const {
    // Check if the queue is empty
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return list.getHead()->data;
}

/*
 * Name: Queue.getLast
 * Description: Returns the last element of the queue without removing it.
 * Parameters: None
 * Returns: T& - Reference to the last element.
 */
template<typename T>
T& Queue<T>::getLast() const {
    // Check if the queue is empty
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    Node<T>* current = list.getHead();
    while (current->next) {
        current = current->next;
    }
    // Return the data of the last node
    return current->data;
}

/*
 * Name: Queue.getSize
 * Description: Returns the number of elements in the queue.
 * Parameters: None
 * Returns: int - The size of the queue.
 */
template<typename T>
int Queue<T>::getSize() const {
    return size; // Return the size of the queue
}

/*
 * Name: Queue.isEmpty
 * Description: Checks if the queue is empty.
 * Parameters: None
 * Returns: bool - True if the queue is empty, false otherwise.
 */
template<typename T>
bool Queue<T>::isEmpty() const {
    return size == 0; // Return true if size is zero, false otherwise
}


#endif //QUEUE_H
