//
// Created by Levi on 2025-06-11.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "nodes.h" // Include the Node class definition
#include <iostream>
using namespace CommandaStructures::Double;

namespace CommandaStructures
{

/* Double Linked List Class */
template <typename T> class DoubleLinkedList
{
  public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void insert(const T& value, int spot = TAIL); // Append a new DoubleNode with the given value to
                                                  // the end of the list (spot is optional)
    void remove(const T& value); // Remove the first DoubleNode with the given value from the list
    template <typename Func> // Function to display the contents of the linked list using a custom
                             // function
                             void display(
                                 Func func) const; // Display the contents using a custom function
    DoubleNode<T>* getHead() const
    {
        return head;
    } // Public getter for head
    DoubleNode<T>* getTail() const
    {
        return tail;
    } // Public getter for tail
    [[nodiscard]] size_t getSize() const
    {
        return size;
    }                                     // Public getter for size
    void removeNode(DoubleNode<T>* node); // Remove a specific DoubleNode from the list
    void clear();                         // Clear the double linked list by deleting all nodes
    bool contains(const T& value) const
    {
        return findNode(value) != nullptr;
    } // Check if the list contains a node with the given value
    DoubleNode<T>*
    findNode(const T& value) const; // Find a node with the given value and return a pointer to it
    void reverse();                 // Reverse the double linked list in place
    void
    insertAfter(DoubleNode<T>* node,
                const T& value); // Insert a new node with the given value after the specified node
    void insertBefore(
        DoubleNode<T>* node,
        const T& value); // Insert a new node with the given value before the specified node
    enum Spot
    {
        HEAD = 0, // Enum to define positions for appending nodes
        TAIL = -1 // TAIL is used to append at the end of the list (default behavior)
    };

    class Iterator
    {
      public:
        explicit Iterator(DoubleNode<T>* ptr) : current(ptr) {}
        T& operator*() const
        {
            return current->data;
        }
        Iterator& operator++()
        {
            current = current->next;
            return *this;
        }
        bool operator!=(const Iterator& other) const
        {
            return current != other.current;
        }
        bool operator==(const Iterator& other) const
        {
            return current == other.current;
        }

        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

      private:
        DoubleNode<T>* current;
    };

    Iterator begin() const
    {
        return Iterator(head);
    }
    Iterator end() const
    {
        return Iterator(nullptr);
    }

    class ReverseIterator
    {
      public:
        explicit ReverseIterator(DoubleNode<T>* ptr) : current(ptr) {}
        T& operator*() const
        {
            return current->data;
        }
        ReverseIterator& operator++()
        {
            current = current->prev;
            return *this;
        }
        bool operator!=(const ReverseIterator& other) const
        {
            return current != other.current;
        }
        bool operator==(const ReverseIterator& other) const
        {
            return current == other.current;
        }

      private:
        DoubleNode<T>* current;
    };

    ReverseIterator rbegin() const
    {
        return ReverseIterator(tail);
    }
    ReverseIterator rend() const
    {
        return ReverseIterator(nullptr);
    }

    class ConstIterator
    {
      public:
        explicit ConstIterator(const DoubleNode<T>* ptr) : current(ptr) {}
        const T& operator*() const
        {
            return current->data;
        }
        ConstIterator& operator++()
        {
            current = current->next;
            return *this;
        }
        bool operator!=(const ConstIterator& other) const
        {
            return current != other.current;
        }
        bool operator==(const ConstIterator& other) const
        {
            return current == other.current;
        }

        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

      private:
        const DoubleNode<T>* current;
    };
    ConstIterator cbegin() const
    {
        return ConstIterator(head);
    }
    ConstIterator cend() const
    {
        return ConstIterator(nullptr);
    }

  private:
    size_t size;         // Size of the double linked list
    DoubleNode<T>* head; // Pointer to the first node in the list
    DoubleNode<T>* tail; // Pointer to the last node in the list
    // Enum to define positions for appending nodes

    static void setNext(DoubleNode<T>* node, DoubleNode<T>* nextNode)
    {
        if (node)
        {
            node->next = nextNode; // Set the next pointer of the current node
        }
    }
    static void setPrev(DoubleNode<T>* node, DoubleNode<T>* prevNode)
    {
        if (node)
        {
            node->prev = prevNode; // Set the previous pointer of the current node
        }
    }
};

/*
 * Name: DoubleLinkedList constructor
 * Description: Initializes an empty double linked list with the head and tail pointer set to
 * nullptr. Parameters: None Returns: void - No return value.
 */
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : size(0), head(nullptr), tail(nullptr)
{
}

/*
 * Name: DoubleLinkedList destructor
 * Description: Cleans up the linked list by deleting all nodes to prevent memory leaks.
 * Parameters: None
 * Returns: void - No return value.
 */
template <typename T> DoubleLinkedList<T>::~DoubleLinkedList()
{
    DoubleNode<T>* current = head;
    while (current)
    {
        DoubleNode<T>* nextNode = current->next; // Store the next node
        delete current;                          // Delete the current node
        current = nextNode;                      // Move to the next node
    }
    size = 0;       // Reset size to zero
    head = nullptr; // Set head to nullptr after deletion
    tail = nullptr; // Set tail to nullptr after deletion
}

/*
 * Name: DoubleLinkedList.insert
 * Description: Inserts a new node with the given value at the specified position in the list.
 * Parameters: value - The value to be inserted into the list.
 *             spot - The position where the new node should be inserted (default is TAIL, which
 * appends to the end). Returns: void - No return value.
 */
template <typename T> void DoubleLinkedList<T>::insert(const T& value, int spot)
{
    DoubleNode<T>* newNode = new DoubleNode<T>(value);
    // If the spot is 0, insert at the head
    if (spot == HEAD)
    {
        setNext(newNode, head); // Set the next pointer of the new node to the current head
        setPrev(head, newNode); // Set the previous pointer of the current head to the new node
        head = newNode;         // Update the head to the new node
        if (!tail)
        { // If the list was empty, set the tail to the new node
            tail = newNode;
        }
        size++;
        return;
    }
    // If the spot is TAIL or negative, insert at the end
    if (spot == TAIL || spot < 0)
    {
        if (!tail)
        { // If the list is empty, set both head and tail to the new node
            head = newNode;
            tail = newNode;
        }
        else
        {
            setNext(tail, newNode); // Set the next pointer of the current tail to the new node
            setPrev(newNode, tail); // Set the previous pointer of the new node to the current tail
            tail = newNode;         // Update the tail to the new node
        }
        size++;
        return;
    }
    // If the spot is positive, insert at the specified position
    DoubleNode<T>* current = getHead();
    for (int i = 0; i < spot - 1 && current; ++i)
    {
        current = current->next; // Traverse to the specified position
    }
    if (!current)
    {                           // If the current node is null, insert at the end
        setNext(tail, newNode); // Set the next pointer of the current tail to the new node
        setPrev(newNode, tail); // Set the previous pointer of the new node to the current tail
        tail = newNode;         // Update the tail to the new node
    }
    else
    {
        setNext(newNode,
                current->next); // Set the next pointer of the new node to the next node of current
        setPrev(newNode, current); // Set the previous pointer of the new node to current
        if (current->next)
        {
            setPrev(current->next,
                    newNode); // Set the previous pointer of the next node to the new node
        }
        setNext(current, newNode); // Set the next pointer of current to the new node
    }
    size++; // Increment the size of the double linked list
}

/*
 * Name: DoubleLinkedList.remove
 * Description: Removes the first node with the given value from the list.
 * Parameters: value - The value of the node to be removed.
 * Returns: void - No return value.
 */
template <typename T> void DoubleLinkedList<T>::remove(const T& value)
{
    if (!head)
        return; // If the list is empty, do nothing
    DoubleNode<T>* current = getHead();
    // Traverse the list to find the node with the given value
    while (current)
    {
        if (current->getData() == value)
        { // If the current node's data matches the value
            if (current->prev)
            {                                          // If it's not the head node
                setNext(current->prev, current->next); // Set the next pointer of the previous node
            }
            else
            {                         // If it is the head node
                head = current->next; // Update head to the next node
            }
            if (current->next)
            {                                          // If it's not the tail node
                setPrev(current->next, current->prev); // Set the previous pointer of the next node
            }
            else
            {                         // If it is the tail node
                tail = current->prev; // Update tail to the previous node
            }
            delete current; // Delete the current node
            size--;         // Decrement the size of the double linked list
            return;         // Exit after removing the first occurrence
        }
        current = current->next; // Move to the next node
    }
}

/*
 * Name: DoubleLinkedList.display
 * Description: Displays the contents of the double linked list using a custom function.
 * Parameters: func - A function that takes a const reference to T and returns void.
 * Returns: void - No return value.
 */
template <typename T> template <typename Func> void DoubleLinkedList<T>::display(Func func) const
{
    DoubleNode<T>* current = getHead(); // Start from the head of the list
    while (current)
    {                             // Traverse through each node
        func(current->getData()); // Call the provided function with the data of the current node
        current = current->next;  // Move to the next node
    }
}

/*
 * Name: DoubleLinkedList.removeNode
 * Description: Removes a specific node from the double linked list.
 * Parameters: node - Pointer to the node to be removed.
 * Returns: void - No return value.
 */
template <typename T> void DoubleLinkedList<T>::removeNode(DoubleNode<T>* node)
{
    if (!node)
        return;
    if (node->prev)
        node->prev->next =
            node->next; // If the node is not the head, set the next pointer of the previous node
    else
        head = node->next; // If it is the head, update head to the next node

    if (node->next)
        node->next->prev =
            node->prev; // If the node is not the tail, set the previous pointer of the next node
    else
        tail = node->prev; // If it is the tail, update tail to the previous node

    delete node;
    size--;
}

/* Name: DoubleLinkedList.clear
 * Description: Clears the double linked list by deleting all nodes.
 * Parameters: None
 * Returns: void - No return value.
 */
template <typename T> void DoubleLinkedList<T>::clear()
{
    DoubleNode<T>* current = head; // Start from the head of the list
    while (current)
    {
        DoubleNode<T>* nextNode = current->next; // Store the next node
        delete current;                          // Delete the current node
        current = nextNode;                      // Move to the next node
    }
    head = nullptr; // Set head to nullptr after deletion
    tail = nullptr; // Set tail to nullptr after deletion
    size = 0;       // Reset size to zero
}

/*
 * Name: DoubleLinkedList.findNode
 * Description: Finds a node with the given value and returns a pointer to it.
 * Parameters: value - The value to search for in the list.
 * Returns: DoubleNode<T>* - A pointer to the node containing the value, or nullptr if not found.
 */
template <typename T> DoubleNode<T>* DoubleLinkedList<T>::findNode(const T& value) const
{
    DoubleNode<T>* current = getHead(); // Start from the head of the list
    // Traverse the list to find the node with the given value
    while (current)
    {
        if (current->getData() == value)
        {                   // If the current node's data matches the value
            return current; // Return the pointer to the current node
        }
        current = current->next; // Move to the next node
    }
    return nullptr; // Return nullptr if not found
}

/*
 * Name: DoubleLinkedList.reverse
 * Description: Reverses the double linked list in place.
 * Parameters: None
 * Returns: void - No return value.
 */
template <typename T> void DoubleLinkedList<T>::reverse()
{
    DoubleNode<T>* current = head; // Start from the head of the list
    DoubleNode<T>* temp = nullptr; // Temporary pointer to hold the next node
    tail = head;                   // Set tail to the current head
    while (current)
    {
        temp = current->prev;            // Store the previous node
        setPrev(current, current->next); // Reverse the previous pointer
        setNext(current, temp);          // Reverse the next pointer
        current = current->prev;         // Move to the next node (which is now previous)
    }
    if (temp)
    { // If temp is not null, update head to the last processed node
        head = temp->prev;
    }
}

/*
 * Name: DoubleLinkedList.insertAfter
 * Description: Inserts a new node with the given value after the specified node.
 * Parameters: node - Pointer to the node after which the new node should be inserted.
 *             value - The value to be inserted into the list.
 * Returns: void - No return value.
 */
template <typename T> void DoubleLinkedList<T>::insertAfter(DoubleNode<T>* node, const T& value)
{
    if (!node)
        return;                                        // If the node is null, do nothing
    DoubleNode<T>* newNode = new DoubleNode<T>(value); // Create a new node with the given value
    setNext(
        newNode,
        node->next); // Set the next pointer of the new node to the next node of the specified node
    setPrev(newNode, node); // Set the previous pointer of the new node to the specified node
    if (node->next)
    { // If there is a next node, update its previous pointer
        setPrev(node->next, newNode);
    }
    else
    { // If there is no next node, update tail to the new node
        tail = newNode;
    }
    setNext(node, newNode); // Set the next pointer of the specified node to the new node
    size++;                 // Increment the size of the double linked list
}

/*
 * Name: DoubleLinkedList.insertBefore
 * Description: Inserts a new node with the given value before the specified node.
 * Parameters: node - Pointer to the node before which the new node should be inserted.
 *             value - The value to be inserted into the list.
 * Returns: void - No return value.
 */
template <typename T> void DoubleLinkedList<T>::insertBefore(DoubleNode<T>* node, const T& value)
{
    if (!node)
        return;                                        // If the node is null, do nothing
    DoubleNode<T>* newNode = new DoubleNode<T>(value); // Create a new node with the given value
    setPrev(newNode, node->prev); // Set the previous pointer of the new node to the previous node
                                  // of the specified node
    setNext(newNode, node);       // Set the next pointer of the new node to the specified node
    if (node->prev)
    { // If there is a previous node, update its next pointer
        setNext(node->prev, newNode);
    }
    else
    { // If there is no previous node, update head to the new node
        head = newNode;
    }
    setPrev(node, newNode); // Set the previous pointer of the specified node to the new node
    size++;                 // Increment the size of the double linked list
}

} // namespace CommandaStructures

#endif // DOUBLELINKEDLIST_H
