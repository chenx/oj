class MinStack {
    stack<int> s, smin;
public:
    MinStack() {
        
    }

    void push(int number) {
        if (smin.empty() || smin.top() >= number) smin.push(number);
        s.push(number);
    }

    int pop() {
        if (s.empty()) return 0;
        int val = s.top();
        
        if (smin.top() == s.top()) smin.pop();
        s.pop();
        return val;
    }

    int min() {
        return smin.top();
    }
};
