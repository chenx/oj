
class MinStack {
    stack<int> s;
    stack<int> smin;
public:
    void push(int x) {
        smin.push(smin.empty() ? x : min(x, smin.top()));
        s.push(x);
    }

    void pop() {
        s.pop();
        smin.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return smin.top();
    }
};


/*
Min Stack.

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
