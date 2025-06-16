//
// Created by Levi on 2025-06-16.
//
#include <iostream>
#include "stack.h"
using namespace CommandaStructures;

void runStackTest() {
    /* Sample Use Case:
     * You want to maintain a history of the last few oxygen readings for quick access.
     * push() new readings as they arrive
     * pop() old readings that are no longer needed
     */

    // Create a deque of custom objects
    struct OxygenReading {
        double oxygenLevel;
        int timestamp; // Timestamp of the reading

        // Define equality operator for comparison
        bool operator==(const OxygenReading& other) const {
            return oxygenLevel == other.oxygenLevel && timestamp == other.timestamp;
        }
        // Display function to format the output
        std::string display() const {
            return "Oxygen Level: " + std::to_string(oxygenLevel) + ", Timestamp: " + std::to_string(timestamp);
        }
    };
    Stack<OxygenReading> oxygenStack;
    // Adding random oxygen readings with manipulated timestamps
    for (int i = 0; i < rand() % 10 + 6; ++i) {
        int timestamp = 1622547800 + i * 10; // Incrementing timestamp by 10 seconds
        double oxygenLevel = 20.0 + (rand() % 100) / 10.0; // Random oxygen level between 20.0 and 30.0
        oxygenStack.push({oxygenLevel, timestamp});
        std::cout << "Added: " << oxygenStack.top().display() << std::endl;
    }
    // Display the top element
    std::cout << "Top element: " << oxygenStack.top().display() << std::endl;
    // Pop ("process") an element from the stack
    std::cout << "Processed top element: " << oxygenStack.pop().display() << std::endl;
    // Display the top element again
    if (!oxygenStack.isEmpty()) {
        std::cout << "Top element after pop: " << oxygenStack.top().display() << std::endl;
    } else {
        std::cout << "Stack is empty after processing." << std::endl;
    }
    // Check if the stack is empty
    std::cout << "Stack size: " << oxygenStack.getSize() << std::endl;
    std::cout << "Is stack empty? " << (oxygenStack.isEmpty() ? "Yes" : "No") << std::endl;
    // Clear the stack
    while (!oxygenStack.isEmpty()) {
        std::cout << "Clearing: " << oxygenStack.pop().display() << std::endl;
    }
    std::cout << "Stack size after clearing: " << oxygenStack.getSize() << std::endl;
    std::cout << "Is stack empty after clearing? " << (oxygenStack.isEmpty() ? "Yes" : "No") << std::endl;
}
