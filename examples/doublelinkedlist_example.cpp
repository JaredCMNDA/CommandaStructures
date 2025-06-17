//
// Created by Levi on 2025-06-16.
//
#include "doublelinkedlist.h"
#include "nodes.h"
#include <iostream>
using namespace CommandaStructures;

void runDoubleLinkedListTest()
{
    struct NodeData
    {
        int id;
        std::string name;

        // Define equality operator
        bool operator==(const NodeData& other) const
        {
            return id == other.id && name == other.name;
        }

        std::string display() const
        {
            return "ID: " + std::to_string(id) + ", Name: " + name;
        }
    };
    DoubleLinkedList<NodeData> list;

    // Insert some nodes
    list.insert({1, "Node1"}, DoubleLinkedList<NodeData>::HEAD);
    list.insert({2, "Node2"}, DoubleLinkedList<NodeData>::TAIL);
    list.insert({3, "Node3"}, 1); // Insert at position 1 (between Node1 and Node2)
    // Display the list
    std::cout << "Double Linked List:" << std::endl;
    list.display([](const NodeData& data) { std::cout << data.display() << std::endl; });
    // Remove a node
    list.remove({2, "Node2"}); // Remove Node2 which is the tail, 2nd node
    // Display the list after removal
    std::cout << "Double Linked List after removal:" << std::endl;
    list.display([](const NodeData& data) { std::cout << data.display() << std::endl; });
    // Check the size of the list
    std::cout << "Size of the list: " << list.getSize() << std::endl;
    // Check if the head and tail are correct
    if (list.getHead())
    {
        std::cout << "Head: " << list.getHead()->getData().display() << std::endl;
    }
    else
    {
        std::cout << "Head is null." << std::endl;
    }
    if (list.getTail())
    {
        std::cout << "Tail: " << list.getTail()->getData().display() << std::endl;
    }
    else
    {
        std::cout << "Tail is null." << std::endl;
    }
    // Find a node
    NodeData searchData = {3, "Node3"};
    DoubleNode<NodeData>* foundNode = list.findNode(searchData);
    if (foundNode)
    {
        std::cout << "Found node: " << foundNode->getData().display() << std::endl;
    }
    else
    {
        std::cout << "Node not found." << std::endl;
    }
    // Try to find a node that doesn't exist
    NodeData notFoundData = {4, "Node4"};
    foundNode = list.findNode(notFoundData);
    if (foundNode)
    {
        std::cout << "Found node: " << foundNode->getData().display() << std::endl;
    }
    else
    {
        std::cout << "Node not found." << std::endl;
    }
    // Clear the list
    list.remove({1, "Node1"}); // Remove Node1 which is the head, 1st node
    list.remove({3, "Node3"}); // Remove Node3 which is the only node left
    std::cout << "Double Linked List after clearing:" << std::endl;
    list.display([](const NodeData& data) { std::cout << data.display() << std::endl; });
    std::cout << "Size of the list after clearing: " << list.getSize() << std::endl;
}