//
// Created by Levi on 2025-06-11.
//

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
#include "node.h" // Include the Node class definition

namespace CommandaStructures {

    /* Double Linked List Class */
    template<typename T>
    class DoubleLinkedList {
    public:

        DoubleLinkedList();
        ~DoubleLinkedList();
        void insert(const T& value, int spot = TAIL); // Append a new node with the given value to the end of the list (spot is optional)
        void remove(const T& value);                  // Remove the first node with the given value from the list
        template<typename Func>                       // Function to display the contents of the linked list using a custom function
        void display(Func func) const;                // Display the contents using a custom function
        Node<T>* getHead() const { return head; }     // Public getter for head
        Node<T>* getTail() const { return tail; }     // Public getter for tail
        [[nodiscard]] size_t getSize() const {return size;}         // Public getter for size

        Node<T>* findNode(const T& value) const;      // Find a node with the given value and return a pointer to it
        enum Spot {
            HEAD = 0, // Enum to define positions for appending nodes
            TAIL = -1 // TAIL is used to append at the end of the list (default behavior)
        };
    private:
        size_t size;   // Size of the double linked list
        Node<T>* head; // Pointer to the first node in the list
        Node<T>* tail; // Pointer to the last node in the list
        // Enum to define positions for appending nodes

        static void setNext(Node<T>* node, Node<T>* nextNode) {
            if (node) {
                node->next = nextNode; // Set the next pointer of the current node
            }
        }
        static void setPrev(Node<T>* node, Node<T>* prevNode) {
            if (node) {
                node->prev = prevNode; // Set the previous pointer of the current node
            }
        }
    };

    /*
     * Name: DoubleLinkedList constructor
     * Description: Initializes an empty double linked list with the head and tail pointer set to nullptr.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    DoubleLinkedList<T>::DoubleLinkedList() : size(0), head(nullptr), tail(nullptr) {}

    /*
 * Name: DoubleLinkedList destructor
 * Description: Cleans up the linked list by deleting all nodes to prevent memory leaks.
 * Parameters: None
 * Returns: void - No return value.
 */
    template<typename T>
    DoubleLinkedList<T>::~DoubleLinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next; // Store the next node
            delete current; // Delete the current node
            current = nextNode; // Move to the next node
        }
        size = 0; // Reset size to zero
        head = nullptr; // Set head to nullptr after deletion
        tail = nullptr; // Set tail to nullptr after deletion
    }

    /*
     * Name: DoubleLinkedList.insert
     * Description: Inserts a new node with the given value at the specified position in the list.
     * Parameters: value - The value to be inserted into the list.
     *             spot - The position where the new node should be inserted (default is TAIL, which appends to the end).
     * Returns: void - No return value.
     */
    template<typename T>
    void DoubleLinkedList<T>::insert(const T &value, int spot) {
        Node<T>* newNode = new Node<T>(value);
        // If the spot is 0, insert at the head
        if (spot == HEAD) {
            setNext(newNode, head); // Set the next pointer of the new node to the current head
            setPrev(head, newNode); // Set the previous pointer of the current head to the new node
            head = newNode; // Update the head to the new node
            if (!tail) { // If the list was empty, set the tail to the new node
                tail = newNode;
            }
            size++;
            return;
        }
        // If the spot is TAIL or negative, insert at the end
        if (spot == TAIL || spot < 0) {
            if (!tail) { // If the list is empty, set both head and tail to the new node
                head = newNode;
                tail = newNode;
            } else {
                setNext(tail, newNode); // Set the next pointer of the current tail to the new node
                setPrev(newNode, tail); // Set the previous pointer of the new node to the current tail
                tail = newNode; // Update the tail to the new node
            }
            size++;
            return;
        }
        // If the spot is positive, insert at the specified position
        Node<T>* current = getHead();
        for (int i = 0; i < spot - 1 && current; ++i) {
            current = current->next; // Traverse to the specified position
        }
        if (!current) { // If the current node is null, insert at the end
            setNext(tail, newNode); // Set the next pointer of the current tail to the new node
            setPrev(newNode, tail); // Set the previous pointer of the new node to the current tail
            tail = newNode; // Update the tail to the new node
        } else {
            setNext(newNode, current->next); // Set the next pointer of the new node to the next node of current
            setPrev(newNode, current); // Set the previous pointer of the new node to current
            if (current->next) {
                setPrev(current->next, newNode); // Set the previous pointer of the next node to the new node
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
    template<typename T>
    void DoubleLinkedList<T>::remove(const T &value) {
        if (!head) return; // If the list is empty, do nothing
        Node<T>* current = getHead();
        // Traverse the list to find the node with the given value
        while (current) {
            if (current->getData() == value) { // If the current node's data matches the value
                if (current->prev) { // If it's not the head node
                    setNext(current->prev, current->next); // Set the next pointer of the previous node
                } else { // If it is the head node
                    head = current->next; // Update head to the next node
                }
                if (current->next) { // If it's not the tail node
                    setPrev(current->next, current->prev); // Set the previous pointer of the next node
                } else { // If it is the tail node
                    tail = current->prev; // Update tail to the previous node
                }
                delete current; // Delete the current node
                size--; // Decrement the size of the double linked list
                return; // Exit after removing the first occurrence
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
    template<typename T>
    template<typename Func>
    void DoubleLinkedList<T>::display(Func func) const {
        Node<T>* current = getHead(); // Start from the head of the list
        while (current) { // Traverse through each node
            func(current->getData()); // Call the provided function with the data of the current node
            current = current->next; // Move to the next node
        }
    }

    /*
     * Name: DoubleLinkedList.findNode
     * Description: Finds a node with the given value and returns a pointer to it.
     * Parameters: value - The value to search for in the list.
     * Returns: Node<T>* - A pointer to the node containing the value, or nullptr if not found.
     */

    template<typename T>
    Node<T>* DoubleLinkedList<T>::findNode(const T &value) const {
        Node<T>* current = getHead(); // Start from the head of the list
        // Traverse the list to find the node with the given value
        while (current) {
            if (current->getData() == value) { // If the current node's data matches the value
                return current; // Return the pointer to the current node
            }
            current = current->next; // Move to the next node
        }
        return nullptr; // Return nullptr if not found
    }

}

#endif //DOUBLELINKEDLIST_H
