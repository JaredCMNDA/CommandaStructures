//
// Created by Levi on 2025-06-10.
//

#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
/*Notes:
 * Functions in the queue class:
 * push - Adds a new element to the end of the queue.
 * pop - Removes and returns the front element of the queue.
 * back - Returns the last element of the queue without removing it.
 * front - Returns the first element of the queue without removing it.
 * emplace - Adds a new element to the end of the queue, allowing for in-place construction.
 * getSize - Returns the number of elements in the queue.
 * isEmpty - Checks if the queue is empty.
 */

namespace CommandaStructures {
    template<typename T>
    class Queue {
    public:
        Queue();
        ~Queue();
        void push(const T& value);                  // Adds a new element to the end of the queue
        T pop();                                   // Removes and returns the front element of the queue
        T& front() const;                           // Returns the first element without removing it
        T& back() const;                            // Returns the last element without removing it
        [[nodiscard]] int getSize() const {return list.getSize();};       // Returns the number of elements in the queue
        [[nodiscard]] bool isEmpty() const;                          // Checks if the queue is empty
    private:
        LinkedList<T> list;                            // Linked list to store the elements of the queue
    };

    /*
     * Name: Queue constructor
     * Description: Initializes an empty queue.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    Queue<T>::Queue() : list() {
        // The size is implicitly managed by the LinkedList class
    }

    /*
     * Name: Queue destructor
     * Description: Cleans up the queue by deleting the linked list to prevent memory leaks.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    Queue<T>::~Queue() = default; // Use the default destructor (no need for custom cleanup since LinkedList handles its own memory)

    /*
     * Name: Queue.enqueue
     * Description: Adds a new element to the end of the queue.
     * Parameters: value - The value to be added to the queue.
     * Returns: void - No return value.
     */
    template<typename T>
    void Queue<T>::push(const T& value) {
        // Use the insert method of the linked list to add the element
        list.insert(value);
    }

    /*
     * Name: Queue.dequeue
     * Description: Removes and returns the front element of the queue.
     * Parameters: None
     * Returns: T - The value of the removed element.
     */
    template<typename T>
    T Queue<T>::pop() {
        // Check if the queue is empty
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        Node<T>* headNode = list.getHead();
        T value = headNode->getData();
        list.remove(value);
        return value;
    }

    /*
     * Name: Queue.getFirst
     * Description: Returns the first element of the queue without removing it.
     * Parameters: None
     * Returns: T& - Reference to the first element.
     */
    template<typename T>
    T& Queue<T>::front() const {
        // Check if the queue is empty
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return list.getHead()->getData();
    }

    /*
     * Name: Queue.getLast
     * Description: Returns the last element of the queue without removing it.
     * Parameters: None
     * Returns: T& - Reference to the last element.
     */
    template<typename T>
    T& Queue<T>::back() const {
        // Check if the queue is empty
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        Node<T>* current = list.getHead();
        while (current->next) {
            current = current->next;
        }
        // Return the data of the last node
        return current->getData();
    }

    /*
     * Name: Queue.isEmpty
     * Description: Checks if the queue is empty.
     * Parameters: None
     * Returns: bool - True if the queue is empty, false otherwise.
     */
    template<typename T>
    bool Queue<T>::isEmpty() const {
        return getSize() == 0; // Return true if size is zero, false otherwise
    }
}

#endif //QUEUE_H
