// Use begin and size only. Don't use end.
class MyCircularQueue3 {
    vector<int> q;
    int capacity;
    int begin; // pop at front.
    // int end; // add at back. end = begin + size - 1;
    int size;

public:
    MyCircularQueue(int k) : q(vector<int>(k)), capacity(k), begin(0), size(0) {}
    
    bool enQueue(int value) {
        if (isFull()) return false;

        int end = (begin + size) % capacity;
        q[end] = value;

        ++ size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        ++ begin;
        if (begin == capacity) begin = 0;

        -- size;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[begin];
    }
    
    int Rear() {
        if (isEmpty()) return -1;

        int end = (begin + size - 1 + capacity) % capacity;
        return q[end];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};


class MyCircularQueue2 {
    vector<int> q;
    int capacity;
    int begin; // pop at front.
    int end; // add at back. end = begin + size;
    int size;

public:
    MyCircularQueue(int k) : q(vector<int>(k)), capacity(k), begin(0), end(0), size(0) {}
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[end ++] = value;
        if (end == capacity) end = 0;

        ++ size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        ++ begin;
        if (begin == capacity) begin = 0;

        -- size;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[begin];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return end == 0 ? q[capacity - 1] : q[end - 1];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};


class MyCircularQueue {
    int capacity;
    int size;
    int front;
    int back;
    vector<int> buffer;

public:
    MyCircularQueue(int k) {
        capacity = k;
        buffer = vector<int>(k, 0);
        front = back = 0;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        size ++;

        buffer[back ++] = value;
        if (back == capacity) back = 0;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        size --;

        buffer[front ++] = 0;
        if (front == capacity) front = 0;

        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return buffer[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        int rear = back - 1;
        if (rear < 0) rear += capacity;
        return buffer[rear];        
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


/**
622. Design Circular Queue
Solved
Medium
Topics
conpanies iconCompanies

Design your implementation of the circular queue. The circular queue is a linear data structure in which 
the operations are performed based on FIFO (First In First Out) principle, and the last position is 
connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. 
In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a 
space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

    MyCircularQueue(k) Initializes the object with the size of the queue to be k.
    int Front() Gets the front item from the queue. If the queue is empty, return -1.
    int Rear() Gets the last item from the queue. If the queue is empty, return -1.
    boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
    boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
    boolean isEmpty() Checks whether the circular queue is empty or not.
    boolean isFull() Checks whether the circular queue is full or not.

You must solve the problem without using the built-in queue data structure in your programming language. 
 */
