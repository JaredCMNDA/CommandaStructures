//
// Created by Levi on 2025-06-16.
//

#include "deque.h"
#include "linkedlist.h"
#include "queue.h"
#include "stack.h"
#include <algorithm>
#include <iostream>

using namespace CommandaStructures;
using namespace CommandaStructures::Single;
using namespace CommandaStructures::Double;

void runIteratorsTest()
{
    std::cout << "=== LinkedList Iterator Test ===\n";
    LinkedList<int> list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    std::cout << "Original (mutable): ";
    for (auto& val : list)
    {
        std::cout << val << " ";
        val *= 10; // mutate during iteration
    }

    std::cout << "\nAfter mutation: ";
    for (const auto& val : list)
        std::cout << val << " ";

    std::cout << "\nRead-only (cbegin/cend): ";
    for (auto it = list.cbegin(); it != list.cend(); ++it)
        std::cout << *it << " ";

    auto found = std::find(list.begin(), list.end(), 20);
    std::cout << "\nFound 20? " << (found != list.end() ? "Yes" : "No") << "\n\n";

    // ===== Queue Test =====
    std::cout << "=== Queue Iterator Test ===\n";
    Queue<int> queue;
    for (int i = 1; i <= 3; ++i)
        queue.push(i);
    for (const auto& val : queue)
        std::cout << val << " ";
    std::cout << "\n";

    // ===== Stack Test =====
    std::cout << "=== Stack Iterator Test ===\n";
    Stack<int> stack;
    for (int i = 1; i <= 3; ++i)
        stack.push(i * 5); // LIFO
    for (const auto& val : stack)
        std::cout << val << " ";
    std::cout << "\n";

    // ===== Deque Test =====
    std::cout << "=== Deque Iterator Test ===\n";
    Deque<int> deque;
    deque.push_front(1);
    deque.push_back(2);
    deque.push_back(3);

    std::cout << "Forward: ";
    for (auto it = deque.begin(); it != deque.end(); ++it)
        std::cout << *it << " ";

    std::cout << "\nReverse: ";
    for (auto it = deque.rbegin(); it != deque.rend(); ++it)
        std::cout << *it << " ";

    std::cout << "\n";
}
