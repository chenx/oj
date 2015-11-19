class MinStack {
    public void push(int x) {
        s.push(x);
        if (sm.isEmpty() || sm.peek() >= x) sm.push(x);
    }

    public void pop() {
        if (s.isEmpty()) return;
        
        int v = s.peek();
        s.pop();
        if (sm.peek() == v) sm.pop();
    }

    public int top() {
        if (s.isEmpty()) return -1;
        return s.peek();
    }

    public int getMin() {
        if (s.isEmpty()) return -1;
        return sm.peek();
    }
    
    private Stack<Integer> s = new Stack<Integer>();
    private Stack<Integer> sm = new Stack<Integer>();
}


/**
Min Stack
Difficulty: Easy

Design a stack that supports push, pop, top, and retrieving 
the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
 */
