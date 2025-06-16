# CommandaStructures

CommandaStructures is a personal C++ library of fundamental data structures, designed to be reused across multiple projects. The goal is to avoid rewriting common structures like linked lists, queues, stacks, and more, by maintaining a single, well-tested codebase.

## Features

- **Linked List**: Generic singly linked list implementation with iterator support.
- **Double Linked List**: Generic doubly linked list with forward and reverse iterators.
- **Queue**: Generic FIFO queue built on a singly linked list. Includes STL-compatible iterators.
- **Stack**: Generic LIFO stack built on a singly linked list. Also supports iteration.
- **Deque**: Double-ended queue implemented using a doubly linked list. Full bidirectional iteration.
- **Ring Buffer**: Fixed-size circular buffer with optional overwrite mode and iterator access.

## Why?

When working on various C++ projects, it's common to need basic data structures. Instead of copying and pasting code or rewriting from scratch, CommandaStructures provides a central place for reusable, template-based implementations with STL-style iteration.

## Usage

1. **Clone or copy** this repository into your project.
2. **Include** the headers you need in your source files:
   ```cpp
   #include "linkedlist.h"
   #include "doublelinkedlist.h"
   #include "queue.h"
   #include "stack.h"
   #include "deque.h"
   #include "ringbuffer.h"
   ```
3. **Use the data structures** as templates with your own types:
   ```cpp
   LinkedList<int> intList;
   Queue<std::string> stringQueue;
   DoubleLinkedList<double> doubleList;
   Stack<float> floatStack;
   Deque<char> charDeque;
   RingBuffer<int> intBuffer(10); // 10 element buffer
   ```
4. **Iterate through structures** using standard loops:
   ```cpp
   for (auto& val : charDeque) {
       std::cout << val << std::endl;
   }

   for (auto it = doubleList.rbegin(); it != doubleList.rend(); ++it) {
       std::cout << *it << std::endl;
   }
   ```

5. **See `src/main.cpp` and `src/test_iterators.cpp` for demos.**
   - `main.cpp`: demos for basic usage and typical operations.
   - `test_iterators.cpp`: shows how to use STL algorithms like `std::find`, `std::for_each`, `std::copy`, and reverse iteration.

## Project Structure

- `include/` — Header files for all data structures (`linkedlist.h`, `doublelinkedlist.h`, `queue.h`, `stack.h`, `deque.h`, `ringbuffer.h`, `nodes.h`)
- `src/` — Example usage and tests (`main.cpp`, `test_iterators.cpp`)
- `CMakeLists.txt` — CMake build configuration

## Notes

- All data structures are implemented as C++20 templates and support custom types (as long as `operator==` is defined).
- Iterators implement STL-compatible traits so algorithms like `std::find()` and `std::copy()` work out-of-the-box.
- Reverse iterators (`rbegin()` / `rend()`) are available in structures based on `DoubleLinkedList`.

## License

This is a personal project. Use at your own risk.

---
*Created by Levi, 2025*
