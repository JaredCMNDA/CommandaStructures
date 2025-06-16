//
// Created by Levi on 2025-06-11.
//

#ifndef NODE_H
#define NODE_H

namespace CommandaStructures::Single {
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
    class SingleNode {
        // Node class to represent each element in the linked list
        // It contains data of type T and a pointer to the next node
    public:
        T data;
        SingleNode<T>* next;
        explicit SingleNode(const T& value);
        T& getData() { return data; } // Getter for data
    };

    /*
     * Name: Node constructor
     * Description: Initializes a node with the given value and sets the next pointer to nullptr.
     * Parameters: value - The value to be stored in the node.
     * Returns: void - No return value.
     */
    template<typename T>
    SingleNode<T>::SingleNode(const T& value) : data(value), next(nullptr) {}

}

namespace CommandaStructures::Double {
    /*
     * Double Node Class
     * Used for double linked lists where each node has a pointer to both the next and previous nodes.
     * Did two separate classes for single and double nodes to keep the code clean and maintainable and reduce memory usage
     * This class inherits from SingleNode and adds a pointer to the previous node.
     */
    template<typename T>
    class DoubleNode {
    public:
        T data;
        DoubleNode<T>* next;
        DoubleNode<T>* prev;
        explicit DoubleNode(const T& value);
        T& getData() { return data; } // Getter for data
    };

    /*
     * Name: DoubleNode constructor
     * Description: Initializes a double node with the given value, sets the next pointer to nullptr, and the previous pointer to nullptr.
     * Parameters: value - The value to be stored in the node.
     * Returns: void - No return value.
     */
    template<typename T>
    DoubleNode<T>::DoubleNode(const T& value) : data(value), next(nullptr), prev(nullptr) {}

}

#endif //NODE_H
