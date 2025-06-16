//
// Created by Levi on 2025-06-10.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "nodes.h" // Include the Node class definition
using namespace CommandaStructures::Single;


namespace CommandaStructures {
    /* Linked List Class */
    template<typename T> // Template class for LinkedList (allows for different data types)
    class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void insert(const T& value, int spot = TAIL); // insert a new node with the given value to the end of the list (spot is optional)
        void remove(const T& value);                  // Remove the first node with the given value from the list
        template<typename Func>                       // Function to display the contents of the linked list using a custom function
        void display(Func func) const;                // Display the contents using a custom function
        SingleNode<T>* getHead() const {return head;}       // Public getter for head
        SingleNode<T>* getTail() const {return tail;}       // Public getter for tail
        [[nodiscard]] size_t getSize() const {return size;}         // Public getter for size
        SingleNode<T>* findNode(const T& value) const;      // Find a node with the given value and return a pointer to it
        void removeNode(SingleNode<T>* node);           // Remove a specific node from the list, return the
        void clear();                                 // Clear the linked list by deleting all nodes
        bool contains(const T& value) const { return findNode(value) != nullptr; } // Check if the list contains a node with the given value
        void reverse(); // Reverse the linked list in place

        enum Spot {
            HEAD = 0, // Enum to define positions for appending nodes
            TAIL = -1 // TAIL is used to append at the end of the list (default behavior)
        };

        class Iterator {
        public:
            explicit Iterator(SingleNode<T>* ptr) : current(ptr) {}
            T& operator*() const { return current->data; }
            Iterator& operator++() { current = current->next; return *this; }
            bool operator!=(const Iterator& other) const { return current != other.current; }
            bool operator==(const Iterator& other) const { return current == other.current; }

            using iterator_category = std::forward_iterator_tag;
            using value_type        = T;
            using difference_type   = std::ptrdiff_t;
            using pointer           = T*;
            using reference         = T&;

        private:
            SingleNode<T>* current;
        };

        Iterator begin() const { return Iterator(head); }
        Iterator end() const { return Iterator(nullptr); }

        class ConstIterator {
        public:
            explicit ConstIterator(const SingleNode<T>* ptr) : current(ptr) {}
            const T& operator*() const { return current->data; }
            ConstIterator& operator++() { current = current->next; return *this; }
            bool operator!=(const ConstIterator& other) const { return current != other.current; }
            bool operator==(const ConstIterator& other) const { return current == other.current; }

            using iterator_category = std::forward_iterator_tag;
            using value_type        = T;
            using difference_type   = std::ptrdiff_t;
            using pointer           = const T*;
            using reference         = const T&;

        private:
            const SingleNode<T>* current;
        };
        ConstIterator cbegin() const { return ConstIterator(head); }
        ConstIterator cend() const { return ConstIterator(nullptr); }


