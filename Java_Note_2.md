# Java Concurrency Models: Multi-Threading, Async, and Non-Blocking I/O

Modern Java offers three distinct approaches to handle concurrent tasks and high-throughput operations. Choosing the right tool depends heavily on whether your application is **CPU-bound** (heavy calculations) or **I/O-bound** (waiting on databases, networks, or disks).

---

## 1. Multi-Threading

Multi-threading splits a program into multiple concurrent execution paths. In traditional Java, each `java.lang.Thread` maps directly to an **operating system (OS) kernel thread**. 

### Key Characteristics
* **Execution Model**: One task per thread. 
* **Resource Cost**: High. Each platform thread consumes around 1MB of memory for its stack.
* **Best Used For**: CPU-intensive operations (e.g., video processing, mathematical simulations).

### Code Example: Thread Pool (ExecutorService)
Instead of manually creating threads, use a thread pool to manage and reuse them efficiently.

```java
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MultiThreadingExample {
    public static void main(String[] args) {
        // Create a fixed pool of 4 platform threads
        ExecutorService executor = Executors.newFixedThreadPool(4);

        for (int i = 0; i < 10; i++) {
            final int taskId = i;
            executor.submit(() -> {
                System.out.println("Task " + taskId + " executed by " + Thread.currentThread().getName());
            });
        }

        executor.shutdown();
    }
}
```

---

## 2. Asynchronous Programming (Async)

Asynchronous programming allows a thread to initiate a task and move on to other work immediately. The task runs in the background, and the application receives a notification, callback, or container object when the result is ready.

### Key Characteristics
* **Execution Model**: Task-based, decoupled from specific threads.
* **Core API**: `CompletableFuture` (introduced in Java 8).
* **Best Used For**: Chaining dependent background tasks without blocking the main workflow.

### Code Example: CompletableFuture
```java
import java.util.concurrent.CompletableFuture;

public class AsyncExample {
    public static void main(String[] args) throws Exception {
        System.out.println("Main thread: Fetching user data...");

        // Start an asynchronous task
        CompletableFuture<String> futureResult = CompletableFuture.supplyAsync(() -> {
            simulateNetworkDelay(2000); // Background work
            return "User Profile Data";
        });

        // Chain a dependent action when the data arrives (Non-blocking pipeline)
        CompletableFuture<Void> pipeline = futureResult
            .thenApply(data -> data + " (Processed)")
            .thenAccept(finalResult -> System.out.println("Async Result: " + finalResult));

        System.out.println("Main thread: Doing other independent work...");
        
        // Wait for the async pipeline to complete before exiting main
        pipeline.get(); 
    }

    private static void simulateNetworkDelay(long ms) {
        try { Thread.sleep(ms); } catch (InterruptedException e) { Thread.currentThread().interrupt(); }
    }
}
```

---

## 3. Non-Blocking I/O (NIO)

Traditional I/O (BIO) blocks a thread until data is fully read or written. Non-Blocking I/O (NIO) allows a single thread to monitor *multiple* network connections or file streams simultaneously. If no data is available on a channel, the thread can immediately check another one.

### Key Characteristics
* **Execution Model**: Event-driven via a `Selector` that multiplexes multiple `Channels`.
* **Core API**: `java.nio` package, or ecosystem frameworks like **Netty** and **Project Reactor (Spring WebFlux)**.
* **Best Used For**: High-density I/O connections (e.g., chat applications, API gateways, streaming services).

### Code Example: Socket Channel Multiplexing
```java
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.util.Iterator;

public class NonBlockingIOServer {
    public static void main(String[] args) throws Exception {
        Selector selector = Selector.open();
        ServerSocketChannel serverChannel = ServerSocketChannel.open();
        
        serverChannel.bind(new InetSocketAddress("localhost", 8080));
        serverChannel.configureBlocking(false); // Enable non-blocking mode
        serverChannel.register(selector, SelectionKey.OP_ACCEPT);

        System.out.println("NIO Server started on port 8080...");

        while (true) {
            selector.select(); // Blocks until at least one registered channel has an event
            Iterator<SelectionKey> keys = selector.selectedKeys().iterator();

            while (keys.hasNext()) {
                SelectionKey key = keys.next();
                keys.remove();

                if (key.isAcceptable()) {
                    // Accept connection without blocking the main event loop
                    System.out.println("New client connection detected!");
                    // Handle client acceptance logic here...
                }
            }
        }
    }
}
```

---

## Summary: Architectural Comparison

| Feature | Multi-Threading (BIO) | Asynchronous Programming | Non-Blocking I/O (NIO) |
| :--- | :--- | :--- | :--- |
| **Thread Management** | One thread per connection/task. | Reuses threads via pools or background executors. | Single thread manages multiple connections. |
| **Blocking Behavior** | Thread idles while waiting for network/disk responses. | Thread is freed; notification triggers when done. | Thread never idles; polls streams for ready data. |
| **Scalability Limit** | Limited by OS kernel thread constraints (~thousands). | Limited by pool sizing and heap memory. | Scalable to millions of concurrent open sockets. |
| **Complexity** | Low to Medium (intuitive imperative code). | Medium (functional, callback, or chain style). | High (requires event loops and state machines). |

---

## Modern Note: Virtual Threads (Project Loom)
If you are using **Java 21 or later**, you can combine the simple, imperative coding style of **Multi-Threading** with the massive scalability of **Non-Blocking I/O** using **Virtual Threads**. They are lightweight threads managed by the Java runtime instead of the OS, allowing you to run millions of concurrent threads without memory exhaustion.

```java
// Java 21+ Lightweight Virtual Thread creation
Thread.startVirtualThread(() -> {
    System.out.println("Running on a lightweight virtual thread!");
});
```
