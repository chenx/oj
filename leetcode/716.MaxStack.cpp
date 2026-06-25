// Use a list / array.
// - O(1) for push, pop, top. O(n) for peekMax and popMax.
// - If a list, it needs to be dll to be convenient to erase.
// - Compare dll and array: both O(n) for peekMax; for popMax, dll is O(n) , array is O(2n). 
// - Use this makes sense when peekMax and popMax happens rarely: 
//   - say if chance of calling peekMax/popMax =~ percentage of max elements in all elements, then it's amortized to O(1).
class MaxStack4 {
    vector<int> array;

public:
    MaxStack() {}
    
    void push(int x) {
        array.push_back(x);
    }
    
    int pop() {
        int val = array.back();
        array.pop_back();
        return val;
    }
    
    int top() {
        return array.back();
    }
    
    // Time out for large input.
    int peekMax() {
        return *max_element(array.begin(), array.end());
    }
    
    // Time out for large input.
    int popMax() {
        vector<int>::reverse_iterator it = max_element(array.rbegin(), array.rend());
        int val = *it;
        array.erase(std::next(it).base());
        return val;
    }

    // This does not work. Need to erase the last inserted max element, not the first.
    // E.g., array is [5,1,5], peek after popMax is 5 using popMax2, but it should be 1.
    int popMax2() {
        vector<int>::iterator it = max_element(array.rbegin(), array.rend());
        int val = *it;
        array.erase(it);
        return val;
    }
};


// Better variable names.
class MaxStack3 {
    set<pair<int, int>> valStack; // <count, value>
    set<pair<int, int>> maxStack; // <value, count>
    int count;

public:
    MaxStack() : count(0) {}
    
    void push(int x) {
        ++ count;
        valStack.insert({count, x});
        maxStack.insert({x, count});
    }
    
    int pop() {
        auto [count, value] = *valStack.rbegin();
        // auto [count, value] = *(-- valStack.end()); // This also works.
        valStack.erase({count, value});
        maxStack.erase({value, count});
        return value;
    }
    
    int top() {
        auto [count, value] = *valStack.rbegin();
        return value;
    }
    
    int peekMax() {
        auto [value, count] = *maxStack.rbegin();
        return value;
    }
    
    int popMax() {
        auto [value, count] = *maxStack.rbegin();
        maxStack.erase({value, count});
        valStack.erase({count, value});
        return value;
    }
};


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
// Time Complexity:
// - O(1) for top and peekMax.
// - O(logN) for push, pop and popMax.
// Space Complexity: O(N), the maximum size of the two balanced trees.
//
// Note this problem is similar to 155. https://leetcode.com/problems/min-stack/ 
// The reason we can't solve it like in min-stack is there is a popMax function.
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
