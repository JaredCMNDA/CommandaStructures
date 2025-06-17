//
// Created by Levi on 2025-06-11.
//

#ifndef DEQUE_H
#define DEQUE_H

#include "doublelinkedlist.h"
/* Notes:
 * Functions in the deque class:
 * push_front - Adds a new element to the front of the deque.
 * push_back - Adds a new element to the back of the deque.
 * pop_front - Removes and returns the front element of the deque.
 * pop_back - Removes and returns the back element of the deque.
 * back - Returns the last element of the deque without removing it.
 * front - Returns the first element of the deque without removing it.
 * getSize - Returns the number of elements in the deque.
 * isEmpty - Checks if the deque is empty.
 */

namespace CommandaStructures
{

template <typename T> class Deque
{
  public:
    Deque();
    ~Deque();
    void push_front(const T& value); // Adds a new element to the front of the deque
    void push_back(const T& value);  // Adds a new element to the back of the deque
    T pop_front();                   // Removes and returns the front element of the deque
    T pop_back();                    // Removes and returns the back element of the deque
    T& front() const;                // Returns the first element without removing it
    T& back() const;                 // Returns the last element without removing it
    [[nodiscard]] int getSize() const
    {
        return list.getSize();
    };                                  // Returns the number of elements in the deque
    [[nodiscard]] bool isEmpty() const; // Checks if the deque is empty
    // Forward iterator support
    auto begin()
    {
        return list.begin();
    }
    auto end()
    {
        return list.end();
    }
    auto cbegin() const
    {
        return list.cbegin();
    }
    auto cend() const
    {
        return list.cend();
    }

    // Reverse iterator support
    auto rbegin()
    {
        return list.rbegin();
    }
    auto rend()
    {
        return list.rend();
    }

  private:
    DoubleLinkedList<T> list; // Double linked list to store the elements of the deque
};

/*
 * Name: Deque constructor
 * Description: Initializes an empty deque.
 * Parameters: None
 * Returns: void - No return value.
 */
template <typename T> Deque<T>::Deque() : list()
{
    // The size is implicitly managed by the DoubleLinkedList class
}

/*
 * Name: Deque destructor
 * Description: Cleans up the deque by deleting the double linked list to prevent memory leaks.
 * Parameters: None
 * Returns: void - No return value.
 */
template <typename T>
Deque<T>::~Deque() = default; // Use the default destructor (no need for custom cleanup since
                              // DoubleLinkedList handles its own memory)

/*
 * Name: Deque.push_front
 * Description: Adds a new element to the front of the deque.
 * Parameters: value - The value to be added to the front of the deque.
 * Returns: void - No return value.
 */
template <typename T> void Deque<T>::push_front(const T& value)
{
    list.insert(value, DoubleLinkedList<T>::HEAD); // Insert at the head of the double linked list
}

/*
 * Name: Deque.push_back
 * Description: Adds a new element to the back of the deque.
 * Parameters: value - The value to be added to the back of the deque.
 * Returns: void - No return value.
 */
template <typename T> void Deque<T>::push_back(const T& value)
{
    list.insert(value, DoubleLinkedList<T>::TAIL); // Insert at the tail of the double linked list
}

/*
 * Name: Deque.pop_front
 * Description: Removes and returns the front element of the deque.
 * Parameters: None
 * Returns: T - The value of the removed front element.
 */
template <typename T> T Deque<T>::pop_front()
{
    if (isEmpty())
    {
        throw std::out_of_range("Deque is empty");
    }
    T value = list.getHead()->getData(); // Get the data from the head node
    list.remove(value);                  // Remove the head node
    return value;                        // Return the removed value
}

/*
 * Name: Deque.pop_back
 * Description: Removes and returns the back element of the deque.
 * Parameters: None
 * Returns: T - The value of the removed back element.
 */
template <typename T> T Deque<T>::pop_back()
{
    if (isEmpty())
    {
        throw std::out_of_range("Deque is empty");
    }
    T value = list.getTail()->getData(); // Get the data from the tail node
    list.remove(value);                  // Remove the tail node
    return value;                        // Return the removed value
}

/*
 * Name: Deque.front
 * Description: Returns the first element of the deque without removing it.
 * Parameters: None
 * Returns: T& - Reference to the first element.
 */
template <typename T> T& Deque<T>::front() const
{
    if (isEmpty())
    {
        throw std::out_of_range("Deque is empty");
    }
    return list.getHead()->getData(); // Return the data of the head node
}

/*
 * Name: Deque.back
 * Description: Returns the last element of the deque without removing it.
 * Parameters: None
 * Returns: T& - Reference to the last element.
 */
template <typename T> T& Deque<T>::back() const
{
    if (isEmpty())
    {
        throw std::out_of_range("Deque is empty");
    }
    return list.getTail()->getData(); // Return the data of the tail node
}

/*
 * Name: Deque.isEmpty
 * Description: Checks if the deque is empty.
 * Parameters: None
 * Returns: bool - True if the deque is empty, false otherwise.
 */
template <typename T> bool Deque<T>::isEmpty() const
{
    return list.getSize() == 0; // Return true if size is zero, false otherwise
}

} // namespace CommandaStructures

#endif // DEQUE_H
