//
// Created by Levi on 2025-06-16.
//
#include <iostream>
#include "queue.h"
using namespace CommandaStructures;

void runQueueIntTest() {
    // Create a queue of integers
    Queue<int> intQueue;
    // push some integers
    intQueue.push(10);
    intQueue.push(20);
    intQueue.push(30);
    // Display the first and last elements
    std::cout << "First element: " << intQueue.front() << std::endl;
    std::cout << "Last element: " << intQueue.front() << std::endl;
    // Dequeue an element
    std::cout << "Dequeued element: " << intQueue.pop() << std::endl;
    // Display the first and last elements again
    std::cout << "First element after dequeue: " << intQueue.back() << std::endl;
    std::cout << "Last element after dequeue: " << intQueue.back() << std::endl;
    // Check if the queue is empty
    std::cout << "Queue size: " << intQueue.getSize() << std::endl;
    std::cout << "Is queue empty? " << (intQueue.isEmpty() ? "Yes" : "No") << std::endl;
    // Dequeue all elements
    while (!intQueue.isEmpty()) {
        std::cout << "Dequeued element: " << intQueue.pop() << std::endl;
    }
    // Check if the queue is empty again
    std::cout << "Queue size after dequeueing all elements: " << intQueue.getSize() << std::endl;
    std::cout << "Is queue empty? " << (intQueue.isEmpty() ? "Yes" : "No") << std::endl;
}

void runQueueTemplateTest() {
    // Create a queue of custom objects
    // Pretend this is a temperature sensor data structure?
    // Imagine we load this data from a file or a database, sensorName -> temp.1, temp.2, etc for multiple sensors?
    struct sampleData {
        std::string sensorName;
        int timeStamp;
        int samplingRate;
        int airTemperature;
        int waterTemperature;

        // Define equality operator
        bool operator==(const sampleData& other) const {
            return sensorName == other.sensorName &&
                   timeStamp == other.timeStamp &&
                   samplingRate == other.samplingRate &&
                   airTemperature == other.airTemperature &&
                   waterTemperature == other.waterTemperature;
        }

        std::string display() const {
            // Format the display of the sample data
            return "Sensor: " + sensorName +
                   ", Timestamp: " + std::to_string(timeStamp) +
                   ", Sampling Rate: " + std::to_string(samplingRate) +
                   ", Air Temp: " + std::to_string(airTemperature) +
                   ", Water Temp: " + std::to_string(waterTemperature);
        }
    };

    Queue<sampleData> dataQueue;
    // push some sample data
    dataQueue.push({"temp1", 1622547800, 10, 25, 20});
    dataQueue.push({"temp1", 1622547860, 15, 30, 22});
    dataQueue.push({"temp1", 1622547920, 20, 28, 21});
    // Display the first and last elements
    std::cout << "First element: " << dataQueue.front().display() << std::endl;
    std::cout << "Last element: " << dataQueue.back().display() << std::endl;
    // Dequeue an element
    std::cout << "Dequeued element: " << dataQueue.pop().sensorName << std::endl;
    // Display the first and last elements again
    std::cout << "First element after dequeue: " << dataQueue.front().sensorName << std::endl;
    std::cout << "Last element after dequeue: " << dataQueue.back().sensorName << std::endl;
    // Check if the queue is empty
    std::cout << "Queue size: " << dataQueue.getSize() << std::endl;
    std::cout << "Is queue empty? " << (dataQueue.isEmpty() ? "Yes" : "No") << std::endl;
    // Dequeue all elements
    while (!dataQueue.isEmpty()) {
        std::cout << "Dequeued element: " << dataQueue.pop().sensorName << std::endl;
    }
    // Check if the queue is empty again
    std::cout << "Queue size after dequeueing all elements: " << dataQueue.getSize() << std::endl;
    std::cout << "Is queue empty? " << (dataQueue.isEmpty() ? "Yes" : "No") << std::endl;
}