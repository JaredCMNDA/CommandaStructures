#include <iostream>
#include "linkedlist.h"
#include "queue.h"
using namespace std;
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
    // Append some data to the speed linked list
    speedList.append({55.5, 1622547800}); // Speed of 55.5 at timestamp 1622547800
    speedList.append({60.0, 1622547860}); // Speed of 60.0 at timestamp 1622547860
    speedList.append({65.2, 1622547920}); // Speed of 65.2 at timestamp 1622547920

    // Append some data to the turbidity linked list
    turbidityList.append({1.2, 1622547800}); // Turbidity of 1.2 at timestamp 1622547800
    turbidityList.append({1.5, 1622547860}); // Turbidity of 1.5 at timestamp 1622547860
    turbidityList.append({1.8, 1622547920}); // Turbidity of 1.8 at timestamp 1622547920

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

int main() {

    queueTemplateTest();
    return 0;

}


