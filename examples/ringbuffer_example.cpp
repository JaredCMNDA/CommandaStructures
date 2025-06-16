//
// Created by Levi on 2025-06-16.
//
#include <iostream>
#include "ringbuffer.h"
using namespace CommandaStructures;

void runRingBufferTest() {

    /* Sample Use Case:
     * You want to maintain a fixed-size buffer for the last 10 temperature readings for temperature sensitivity
     */

    struct TemperatureReading {
        double temperature;
        int timestamp; // Timestamp of the reading

        // Define equality operator for comparison
        bool operator==(const TemperatureReading& other) const {
            return temperature == other.temperature && timestamp == other.timestamp;
        }
        // Display function to format the output
        std::string display() const {
            return "Temperature: " + std::to_string(temperature) + ", Timestamp: " + std::to_string(timestamp);
        }
    };

    RingBuffer<TemperatureReading> tempBuffer(10, true); // Create a ring buffer with a capacity of 10 and overwrite mode enabled
    // Adding random temperature readings with manipulated timestamps
    for (int i = 0; i < rand() % 15 + 6; ++i) {
        int timestamp = 1622547800 + i * 10; // Incrementing timestamp by 10 seconds
        double temperature = 20.0 + (rand() % 100) / 10.0; // Random temperature between 20.0 and 30.0
        try {
            tempBuffer.push({temperature, timestamp});
            std::cout << "Added: " << tempBuffer.back().display() << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    // Display the first and last elements
    if (!tempBuffer.isEmpty()) {
        std::cout << "First element: " << tempBuffer.front().display() << std::endl;
        std::cout << "Last element: " << tempBuffer.back().display() << std::endl;
    } else {
        std::cout << "Buffer is empty." << std::endl;
    }
    // Pop ("process") an element from the front
    try {
        std::cout << "Processed front element: " << tempBuffer.pop().display() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    // Display the first and la st elements again
    if (!tempBuffer.isEmpty()) {
        std::cout << "First element after pop: " << tempBuffer.front().display() << std::endl;
        std::cout << "Last element after pop: " << tempBuffer.back().display() << std::endl;
    } else {
        std::cout << "Buffer is empty after pop." << std::endl;
    }
    // Check if the buffer is empty
    std::cout << "Buffer size: " << tempBuffer.getSize() << std::endl;
    std::cout << "Is buffer empty? " << (tempBuffer.isEmpty() ? "Yes" : "No") << std::endl;
    // Clear the buffer
    tempBuffer.clear();
    std::cout << "Buffer size after clearing: " << tempBuffer.getSize() << std::endl;
    std::cout << "Is buffer empty after clearing? " << (tempBuffer.isEmpty() ? "Yes" : "No") << std::endl;
}