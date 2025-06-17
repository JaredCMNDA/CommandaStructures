//
// Created by Levi on 2025-06-11.
//

#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"
/* Notes:
 * Functions in the stack class:
 * push - Adds a new element to the top of the stack.
 * pop - Removes and returns the top element of the stack.
 * top - Returns the top element of the stack without removing it.
 * getSize - Returns the number of elements in the stack.
 * isEmpty - Checks if the stack is empty.
 */

namespace CommandaStructures
{

template <typename T> class Stack
{
  public:
    Stack();                   // Constructor to initialize an empty stack
    ~Stack();                  // Destructor to clean up the stack
    void push(const T& value); // Adds a new element to the top of the stack
    T pop();                   // Removes and returns the top element of the stack
    T& top() const;            // Returns the top element of the stack without removing it
    [[nodiscard]] int getSize() const
    {
        return list.getSize();
    };                                  // Returns the number of elements in the stack
    [[nodiscard]] bool isEmpty() const; // Checks if the stack is empty
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

    auto crbegin() const
    {
        return list.rbegin();
    }
    auto crend() const
    {
        return list.rend();
    }

  private:
    LinkedList<T> list; // Linked list to store the elements of the stack
};

/*
 * Name: Stack constructor
 * Description: Initializes an empty stack.
 * Parameters: None
 * Returns: void - No return value.
 */
template <typename T> Stack<T>::Stack()
{
    list = LinkedList<T>(); // Initialize the linked list to manage stack elements
};

/*
 * Name: Stack destructor
 * Description: Cleans up the stack by deleting the linked list to prevent memory leaks.
 * Parameters: None
 * Returns: void - No return value.
 */
template <typename T>
Stack<T>::~Stack() = default; // Use the default destructor (no need for custom cleanup since
                              // LinkedList handles its own memory)

/*
 * Name: Stack.push
 * Description: Adds a new element to the top of the stack.
 * Parameters: value - The value to be added to the stack.
 * Returns: void - No return value.
 */
template <typename T> void Stack<T>::push(const T& value)
{
    list.insert(value, LinkedList<T>::HEAD); // Insert at the head of the linked list
}

/*
 * Name: Stack.pop
 * Description: Removes and returns the top element of the stack.
 * Parameters: None
 * Returns: T - The value of the removed top element.
 */
template <typename T> T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack is empty");
    }
    T data = list.getHead()->getData(); // Get the data from the head node
    list.removeNode(list.getHead());
    return data; // Return the removed value
}

/*
 * Name: Stack.top
 * Description: Returns the top element of the stack without removing it.
 * Parameters: None
 * Returns: T& - Reference to the top element.
 */
template <typename T> T& Stack<T>::top() const
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack is empty");
    }
    return list.getHead()->getData(); // Return the data of the head node
}

/*
 * Name: Stack.isEmpty
 * Description: Checks if the stack is empty.
 * Parameters: None
 * Returns: bool - True if empty, false otherwise
 */
template <typename T> bool Stack<T>::isEmpty() const
{
    return list.getSize() == 0; // Return true if size is zero, false otherwise
}

} // namespace CommandaStructures

#endif // STACK_H
