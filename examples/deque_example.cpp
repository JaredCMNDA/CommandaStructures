//
// Created by Levi on 2025-06-16.
//
#include "deque.h"
#include <iostream>
using namespace CommandaStructures;

void runDequeTest()
{
    // Create a deque of integers
    Deque<int> intDeque;
    // Push some integers to the front and back
    intDeque.push_front(10);
    intDeque.push_back(20);
    intDeque.push_front(5);
    intDeque.push_back(30);
    // Display the first and last elements
    std::cout << "First element: " << intDeque.front()
              << std::endl; // Doesn't need .display() since it's an int and << operator is defined
                            // for int
    std::cout << "Last element: " << intDeque.back() << std::endl;
    // Pop an element from the front
    std::cout << "Popped front element: " << intDeque.pop_front() << std::endl;
    // Pop an element from the back
    std::cout << "Popped back element: " << intDeque.pop_back() << std::endl;
    // Display the first and last elements again
    std::cout << "First element after pops: " << intDeque.front() << std::endl;
    std::cout << "Last element after pops: " << intDeque.back() << std::endl;
    // Check if the deque is empty
    std::cout << "Deque size: " << intDeque.getSize() << std::endl;
    std::cout << "Is deque empty? " << (intDeque.isEmpty() ? "Yes" : "No") << std::endl;
}

void runDequeTemplateTest()
{
    /* Sample Use Case:
     * You want to maintain the last 60 seconds of oxygen readings and calculate rolling averages.
     * push_back() new readings as they arrive
     * pop_front() old readings that are older than 60 seconds
     */

    // Create a deque of custom objects
    struct OxygenReading
    {
        double oxygenLevel;
        int timestamp; // Timestamp of the reading

        // Define equality operator for comparison
        bool operator==(const OxygenReading& other) const
        {
            return oxygenLevel == other.oxygenLevel && timestamp == other.timestamp;
        }
        // Display function to format the output
        std::string display() const
        {
            return "Oxygen Level: " + std::to_string(oxygenLevel) +
                   ", Timestamp: " + std::to_string(timestamp);
        }
    };
    Deque<OxygenReading> oxygenDeque;

    // Adding random oxygen readings with manipulated timestamps
    for (int i = 0; i < rand() % 10 + 6; ++i)
    {
        int timestamp = 1622547800 + i * 10; // Incrementing timestamp by 10 seconds
        double oxygenLevel =
            20.0 +
            (rand() % 100) / 10.0; // Random oxygen level between 20.0 and 30.0 (this is actually
                                   // meaningless idk how oxygen sensors output data)
        oxygenDeque.push_back({oxygenLevel, timestamp});
        std::cout << "Added: " << oxygenDeque.back().display() << std::endl;
    }
    // Display the first and last elements
    std::cout << "First element: " << oxygenDeque.front().display() << std::endl;
    std::cout << "Last element: " << oxygenDeque.back().display() << std::endl;
    // Pop ("process") an element from the front
    std::cout << "Processed front element: " << oxygenDeque.pop_front().display() << std::endl;
    // Pop ("process") an element from the back
    std::cout << "Processed back element: " << oxygenDeque.pop_back().display() << std::endl;
    // Display the first and last elements again
    if (!oxygenDeque.isEmpty())
    {
        std::cout << "First element after pops: " << oxygenDeque.front().display() << std::endl;
        std::cout << "Last element after pops: " << oxygenDeque.back().display() << std::endl;
    }
    else
    {
        std::cout << "Deque is empty after processing." << std::endl;
    }
    // Check if the deque is empty
    std::cout << "Deque size: " << oxygenDeque.getSize() << std::endl;
    std::cout << "Is deque empty? " << (oxygenDeque.isEmpty() ? "Yes" : "No") << std::endl;
    // Clear the deque
    while (!oxygenDeque.isEmpty())
    {
        std::cout << "Clearing: " << oxygenDeque.pop_front().display() << std::endl;
    }
    std::cout << "Deque size after clearing: " << oxygenDeque.getSize() << std::endl;
    std::cout << "Is deque empty after clearing? " << (oxygenDeque.isEmpty() ? "Yes" : "No")
              << std::endl;
}