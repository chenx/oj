// Use vector<int> instead of pair<int, int>.
class MaxStack2 {
    set<vector<int>> stack;
    set<vector<int>> values;
    int count;
public:
    MaxStack() {
        count = 0;
    }
    
    void push(int x) {
        ++ count;
        stack.insert({count, x});
        values.insert({x, count});
    }
    
    int pop() {
        vector<int> p = *stack.rbegin();
        stack.erase(p);
        values.erase({p[1], p[0]});
        return p[1];
    }
    
    int top() {
        vector<int> p = *stack.rbegin();
        return p[1];
    }
    
    int peekMax() {
        vector<int> p = *values.rbegin();
        return p[0];
    }
    
    int popMax() {
        vector<int> p = *values.rbegin();
        values.erase(p);
        stack.erase({p[1], p[0]});
        return p[0];
    }
};


// A set is a balanced tree. *set.rbegin() is always the one with the largest value.
//
// From https://leetcode.com/problems/max-stack/editorial/
// Time Complexity: O(logN) for each operation except for initialization.
// Space Complexity: O(N), the maximum size of the two balanced trees.
class MaxStack {
private:
    set<pair<int, int>> stack;
    set<pair<int, int>> values;
    int cnt;

public:
    MaxStack() { cnt = 0; }

    void push(int x) {
        stack.insert({cnt, x});
        values.insert({x, cnt});
        cnt++;
    }

    int pop() {
        pair<int, int> p = *stack.rbegin();
        stack.erase(p);
        values.erase({p.second, p.first});
        return p.second;
    }

    int top() { return stack.rbegin()->second; }

    int peekMax() { return values.rbegin()->first; }

    int popMax() {
        pair<int, int> p = *values.rbegin();
        values.erase(p);
        stack.erase({p.second, p.first});
        return p.first;
    }
};

/**
716. Max Stack

Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

    MaxStack() Initializes the stack object.
    void push(int x) Pushes element x onto the stack.
    int pop() Removes the element on top of the stack and returns it.
    int top() Gets the element on the top of the stack without removing it.
    int peekMax() Retrieves the maximum element in the stack without removing it.
    int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, 
    only remove the top-most one.

You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.
 */
