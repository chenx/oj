// Use only 1 stack.
class MyQueue2 {
    // push: O(n), use call stack as the 2nd stack.
    // pop: O(1)
    stack<int> s;

public:
    MyQueue() {}
    
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            return;
        }
        int t = s.top();
        s.pop();
        push(x);
        s.push(t);
    }
    
    int pop() {
        if (empty()) throw exception();

        int val = s.top();
        s.pop();
        return val;
    }
    
    int peek() {
        if (empty()) throw exception();

        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};


// Use 2 stacks.
// push: O(1)
// peek, pop: O(n) but amortized to O(1).
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (empty()) return;
        movS1ToS2();
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if (empty()) return -1; // underflow
        movS1ToS2();
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }

private:
    stack<int> s1;
    stack<int> s2;
    
    void movS1ToS2() {
        if (! s2.empty()) return;
        while (! s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
};

/**
Implement Queue using Stacks
Difficulty: Easy

Implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.

Notes:

    You must use only standard operations of a stack -- which means 
    only push to top, peek/pop from top, size, and is empty operations are valid.
    
    Depending on your language, stack may not be supported natively. 
    You may simulate a stack by using a list or deque (double-ended 
    queue), as long as you use only standard operations of a stack.
    
    You may assume that all operations are valid (for example, no pop 
    or peek operations will be called on an empty queue).

 */
