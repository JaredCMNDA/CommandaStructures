# CommandaStructures

CommandaStructures is a personal C++ library of fundamental data structures, designed to be reused across multiple projects. The goal is to avoid rewriting common structures like linked lists, queues, stacks, and more, by maintaining a single, well-tested codebase.

## Features

- **Linked List**: Generic singly linked list implementation.
- **Double Linked List**: Generic doubly linked list implementation.
- **Queue**: Generic queue built on top of the singly linked list.
- *(Planned: Stack, Trees, and other data structures)*

## Why?

When working on various C++ projects, it's common to need basic data structures. Instead of copying and pasting code or rewriting from scratch, CommandaStructures provides a central place for reusable, template-based implementations.

## Usage

1. **Clone or copy** this repository into your project.
2. **Include** the headers you need in your source files:
   ```cpp
   #include "linkedlist.h"
   #include "doublelinkedlist.h"
   #include "queue.h"
   ```
3. **Use the data structures** as templates with your own types:
   ```cpp
   LinkedList<int> intList;
   Queue<std::string> stringQueue;
   DoubleLinkedList<double> doubleList;
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

See `src/main.cpp` for more example usage and tests.

## Project Structure

- `include/` — Header files for all data structures (`linkedlist.h`, `doublelinkedlist.h`, `queue.h`, `node.h`)
- `src/` — Example usage and tests (`main.cpp`)
- `CMakeLists.txt` — Build configuration (if using CMake)

## License

This is a personal project. Use at your own risk.

---
*Created by Levi, 2025*
