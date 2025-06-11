#include <iostream>
#include "linkedlist.h"
#include "queue.h"
#include "doublelinkedlist.h"
using namespace std;
using namespace CommandaStructures;
// This is a simple c++ program for relearning queue, stacks, linked lists, trees, etc.

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
    // Enqueue some integers
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    // Display the first and last elements
    std::cout << "First element: " << intQueue.getFirst() << std::endl;
    std::cout << "Last element: " << intQueue.getLast() << std::endl;
    // Dequeue an element
    std::cout << "Dequeued element: " << intQueue.dequeue() << std::endl;
    // Display the first and last elements again
    std::cout << "First element after dequeue: " << intQueue.getFirst() << std::endl;
    std::cout << "Last element after dequeue: " << intQueue.getLast() << std::endl;
    // Check if the queue is empty
    std::cout << "Queue size: " << intQueue.getSize() << std::endl;
    std::cout << "Is queue empty? " << (intQueue.isEmpty() ? "Yes" : "No") << std::endl;
    // Dequeue all elements
    while (!intQueue.isEmpty()) {
        std::cout << "Dequeued element: " << intQueue.dequeue() << std::endl;
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
    // Enqueue some sample data
    dataQueue.enqueue({"temp1", 1622547800, 10, 25, 20});
    dataQueue.enqueue({"temp1", 1622547860, 15, 30, 22});
    dataQueue.enqueue({"temp1", 1622547920, 20, 28, 21});
    // Display the first and last elements
    std::cout << "First element: " << dataQueue.getFirst().display() << std::endl;
    std::cout << "Last element: " << dataQueue.getLast().display() << std::endl;
    // Dequeue an element
    std::cout << "Dequeued element: " << dataQueue.dequeue().sensorName << std::endl;
    // Display the first and last elements again
    std::cout << "First element after dequeue: " << dataQueue.getFirst().sensorName << std::endl;
    std::cout << "Last element after dequeue: " << dataQueue.getLast().sensorName << std::endl;
    // Check if the queue is empty
    std::cout << "Queue size: " << dataQueue.getSize() << std::endl;
    std::cout << "Is queue empty? " << (dataQueue.isEmpty() ? "Yes" : "No") << std::endl;
    // Dequeue all elements
    while (!dataQueue.isEmpty()) {
        std::cout << "Dequeued element: " << dataQueue.dequeue().sensorName << std::endl;
    }
    // Check if the queue is empty again
    std::cout << "Queue size after dequeueing all elements: " << dataQueue.getSize() << std::endl;
    std::cout << "Is queue empty? " << (dataQueue.isEmpty() ? "Yes" : "No") << std::endl;
}

void DoubleLinkedListTest() {
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
    std::cout << "Size of the list: " << list.size() << std::endl;
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
    std::cout << "Size of the list after clearing: " << list.size() << std::endl;
}

int main() {

    DoubleLinkedListTest();

    return 0;

}


