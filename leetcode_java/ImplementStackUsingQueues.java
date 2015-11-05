class MyStack {
    // Push element x onto stack.
    public void push(int x) {
        if (q1.isEmpty()) {
            q1.add(x);
            return;
        }
        
        q1.add(x);
        q2.add(q1.remove());
    }

    // Removes the element on top of the stack.
    public void pop() {
        if (q1.isEmpty()) return;
        
        q1.remove();
        
        int len = q2.size();
        for (int i = 0; i < len; ++ i) { // Note: "i < len", not "i < len - 1".
            push(q2.remove());
        }
    }

    // Get the top element.
    public int top() {
        if (empty()) return null; // underflow.
        return q1.peek();
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return q1.isEmpty();
    }
    
    private Queue<Integer> q1 = new LinkedList<Integer>();
    private Queue<Integer> q2 = new LinkedList<Integer>();
}


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
