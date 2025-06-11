//
// Created by Levi on 2025-06-10.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "node.h" // Include the Node class definition


namespace CommandaStructures {
    /* Linked List Class */
    template<typename T> // Template class for LinkedList (allows for different data types)
    class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void insert(const T& value, int spot = TAIL); // insert a new node with the given value to the end of the list (spot is optional)
        void remove(const T& value);                  // Remove the first node with the given value from the list
        int size();                                   // Return the number of nodes in the linked list
        template<typename Func>                       // Function to display the contents of the linked list using a custom function
        void display(Func func) const;                // Display the contents using a custom function
        Node<T>* getHead() const;                     // Public getter for head
        Node<T>* findNode(const T& value) const;      // Find a node with the given value and return a pointer to it
        enum Spot {
            HEAD = 0, // Enum to define positions for appending nodes
            TAIL = -1 // TAIL is used to append at the end of the list (default behavior)
        };
    private:
        Node<T>* head; // Pointer to the first node in the list
        // Enum to define positions for appending nodes
    };

    /*
     * Name: LinkedList constructor
     * Description: Initializes an empty linked list with the head pointer set to nullptr.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    LinkedList<T>::LinkedList() : head(nullptr) {}

    /*
     * Name: LinkedList destructor
     * Description: Cleans up the linked list by deleting all nodes to prevent memory leaks.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    LinkedList<T>::~LinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next; // Store the next node
            delete current; // Delete the current node
            current = nextNode; // Move to the next node
        }
        head = nullptr; // Set head to nullptr after deletion
    }

    /*
     * Name: LinkedList.insert
     * Description: inserts a new node with the given value to the end of the linked list.
     * Parameters: value - The value to be added to the linked list.
     *             spot - The position where the new node should be inserted (default is TAIL, which appends to the end).
     * Returns: void - No return value.
     */
    template<typename T>
    void LinkedList<T>::insert(const T& value, int spot) {
        // Create a new node with the given value
        Node<T>* newNode = new Node<T>(value);
        // If the spot is 0, insert at the head
        if (spot == HEAD) {
            newNode->next = head;
            head = newNode;
            return;
        }
        // If the head is null, set the new node as the head
        if (!head) {
            head = newNode;
            return;
        }
        // Set the current node to the head and traverse to the desired spot
        Node<T>* current = head;
        // If spot is positive, traverse to the specified position
        if (spot > 0) {
            for (int i = 0; i < spot - 1 && current->next; i++) {
                current = current->next;
            }
        }
        // If spot is negative or greater than the size, insert to the end
        else {
            while (current->next) {
                current = current->next;
            }
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    /*
     * Name: LinkedList.remove
     * Description: Removes the first node with the given value from the linked list.
     * Parameters: value - The value of the node to be removed.
     * Returns: void - No return value.
     */
    template<typename T>
    void LinkedList<T>::remove(const T& value) {
        // If the list is empty, do nothing
        if (!head) return;
        // If the head node contains the value, remove it and update the head pointer
        if (head->getData() == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        // Otherwise, traverse the list to find the node with the given value
        Node<T>* current = head;
        // Traverse until we find the node with the value or reach the end of the list
        while (current->next && !(current->next->getData() == value)) {
            current = current->next;
        }
        // If we found the node, remove it by updating the next pointer of the previous node
        if (current->next) {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        // If we didn't find the node, do nothing
    }

    /*
     * Name: LinkedList.size
     * Description: Returns the number of nodes in the linked list.
     * Parameters: None
     * Returns: int - The size of the linked list.
     */
    template<typename T>
    int LinkedList<T>::size() {
        // Initialize a counter to zero
        int count = 0;
        // Get the head of the list and traverse through each node, incrementing the counter
        Node<T>* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        // Return the total count of nodes
        return count;
    }

    /*
     * Name: LinkedList.display
     * Description: Displays the contents of the linked list.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    template<typename Func>
    void LinkedList<T>::display(Func func) const {
        // Get the head of the list and traverse through each node, printing the data
        Node<T>* current = head;
        while (current) {
            // The custom function passed as a parameter is called for each node's data
            func(current->getData());
            current = current->next;
        }
        // Print a newline at the end for better readability
        std::cout << std::endl;
    }

    /*
     * Name: LinkedList.getHead
     * Description: Returns the head of the linked list.
     * Parameters: None
     * Returns: Node<T>* - Pointer to the head node.
     */
    template<typename T>
    Node<T>* LinkedList<T>::getHead() const {
        return head; // Return the head of the linked list
    }

    /*
     * Name: LinkedList.findNode
     * Description: Finds a node with the given value and returns a pointer to it.
     * Parameters: value - The value to search for in the linked list.
     * Returns: Node<T>* - Pointer to the node containing the value, or nullptr if not found.
     */
    template<typename T>
    Node<T>* LinkedList<T>::findNode(const T& value) const {
        const Node<T>* current = head; // Start from the head of the list
        // Traverse the list to find the node with the given value
        while (current) {
            if (current->getData() == value) { // If the current node's data matches the value
                return const_cast<Node<T>*>(current); // Return a non-const pointer to the found node
            }
            current = current->next; // Else move to the next node
        }
        std::cerr << "No such node" << std::endl;
        return nullptr; // If no node with the value is found, return nullptr
    }
}

#endif //LINKEDLIST_H


