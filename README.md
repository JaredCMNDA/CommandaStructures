# CommandaStructures

CommandaStructures is a personal C++ library of fundamental data structures, designed to be reused across multiple projects. The goal is to avoid rewriting common structures like linked lists, queues, stacks, and more, by maintaining a single, well-tested codebase.

## Features

- **Linked List**: Generic singly linked list implementation.
- **Double Linked List**: Generic doubly linked list implementation.
- **Queue**: Generic queue built on top of the singly linked list.
- **Stack**: Generic stack built on top of the singly linked list.
- **Deque**: Generic double-ended queue using a doubly linked list.
- **Ring Buffer**: Fixed-size circular buffer with optional overwrite mode.

## Why?

When working on various C++ projects, it's common to need basic data structures. Instead of copying and pasting code or rewriting from scratch, CommandaStructures provides a central place for reusable, template-based implementations.

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
4. **Example: Using DoubleLinkedList**
   ```cpp
   struct MyData {
       int id;
       std::string name;
       bool operator==(const MyData& other) const { return id == other.id && name == other.name; }
   };

   DoubleLinkedList<MyData> list;
   list.insert({1, "Alice"}, DoubleLinkedList<MyData>::HEAD);
   list.insert({2, "Bob"}, DoubleLinkedList<MyData>::TAIL);
   list.remove({1, "Alice"});
   ```

5. **See `src/main.cpp` for more example usage and tests.**
   - There are test/demo functions for each structure (e.g., `linkedListTest`, `queueIntTest`, `doubleLinkedListTest`, `dequeTest`, `stackTest`, `ringBufferTest`).
   - These show how to use custom structs, display functions, and typical operations.

## Project Structure

- `include/` — Header files for all data structures (`linkedlist.h`, `doublelinkedlist.h`, `queue.h`, `stack.h`, `deque.h`, `ringbuffer.h`, `node.h`)
- `src/` — Example usage and tests (`main.cpp`)
- `CMakeLists.txt` — CMake build configuration

## Notes

- All data structures are implemented as C++ templates and support custom types (structs/classes) as long as you define `operator==` for your type.
- The code is intended for learning, experimentation, and as a reusable base for future projects.
- Contributions and suggestions are welcome!

## License

This is a personal project. Use at your own risk.

---
*Created by Levi, 2025*
