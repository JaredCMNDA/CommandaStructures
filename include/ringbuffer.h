//
// Created by Levi on 2025-06-11.
//

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <linkedlist.h>
/* Notes:
 * Functions in the ring buffer class:
 * push - Adds a new element to the buffer, overwriting the oldest element if the buffer is full.
 * pop - Removes and returns the oldest element from the buffer (if not overwrite only mode).
 * front - Returns the oldest element without removing it.
 * back - Returns the most recently added element without removing it.
 * getSize - Returns the number of elements currently in the buffer.
 * isFull - Checks if the buffer is full.
 * isEmpty - Checks if the buffer is empty.
 * clear - Clears the buffer, removing all elements.
 * isOverwriteOnly - Checks if the buffer is in overwrite-only mode.
 * capacity - Returns the maximum number of elements the buffer can hold.
 * resize - Resizes the buffer to a new capacity, preserving existing elements if possible.
 *
 * Extra:
 * Overwrite only mode: new data is always accepted (push() never fails), the tail moves forward as normal and when full, head also moves forward to discard the oldest item silently
 */

namespace CommandaStructures {

    template<typename T>
    class RingBuffer {
    public:
        RingBuffer(size_t capacity, bool overwrite = false);
        ~RingBuffer();
        void push(const T& value);       // Adds a new element to the buffer, overwriting the oldest if full
        T pop();                         // Removes and returns the oldest element from the buffer
        T& front() const;                // Returns the oldest element without removing it
        T& peek() const { return front(); }  // Alias for front()
        T& back() const;                 // Returns the most recently added element without removing it
        [[nodiscard]] int getSize() const {return list.getSize();};             // Returns the number of elements currently in the buffer
        [[nodiscard]] bool isFull() const;             // Checks if the buffer is full
        [[nodiscard]] bool isEmpty() const;            // Checks if the buffer is empty
        void clear();                    // Clears the buffer, removing all elements
        [[nodiscard]] bool isOverwriteOnly() const {return overwriteOnly;};    // Checks if the buffer is in overwrite-only mode
        [[nodiscard]] size_t capacity() const {return maxCapacity;};         // Returns the maximum number of elements the buffer can hold
        void resize(size_t newCapacity); // Resizes the buffer to a new capacity, preserving existing elements if possible
        // Forward iterator support
        auto begin()       { return list.begin(); }
        auto end()         { return list.end(); }
        auto cbegin() const { return list.cbegin(); }
        auto cend() const   { return list.cend(); }

        // Reverse iterator support
        auto rbegin()      { return list.rbegin(); }
        auto rend()        { return list.rend(); }
    private:
        LinkedList<T> list;              // Linked list to store the elements of the buffer
        size_t maxCapacity;              // Maximum number of elements the buffer can hold
        bool overwriteOnly;              // Flag to indicate if the buffer is in overwrite-only mode default is false
    };

    /*
     * Name: RingBuffer constructor
     * Description: Initializes an empty ring buffer with a default capacity.
     * Parameters: capacity - The maximum number of elements the buffer can hold.
     *             overwrite - A flag indicating if the buffer should overwrite the oldest element when full (default is false).
     * Returns: void - No return value.
     */
    template<typename T>
    RingBuffer<T>::RingBuffer(size_t capacity, bool overwrite)
        : maxCapacity(capacity), overwriteOnly(overwrite) {
        if (capacity == 0) {
            throw std::invalid_argument("RingBuffer capacity must be greater than zero");
        }
        list = LinkedList<T>();
    }

    /*
     * Name: RingBuffer destructor
     * Description: Cleans up the ring buffer by deleting the linked list to prevent memory leaks.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    RingBuffer<T>::~RingBuffer() = default; // Use the default destructor (no need for custom cleanup since LinkedList handles its own memory)

    /*
     * Name: RingBuffer.push
     * Description: Adds a new element to the buffer, overwriting the oldest element if the buffer is full.
     * Parameters: value - The value to be added to the buffer.
     * Returns: void - No return value.
     */
    template<typename T>
    void RingBuffer<T>::push(const T& value) {
        if (isFull()) {
            if (overwriteOnly) {
                // If in overwrite-only mode, remove the oldest element
                list.removeNode(list.getHead());
            } else {
                // If not in overwrite-only mode, do not add the new element
                throw std::runtime_error("RingBuffer is full and not in overwrite-only mode");
            }
        }
        list.insert(value); // Insert the new value at the end of the linked list
    }

    /*
     * Name: RingBuffer.pop
     * Description: Removes and returns the oldest element from the buffer.
     * Parameters: None
     * Returns: T - The value of the removed element.
     */
    template<typename T>
    T RingBuffer<T>::pop() {
        if (isEmpty()) {
            throw std::out_of_range("RingBuffer is empty");
        }
        T value = list.getHead()->getData(); // Get the data from the head node
        list.removeNode(list.getHead()); // Remove the head node
        return value; // Return the removed value
    }

    /*
     * Name: RingBuffer.front
     * Description: Returns the oldest element without removing it.
     * Parameters: None
     * Returns: T& - Reference to the oldest element.
     */
    template<typename T>
    T& RingBuffer<T>::front() const {
        if (isEmpty() || list.getHead() == nullptr) {
            throw std::out_of_range("RingBuffer is empty or head is null");
        }
        return list.getHead()->getData(); // Return the data from the head node
    }

    /*
     * Name: RingBuffer.back
     * Description: Returns the most recently added element without removing it.
     * Parameters: None
     * Returns: T& - Reference to the most recently added element.
     */
    template<typename T>
    T& RingBuffer<T>::back() const {
        if (isEmpty() || list.getTail() == nullptr) {
            throw std::out_of_range("RingBuffer is empty or tail is null");
        }
        return list.getTail()->getData(); // Return the data from the tail node
    }

    /*
     * Name: RingBuffer.isFull
     * Description: Checks if the buffer is full.
     * Parameters: None
     * Returns: bool - True if the buffer is full, false otherwise.
     */
    template<typename T>
    bool RingBuffer<T>::isFull() const {
        return list.getSize() >= maxCapacity; // Check if the size of the linked list is equal to or greater than the maximum capacity
    }

    /*
     * Name: RingBuffer.isEmpty
     * Description: Checks if the buffer is empty.
     * Parameters: None
     * Returns: bool - True if the buffer is empty, false otherwise.
     */
    template<typename T>
    bool RingBuffer<T>::isEmpty() const {
        return list.getSize() == 0; // Check if the size of the linked list is zero
    }

    /*
     * Name: RingBuffer.clear
     * Description: Clears the buffer, removing all elements.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    void RingBuffer<T>::clear() {
        list.clear();
    }

    /*
     * Name: RingBuffer.resize
     * Description: Resizes the buffer to a new capacity, preserving existing elements if possible. Removes oldest elements if the new capacity is smaller than the current size.
     * Parameters: newCapacity - The new maximum number of elements the buffer can hold.
     * Returns: void - No return value.
     */
    template<typename T>
    void RingBuffer<T>::resize(size_t newCapacity) {
        if (newCapacity < list.getSize()) {
            // If the new capacity is less than the current size, remove the oldest elements
            while (list.getSize() > newCapacity) {
                list.removeNode(list.getHead());
            }
        }
        maxCapacity = newCapacity; // Update the maximum capacity
    }


}



#endif //RINGBUFFER_H
