/**
 * Min Stack.
 * 
 * @Author: X. C.
 * @since: 11/10/2014
 */
 
 /**
  * This works too, passes all tests.
  * From: http://www.mitbbs.com/article_t/JobHunting/32825491.html
  * 
  * However, this does not save that much memory as MinStack2 when, e.g.,
  * all elements are equal, both stacks will be pushed all the time.
  * 
  * That said, if numbers are pushed in decreasing order, MinStack2 uses more spaces
  * since all numbers will be pushed to smin too as (x, 1).
  */
class MinStack3 {
    stack<int> s;
    stack<int> smin;
public:
    void push(int x) {
        if (s.empty() || smin.top() >= x) {
            smin.push(x);
        }
        s.push(x);
    }

    void pop() {
        if (smin.top() == s.top()) {
            smin.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return smin.top();
    }
};

/**
 * This works. Also passes all tests.
 * 
 * The idea is to use a pair<value, count> to store min value,
 * such that repeated min values don't need extra spaces.
 * 
 * Note: syntax wise, instead of:
 *     smin.push(pair<int, int>(x, 1);
 * you can also do:
 *     pair<int, int> p(x, 1);
 *     smin.push(p);
 */
class MinStack2 {
    stack<int> s;
    stack<pair<int, int> > smin;
public:
    void push(int x) {
        if (smin.empty()) {
            smin.push(pair<int, int>(x, 1));
        }
        else {
            if (x < smin.top().first) { 
                smin.push(pair<int, int>(x, 1));
            }
            else {
                smin.top().second += 1;
            }
        }
        s.push(x);
    }

    void pop() {
        s.pop();
        if (smin.top().second == 1) {
            smin.pop();
        }
        else {
            smin.top().second -= 1;
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return smin.top().first;
    }
};


/**
 * This works. But runs out of memory for last test.
 */
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
