//
// Created by Levi on 2025-06-11.
//

#ifndef NODE_H
#define NODE_H
#include "linkedlist.h"

namespace CommandaStructures {

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
        Node<T>* prev;
        explicit Node(const T& value);
        T& getData() { return data; } // Getter for data
    };

    /*
     * Name: Node constructor
     * Description: Initializes a node with the given value and sets the next pointer to nullptr.
     * Parameters: value - The value to be stored in the node.
     * Returns: void - No return value.
     */
    template<typename T>
    Node<T>::Node(const T& value) : data(value), next(nullptr) {}


}
#endif //NODE_H
