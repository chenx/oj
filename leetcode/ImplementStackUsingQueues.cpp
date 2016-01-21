// This works and uses only standard queue operations.
// Key is to keep only 1 element in q1, so top() and pop() are both easy.
// When pop, after pop q1, push all q2 elements again.
// 1/20/2016
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if (! q1.empty()) {
            q2.push(q1.front()); 
            q1.pop();
        }
        q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (q1.empty()) return;
        
        q1.pop();
        for (int i = 0, len = q2.size(); i < len; ++ i) {
            push(q2.front());
            q2.pop();
        }
    }

    // Get the top element.
    int top() {
        return q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1, q2;
};

// Although works, this uses q.back(), which is non-standard.
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (empty()) return;
        int len = q.size(), v;
        for (int i = 0; i < len - 1; ++ i) {
            v = q.front();
            q.pop();
            q.push(v);
        }
        q.pop();
    }

    // Get the top element.
    int top() {
        if (empty()) return -1; // underflow.
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
    
private:
    queue<int> q;
};


/**
Implement Stack using Queues
Difficulty: Easy

Implement the following operations of a stack using queues.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.

Notes:

    You must use only standard operations of a queue -- which means only 
    push to back, peek/pop from front, size, and is empty operations are valid.
    
    Depending on your language, queue may not be supported natively. 
    You may simulate a queue by using a list or deque (double-ended queue), 
    as long as you use only standard operations of a queue.
    
    You may assume that all operations are valid (for example, no pop or 
    top operations will be called on an empty stack).

 */
