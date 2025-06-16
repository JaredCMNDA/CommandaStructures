cmake_minimum_required(VERSION 3.20)
project(CommandaStructures)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include path
include_directories(include)

# Main executable
add_executable(CommandaStructures
        src/main.cpp
        examples/queue_example.cpp
        examples/linkedlist_example.cpp
        examples/doublelinkedlist_example.cpp
        examples/deque_example.cpp
        examples/ringbuffer_example.cpp
        examples/stack_example.cpp
        examples/iterators_example.cpp
)

# Link the include directory to both targets
target_include_directories(CommandaStructures PRIVATE include)