    private:
        size_t size;   // Size of the linked list
        SingleNode<T>* head; // Pointer to the first node in the list
        SingleNode<T>* tail; // Pointer to the last node in the list
        // Enum to define positions for appending nodes
    };

    /*
     * Name: LinkedList constructor
     * Description: Initializes an empty linked list with the head and tail pointer set to nullptr.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    LinkedList<T>::LinkedList() : size(0), head(nullptr), tail(nullptr) {
    }

    /*
     * Name: LinkedList destructor
     * Description: Cleans up the linked list by deleting all nodes to prevent memory leaks.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    LinkedList<T>::~LinkedList() {
        SingleNode<T>* current = head;
        while (current) {
            SingleNode<T>* nextNode = current->next; // Store the next node
            delete current; // Delete the current node
            current = nextNode; // Move to the next node
        }
        size = 0; // Reset size to zero
        head = nullptr; // Set head to nullptr after deletion
        tail = nullptr; // Set tail to nullptr after deletion
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
        SingleNode<T>* newNode = new SingleNode<T>(value);
        // If the spot is 0, insert at the head
        if (spot == HEAD) {
            newNode->next = head;
            head = newNode;
            if (!tail) tail = newNode; // If list was empty, set tail
            size++; // Increment size
            return;
        }
        // If the head is null, set the new node as the head
        if (!head) {
            head = newNode;
            tail = newNode; // If the list was empty, set tail to the new node as well
            size++;
            return;
        }
        // Set the current node to the head and traverse to the desired spot
        SingleNode<T>* current = head;
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
        if (!newNode->next) tail = newNode; // If inserted at end, update tail
        size++; // Increment size
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
            SingleNode<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        // Otherwise, traverse the list to find the node with the given value
        SingleNode<T>* current = head;
        // Traverse until we find the node with the value or reach the end of the list
        while (current->next && !(current->next->getData() == value)) {
            current = current->next;
        }
        // If we found the node, remove it by updating the next pointer of the previous node
        if (current->next) {
            SingleNode<T>* temp = current->next;
            current->next = current->next->next;
            if (!current->next) {
                tail = current; // If we removed the last node, update the tail pointer
            }
            delete temp;
            size--;
        }
        // If we didn't find the node, do nothing
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
        SingleNode<T>* current = head;
        while (current) {
            // The custom function passed as a parameter is called for each node's data
            func(current->getData());
            current = current->next;
        }
        // Print a newline at the end for better readability
        std::cout << std::endl;
    }

    /*
     * Name: LinkedList.findNode
     * Description: Finds a node with the given value and returns a pointer to it.
     * Parameters: value - The value to search for in the linked list.
     * Returns: SingleNode<T>* - Pointer to the node containing the value, or nullptr if not found.
     */
    template<typename T>
    SingleNode<T>* LinkedList<T>::findNode(const T& value) const {
        const SingleNode<T>* current = head; // Start from the head of the list
        // Traverse the list to find the node with the given value
        while (current) {
            if (current->getData() == value) { // If the current node's data matches the value
                return const_cast<SingleNode<T>*>(current); // Return a non-const pointer to the found node
            }
            current = current->next; // Else move to the next node
        }
        std::cerr << "No such node" << std::endl;
        return nullptr; // If no node with the value is found, return nullptr
    }

    /*
     * Name: LinkedList.removeNode
     * Description: Removes a specific node from the linked list.
     * Parameters: node - Pointer to the node to be removed.
     * Returns: void - No return value.
     */
    template<typename T>
    void LinkedList<T>::removeNode(SingleNode<T>* node) {
        if (!node || !head) return; // If the node is null or the list is empty, do nothing
        if (node == head) {
            head = head->next; // Update the head pointer
            if (node == tail) {
                tail = nullptr;  // The list had one element
            }
            delete node; // Delete the node
            size--; // Decrement the size of the list
            return;
        }
        // Traverse the list to find the previous node
        SingleNode<T>* current = head;
        while (current && current->next != node) {
            current = current->next; // Move to the next node
        }
        // If we found the previous node, update its next pointer to skip the node to be removed
        if (current) {
            current->next = node->next; // Bypass the node to be removed
            if (node == tail) {
                tail = current; // Update the tail if the removed node was the last one
            }
            delete node; // Delete the node
            size--; // Decrement the size of the list
        }
    }

    /*
     * Name: LinkedList.clear
     * Description: Clears the linked list by deleting all nodes.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    void LinkedList<T>::clear() {
        SingleNode<T>* current = head; // Start from the head of the list
        while (current) {
            SingleNode<T>* nextNode = current->next; // Store the next node
            delete current; // Delete the current node
            current = nextNode; // Move to the next node
        }
        head = nullptr; // Set head to nullptr after deletion
        tail = nullptr; // Set tail to nullptr after deletion
        size = 0; // Reset size to zero
    }

    /*
     * Name: LinkedList.reverse
     * Description: Reverses the linked list in place.
     * Parameters: None
     * Returns: void - No return value.
     */
    template<typename T>
    void LinkedList<T>::reverse() {
        SingleNode<T>* prev = nullptr; // Previous node pointer
        SingleNode<T>* current = head; // Current node pointer
        tail = head; // Set tail to the current head
        while (current) {
            SingleNode<T>* nextNode = current->next; // Store the next node
            current->next = prev; // Reverse the next pointer
            prev = current; // Move prev to the current node
            current = nextNode; // Move to the next node
        }
        head = prev; // Update head to the last processed node
    }



}

#endif //LINKEDLIST_H
