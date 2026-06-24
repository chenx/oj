# Java Concurrency Models: Multi-Threading, Async, and Non-Blocking I/O

Modern Java offers three distinct approaches to handle concurrent tasks and high-throughput operations. Choosing the right tool depends heavily on whether your application is **CPU-bound** (heavy calculations) or **I/O-bound** (waiting on databases, networks, or disks).


## Links

- https://docs.oracle.com/javase/8/docs/api/java/lang/Thread.html
- https://www.w3schools.com/java/java_threads.asp
- https://www.geeksforgeeks.org/java/java-threads/
- https://medium.com/@syed.fawzul.azim/how-java-threads-work-jvm-internals-cpu-level-execution-and-multi-threading-in-java-89d8d343677f


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



## Summary: Architectural Comparison

| Feature | Multi-Threading (BIO) | Asynchronous Programming | Non-Blocking I/O (NIO) |
| - | - | - | - |
| **Thread Management** | One thread per connection/task. | Reuses threads via pools or background executors. | Single thread manages multiple connections. |
| **Blocking Behavior** | Thread idles while waiting for network/disk responses. | Thread is freed; notification triggers when done. | Thread never idles; polls streams for ready data. |
| **Scalability Limit** | Limited by OS kernel thread constraints (~thousands). | Limited by pool sizing and heap memory. | Scalable to millions of concurrent open sockets. |
| **Complexity** | Low to Medium (intuitive imperative code). | Medium (functional, callback, or chain style). | High (requires event loops and state machines). |



## Modern Note: Virtual Threads (Project Loom)
If you are using **Java 21 or later**, you can combine the simple, imperative coding style of **Multi-Threading** with the massive scalability of **Non-Blocking I/O** using **Virtual Threads**. They are lightweight threads managed by the Java runtime instead of the OS, allowing you to run millions of concurrent threads without memory exhaustion.

```java
// Java 21+ Lightweight Virtual Thread creation
Thread.startVirtualThread(() -> {
    System.out.println("Running on a lightweight virtual thread!");
});
```

---

# Thread, Runnable, Platform Threads (Traditional) vs Virtual Threads (Java 21+), ExecutorServices (Thread Pool)

**Java threading** allows your program to execute multiple tasks concurrently by splitting work into independent paths of execution. By default, every Java application runs on a single "main" thread, but you can create additional threads to perform background tasks, maximize CPU utilization, and keep user interfaces responsive.

### Core Approaches to Creating Threads

Java offers two classic techniques for defining and launching a basic platform thread.

#### 1. Implementing the `Runnable` Interface (Preferred)
You implement the [Runnable Interface](https://oracle.com) and pass it to a `Thread` object. This is the industry-standard preference because Java does not support multiple class inheritance. Implementing an interface keeps your class free to extend something else.

```java
public class MyRunnable implements Runnable {
    @Override
    public void run() {
        System.out.println("Running in a separate thread: " + Thread.currentThread().getName());
    }

    public static void main(String[] args) {
        Thread thread = new Thread(new MyRunnable());
        thread.start(); // Spawns the thread and executes run()
    }
}
```

#### 2. Extending the `Thread` Class
You subclass the [Thread Class](https://oracle.com) and override its `run()` method. This is simple but structurally restrictive.

```java
public class MyThread extends Thread {
    @Override
    public void run() {
        System.out.println("Running inside extended Thread class.");
    }

    public static void main(String[] args) {
        MyThread thread = new MyThread();
        thread.start(); // Never call run() directly; start() instantiates the actual thread
    }
}
```



### Comparison: Classic Platforms vs. Modern Virtual Threads

Java concurrency drastically improved with the introduction of **Virtual Threads** in Java 21. 

| Feature | Platform Threads (Traditional) | Virtual Threads (Java 21+) |
| :--- | :--- | :--- |
| **Management** | Managed directly by the Operating System. | Managed purely by the Java Runtime (JVM). |
| **Resource Cost** | Heavy; large stack memory allocations. | Lightweight; negligible footprint. |
| **Scalability** | Limited to thousands due to OS constraints. | Scalable to millions within one application. |
| **Best Used For** | Long-running, heavy CPU-bound computations. | High-volume blocking I/O (e.g., HTTP requests). |

*To launch a virtual thread in modern Java:*
```java
Thread.ofVirtual().start(() -> System.out.println("Lightweight virtual thread!"));
```



### Advanced Concurrency: ExecutorServices

Manually spinning up raw `Thread` objects for every single background task can easily crash your system under high load. Instead, production applications use thread pools via the `ExecutorService` framework.

*   **Fixed Thread Pools**: Limits the system to a fixed allocation of concurrent workers.
*   **Cached Thread Pools**: Dynamically expands and contracts based on real-time spikes in short tasks.

```java
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ThreadPoolExample {
    public static void main(String[] args) {
        // Creates a controlled ecosystem with exactly 3 worker threads
        ExecutorService executor = Executors.newFixedThreadPool(3);

        for (int i = 0; i < 10; i++) {
            executor.submit(() -> {
                System.out.println("Executing via pool: " + Thread.currentThread().getName());
            });
        }
        
        executor.shutdown(); // Gracefully closes down the thread resource pool
    }
}
```



### Thread Safety and Synchronization

Because independent threads share the same application memory space, multiple threads trying to modify the same resource simultaneously will corrupt your data (race conditions). 

You must guarantee thread safety using one of these options:
*   **The `synchronized` Keyword**: Locks a block or whole method to allow only one thread entry at a time.
*   **Volatile Variables**: Guarantees that changes to a variable are instantly visible across separate CPU registers.
*   **Concurrent Collections**: Avoid standard arrays/lists and use drop-in thread-safe equivalents like `ConcurrentHashMap` or `CopyOnWriteArrayList`.
