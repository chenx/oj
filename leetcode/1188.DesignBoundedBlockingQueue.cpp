// From: https://algo.monster/liteproblems/1188
#include <semaphore.h>

class BoundedBlockingQueue {
public:
/**
     * Constructor initializes a bounded blocking queue with given capacity.
     * @param capacity Maximum number of elements the queue can hold
     */
    BoundedBlockingQueue(int capacity) {
        // Initialize semaphore for available slots (producer semaphore)
        // Initial value = capacity (all slots are initially available)
        sem_init(&empty_slots_, 0, capacity);

        // Initialize semaphore for filled slots (consumer semaphore)
        // Initial value = 0 (no items to consume initially)
        sem_init(&filled_slots_, 0, 0);
    }

    /**
     * Adds an element to the queue. Blocks if queue is full.
     * @param element The element to be added to the queue
     */
    void enqueue(int element) {
        // Wait for an empty slot (decrements empty_slots_)
        sem_wait(&empty_slots_);

        // Critical section: add element to queue
        queue_.push(element);

        // Signal that a filled slot is available (increments filled_slots_)
        sem_post(&filled_slots_);
    }

    /**
     * Removes and returns an element from the queue. Blocks if queue is empty.
     * @return The element removed from the front of the queue
     */
    int dequeue() {
        // Wait for a filled slot (decrements filled_slots_)
        sem_wait(&filled_slots_);

        // Critical section: remove element from queue
        int result = queue_.front();
        queue_.pop();

        // Signal that an empty slot is available (increments empty_slots_)
        sem_post(&empty_slots_);
        return result;
    }

    /**
     * Returns the current number of elements in the queue.
     * @return Current size of the queue
     */
    int size() {
        return queue_.size();
    }

private:
    std::queue<int> queue_;        // Internal queue to store elements
    sem_t empty_slots_;            // Semaphore tracking available slots for producers
    sem_t filled_slots_;           // Semaphore tracking filled slots for consumers
};


/**
1188. Design Bounded Blocking Queue
Medium

Implement a thread-safe bounded blocking queue that has the following methods:

    BoundedBlockingQueue(int capacity) The constructor initializes the queue with a maximum capacity.
    void enqueue(int element) Adds an element to the front of the queue. If the queue is full, the calling 
        thread is blocked until the queue is no longer full.
    int dequeue() Returns the element at the rear of the queue and removes it. If the queue is empty, the 
        calling thread is blocked until the queue is no longer empty.
    int size() Returns the number of elements currently in the queue.

Your implementation will be tested using multiple threads at the same time. Each thread will either be a 
    producer thread that only makes calls to the enqueue method or a consumer thread that only makes calls 
    to the dequeue method. The size method will be called after every test case.

Please do not use built-in implementations of bounded blocking queue as this will not be accepted in an interview.
 */
