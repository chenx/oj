# C++ Notes (2)


## Async, non-blocking I/O, multi-threading

In Linux C++, combining asynchronous tasks, non-blocking I/O, and multi-threading represents the gold standard for building high-performance, scalable systems like web servers or database engines.

Rather than relying on one thread per connection (which wastes memory and slows down the OS scheduler), modern architecture decouples I/O multiplexing from data processing using thread pools and event loops.

### Core Architectural Patterns

High-performance applications usually rely on one of two primary architectural patterns to combine these concepts:

- Reactor Pattern:
  - A single thread running an event loop uses non-blocking I/O (epoll) to detect when a file descriptor is ready. It then dispatches the actual computational work to a multi-threaded worker pool.

- Proactor Pattern:
  - The application initiates an asynchronous I/O operation and immediately continues executing other code. The operating system performs the transfer in the background and pushes a completion event to a thread-safe queue
