# CommandaStructures

CommandaStructures is a personal C++ library of fundamental data structures, designed to be reused across multiple projects. The goal is to avoid rewriting common structures like linked lists, queues, stacks, and more, by maintaining a single, well-tested codebase.

## Features

- **Linked List**: Generic singly linked list implementation.
- **Queue**: Generic queue built on top of the linked list.
- *(Planned: Stack, Trees, and other data structures)*

## Why?

When working on various C++ projects, it's common to need basic data structures. Instead of copying and pasting code or rewriting from scratch, CommandaStructures provides a central place for reusable, template-based implementations.

## Usage

1. **Clone or copy** this repository into your project.
2. **Include** the headers you need in your source files:
   ```cpp
   #include "linkedlist.h"
   #include "queue.h"
   ```
3. **Use the data structures** as templates with your own types:
   ```cpp
   LinkedList<int> intList;
   Queue<std::string> stringQueue;
   ```

See `src/main.cpp` for example usage and tests.

## Building

This project uses CMake. To build:

```sh
cmake -S . -B build
cmake --build build
```

## License

This is a personal project. Use at your own risk.

---
*Created by Levi, 2025*
