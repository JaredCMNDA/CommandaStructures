//
// Created by Levi on 2025-06-10.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
/*Notes:
 * Functions in the linked list class:
 * append - Adds a new node with the given value to the specified location (default end of the list).
 * size - Returns the number of nodes in the linked list.
 * remove - Removes the first node with the given value from the list.
 * display - Displays the contents of the linked list using a custom function.
 */

/* Linked List Node Class */
/*
If you want each node to store multiple types of data (e.g., color, speed, size, position, heading, etc.), you should define a struct or class that contains all the fields you need, and then use that struct/class as the template parameter for your Node and LinkedList.
For example:
struct ObjectData {
    std::string color;
    double speed;
    double size;
    double position;
    double heading;
    Add more fields as needed
};
Then, you can create a linked list of ObjectData:
Node<ObjectData>* head = nullptr;
This way, each node can store all the different types of data you need.
 */
template<typename T> // Template class for Node (allows for different data types)
class Node {
    // Node class to represent each element in the linked list
    // It contains data of type T and a pointer to the next node
public:
    T data;
    Node<T>* next;
    explicit Node(const T& value);
};

/*
 * Name: Node constructor
 * Description: Initializes a node with the given value and sets the next pointer to nullptr.
 * Parameters: value - The value to be stored in the node.
 * Returns: void - No return value.
 */
template<typename T>
Node<T>::Node(const T& value) : data(value), next(nullptr) {}

/* Linked List Class */
template<typename T> // Template class for LinkedList (allows for different data types)
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void append(const T& value, int spot = -1);   // Append a new node with the given value to the end of the list (spot is optional)
    void remove(const T& value);             // Remove the first node with the given value from the list
    int size();                              // Return the number of nodes in the linked list
    template<typename Func>                  // Function to display the contents of the linked list using a custom function
    void display(Func func) const;           // Display the contents using a custom function
    Node<T>* getHead() const; // Public getter for head
private:
    Node<T>* head; // Pointer to the first node in the list
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
 * Name: LinkedList.append
 * Description: Appends a new node with the given value to the end of the linked list.
 * Parameters: value - The value to be added to the linked list.
 * Returns: void - No return value.
 */
template<typename T>
void LinkedList<T>::append(const T& value, int spot) {
    // Create a new node with the given value
    Node<T>* newNode = new Node<T>(value);
    // If the spot is 0, insert at the head
    if (spot == 0) {
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
    // If spot is negative or greater than the size, append to the end
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
    if (head->data == value) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    // Otherwise, traverse the list to find the node with the given value
    Node<T>* current = head;
    // Traverse until we find the node with the value or reach the end of the list
    while (current->next && !(current->next->data == value)) {
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
        func(current->data);
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


#endif //LINKEDLIST_H


