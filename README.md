# CommandaStructures

CommandaStructures is a personal C++ library of fundamental data structures, designed to be reused across multiple projects.

## Background
While working on an **autonomous surface vehicle (ASV)** for source‑water monitoring, I realised that most embedded C++ firmware still needed hand‑rolled containers for queues, ring buffers and linked lists.  
The ASV’s onboard code had to:

* log high‑rate sensor data (pH, turbidity, GPS, IMU) without dynamic allocation,
* stream telemetry over LoRa when bandwidth allowed, and
* run deterministic control loops on a Jetson‑class SBC and a safety MCU.

Instead of copying snippets from past coursework or online examples, I made a clean, header‑only library—**CommandaStructures**—so the same, well‑tested containers could serve both the ASV firmware and future robotics or data‑processing projects.

(Clean is subjective in this case - some of the code is a bit rough around the edges, but it works and is well documented! [i hope, honestly])
## Features

- **Linked List** – Generic singly linked list with STL‑style iterators  
- **Double Linked List** – Bidirectional list with forward/reverse iterators  
- **Queue** – FIFO queue built on the singly linked list  
- **Stack** – LIFO stack, also iterator‑friendly  
- **Deque** – Double‑ended queue implemented on the doubly linked list  
- **Ring Buffer** – Fixed‑size circular buffer with optional overwrite mode  

## Why?

1. **Embedded constraints** – The ASV needed deterministic memory usage and zero external dependencies  
2. **Reusability** – I no longer want to rewrite core containers for every class project or side build  
3. **Testing once** – A single library under version control means bugs get fixed everywhere at once  
4. **Iterator support** – STL‑style iterators let me plug these structures straight into `<algorithm>` without adapters  

## Usage

1. **Clone or copy** this repository into your project  
2. **Include** the headers you need:

   ```cpp
   #include "linkedlist.h"
   #include "doublelinkedlist.h"
   #include "queue.h"
   #include "stack.h"
   #include "deque.h"
   #include "ringbuffer.h"
   ```

3. **Instantiate** with your own types:

   ```cpp
   RingBuffer<float> pHBuffer(300);      // store last 300 pH readings
   Queue<Telemetry> uplinkQueue;         // telemetry packets awaiting LoRa window
   ```

4. **Iterate** using range‑based or explicit iterators:

   ```cpp
   for (auto& pkt : uplinkQueue) send(pkt);
   ```

See `examples/` and `src/` for working demos.

## Project Structure

```
include/     Header files (linkedlist.h, queue.h, …)
src/         Main entry and unit tests
examples/    Usage demos for each structure
CMakeLists   Build configuration
```

## Notes
No set dates, but some things I would like to add!

1. **Fixed‑capacity matrices and vectors** for lightweight linear algebra on the ASV 
   - Useful for state estimation, coordinate transformations, etc.
2. **Compile‑time tables** using constexpr containers for compile‑time data storage
   - Ideal for static configuration or lookup tables in embedded systems
   - Push more logic to compile time to reduce runtime overhead
   - This is something that will probably take a long time and will cause headaches so I am not rushing this :)
3. **Unit tests** for all structures to ensure reliability
4. **Iterators** for all structures to support STL algorithms
   - This is already partially done, but needs more work to be fully compliant (and I want to clean it up a bit)


## License

Personal project. Use at your own risk.

---

*Created by Jared, 2025*