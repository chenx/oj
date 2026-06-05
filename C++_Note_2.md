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

### 1. Non-Blocking I/O (The OS Level)

Non-blocking I/O ensures that a system call (like read or write) returns immediately. If the operation cannot finish right away, it returns an error code instead of putting the thread to sleep.

#### Setting Sockets to Non-Blocking

To prevent a socket file descriptor from blocking, modify its flags using the Linux native fcntl API:

```
#include <fcntl.h>
#include <unistd.h>

void set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK); // Enables O_NONBLOCK mode
}
```

#### Handling the Event Loop (epoll)

Instead of constantly polling individual non-blocking sockets in a busy-wait loop, use epoll to listen to thousands of file descriptors simultaneously.

```
#include <sys/epoll.h>

// Initialize epoll instance
int epoll_fd = epoll_create1(0);

epoll_event ev{}, events[64];
ev.events = EPOLLIN | EPOLLET; // Edge-Triggered read events
ev.data.fd = socket_fd;
epoll_ctl(epoll_fd, EPOLL_CTL_ADD, socket_fd, &ev);

// Wait loop (usually run on a dedicated I/O thread)
while (true) {
    int nfds = epoll_wait(epoll_fd, events, 64, -1);
    for (int i = 0; i < nfds; ++i) {
        if (events[i].events & EPOLLIN) {
            // Hand off events[i].data.fd to a multi-threaded worker pool
        }
    }
}
```

### 2. Multi-Threading & Async Execution (The C++ Level)

The C++ standard library does not inherently feature direct support for OS-level non-blocking network I/O. However, it does provide robust abstractions to write multi-threaded, asynchronous code to process the data fetched by your I/O loops.

#### std::async and std::future

std::async runs a function asynchronously—often by spinning up or utilizing a background thread—and immediately yields a std::future object to retrieve the result later.

```
#include <iostream>
#include <future>
#include <chrono>

int process_data(std::string data) {
    // Simulate heavy data computation or parsing
    return data.length();
}

int main() {
    std::string received_packet = "Payload data...";
    
    // Launch task asynchronously on a background thread pool managed by the runtime
    std::future<int> result = std::async(std::launch::async, process_data, received_packet);
    
    // Main thread remains entirely free to manage the I/O event loop or UI
    
    // Block only when you absolutely need the computation result
    int length = result.get(); 
    std::cout << "Processed length: " << length << std::endl;
}
```

#### C++20 Coroutines

C++20 introduced language-level coroutines (co_await, co_return). Coroutines allow a function to cooperatively suspend its execution when waiting for non-blocking I/O to complete and resume precisely where it left off once the OS signals readability.


### Modern Solutions: io_uring and Production Libraries

Writing low-level epoll wrappers and manual thread pools from scratch is prone to bugs and race conditions. Production environments rely on highly optimized frameworks:

- io_uring:
  - This is the modern, cutting-edge Linux-native asynchronous I/O interface. It relies on a lock-free submission and completion ring shared directly between kernel space and user space. It completely eliminates the context-switch overhead inherent to standard system calls.
- Boost.Asio:
  - The industrial standard for C++ network programming. It encapsulates epoll (and io_uring in newer releases) into an elegant, cross-platform, asynchronous execution context.
- libuv:
  - A high-performance, asynchronous I/O library written in C (extensively utilized in Node.js) that can be linked cleanly into C++ applications.

