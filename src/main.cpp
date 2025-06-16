#include <iostream>
#include <stdlib.h> // For random number generation

#include "linkedlist.h"
#include "queue.h"
#include "doublelinkedlist.h"
#include "deque.h"
#include "stack.h"
#include "ringbuffer.h"

using namespace std;
using namespace CommandaStructures;
// This is a simple c++ program for relearning queue, stacks, linked lists, trees, etc.

/*TO DO:
 * add tail pointer to linked list
 *
 */

void linkedListTest() {
    // Create two linked lists, both will have different data types (e.g., two diff sensors give diff parameters)
    // Speed sensor linked list
    struct SpeedData {
        double speed;
        double timestamp; // Timestamp of the speed measurement
    };
    Node<SpeedData>* speedHead = nullptr;

    // Turbidity sensor linked list
    struct TurbidityData {
        double turbidity;
        double timestamp; // Timestamp of the turbidity measurement
    };
    Node<TurbidityData>* turbidityHead = nullptr;

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

void queueIntTest() {
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

void queueTemplateTest() {
    // Create a queue of custom objects
    // Pretend this is a temperature sensor data structure?
    // Imagine we load this data from a file or a database, sensorName -> temp.1, temp.2, etc for multiple sensors?
    struct sampleData {
        string sensorName;
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

        string display() const {
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

void doubleLinkedListTest() {
    struct NodeData {
        int id;
        string name;

        // Define equality operator
        bool operator==(const NodeData& other) const {
            return id == other.id && name == other.name;
        }

        string display() const {
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
    list.display([](const NodeData& data) {
        std::cout << data.display() << std::endl;
    });
    // Remove a node
    list.remove({2, "Node2"}); // Remove Node2 which is the tail, 2nd node
    // Display the list after removal
    std::cout << "Double Linked List after removal:" << std::endl;
    list.display([](const NodeData& data) {
        std::cout << data.display() << std::endl;
    });
    // Check the size of the list
    std::cout << "Size of the list: " << list.getSize() << std::endl;
    // Check if the head and tail are correct
    if (list.getHead()) {
        std::cout << "Head: " << list.getHead()->getData().display() << std::endl;
    } else {
        std::cout << "Head is null." << std::endl;
    }
    if (list.getTail()) {
        std::cout << "Tail: " << list.getTail()->getData().display() << std::endl;
    } else {
        std::cout << "Tail is null." << std::endl;
    }
    // Find a node
    NodeData searchData = {3, "Node3"};
    Node<NodeData>* foundNode = list.findNode(searchData);
    if (foundNode) {
        std::cout << "Found node: " << foundNode->getData().display() << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }
    // Try to find a node that doesn't exist
    NodeData notFoundData = {4, "Node4"};
    foundNode = list.findNode(notFoundData);
    if (foundNode) {
        std::cout << "Found node: " << foundNode->getData().display() << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }
    // Clear the list
    list.remove({1, "Node1"}); // Remove Node1 which is the head, 1st node
    list.remove({3, "Node3"}); // Remove Node3 which is the only node left
    std::cout << "Double Linked List after clearing:" << std::endl;
    list.display([](const NodeData& data) {
        std::cout << data.display() << std::endl;
    });
    std::cout << "Size of the list after clearing: " << list.getSize() << std::endl;
}

void dequeTest() {
    // Create a deque of integers
    Deque<int> intDeque;
    // Push some integers to the front and back
    intDeque.push_front(10);
    intDeque.push_back(20);
    intDeque.push_front(5);
    intDeque.push_back(30);
    // Display the first and last elements
    std::cout << "First element: " << intDeque.front() << std::endl; // Doesn't need .display() since it's an int and << operator is defined for int
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

void dequeTemplateTest() {
    /* Sample Use Case:
     * You want to maintain the last 60 seconds of oxygen readings and calculate rolling averages.
     * push_back() new readings as they arrive
     * pop_front() old readings that are older than 60 seconds
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
        string display() const {
            return "Oxygen Level: " + std::to_string(oxygenLevel) + ", Timestamp: " + std::to_string(timestamp);
        }
    };
    Deque<OxygenReading> oxygenDeque;

    // Adding random oxygen readings with manipulated timestamps
    for (int i = 0; i < rand() % 10 + 6; ++i) {
        int timestamp = 1622547800 + i * 10; // Incrementing timestamp by 10 seconds
        double oxygenLevel = 20.0 + (rand() % 100) / 10.0; // Random oxygen level between 20.0 and 30.0 (this is actually meaningless idk how oxygen sensors output data)
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
    if (!oxygenDeque.isEmpty()) {
        std::cout << "First element after pops: " << oxygenDeque.front().display() << std::endl;
        std::cout << "Last element after pops: " << oxygenDeque.back().display() << std::endl;
    } else {
        std::cout << "Deque is empty after processing." << std::endl;
    }
    // Check if the deque is empty
    std::cout << "Deque size: " << oxygenDeque.getSize() << std::endl;
    std::cout << "Is deque empty? " << (oxygenDeque.isEmpty() ? "Yes" : "No") << std::endl;
    // Clear the deque
    while (!oxygenDeque.isEmpty()) {
        std::cout << "Clearing: " << oxygenDeque.pop_front().display() << std::endl;
    }
    std::cout << "Deque size after clearing: " << oxygenDeque.getSize() << std::endl;
    std::cout << "Is deque empty after clearing? " << (oxygenDeque.isEmpty() ? "Yes" : "No") << std::endl;
}

void stackTest() {
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
        string display() const {
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

void ringBufferTest() {

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
        string display() const {
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

int main() {

    ringBufferTest();


    return 0;

}
