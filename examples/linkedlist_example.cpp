//
// Created by Levi on 2025-06-16.
//
#include <iostream>
#include "linkedlist.h"
using namespace CommandaStructures;

void runLinkedListExample() {
    // Create two linked lists, both will have different data types (e.g., two diff sensors give diff parameters)
    // Speed sensor linked list
    struct SpeedData {
        double speed;
        double timestamp; // Timestamp of the speed measurement
    };
    SingleNode<SpeedData>* speedHead = nullptr;

    // Turbidity sensor linked list
    struct TurbidityData {
        double turbidity;
        double timestamp; // Timestamp of the turbidity measurement
    };
    SingleNode<TurbidityData>* turbidityHead = nullptr;

    // Create instances of the linked lists
    LinkedList<SpeedData> speedList;
    LinkedList<TurbidityData> turbidityList;
    // insert some data to the speed linked list
    speedList.insert({55.5, 1622547800}); // Speed of 55.5 at timestamp 1622547800
    speedList.insert({60.0, 1622547860}); // Speed of 60.0 at timestamp 1622547860
    speedList.insert({65.2, 1622547920}); // Speed of 65.2 at timestamp 1622547920

    // insert some data to the turbidity linked list
    turbidityList.insert({1.2, 1622547800}); // Turbidity of 1.2 at timestamp 1622547800
    turbidityList.insert({1.5, 1622547860}); // Turbidity of 1.5 at timestamp 1622547860
    turbidityList.insert({1.8, 1622547920}); // Turbidity of 1.8 at timestamp 1622547920

    // Display the speed linked list
    std::cout << "Speed Linked List:" << std::endl;
    speedList.display([](const SpeedData& data) {
        std::cout << "Speed: " << data.speed << " at timestamp: " << data.timestamp << std::endl;
    });
    // Display the turbidity linked list
    std::cout << "Turbidity Linked List:" << std::endl;
    turbidityList.display([](const TurbidityData& data) {
        std::cout << "Turbidity: " << data.turbidity << " at timestamp: " << data.timestamp << std::endl;
    });
}