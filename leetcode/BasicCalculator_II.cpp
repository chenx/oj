
class Solution {
public:
    int calculate(string s) {
        return evaluate(s);
    }

    void ignore_space(const char * &s) {
        while (*s == ' ') ++ s;
    }
    
    int getNum(const char * &s) {
        ignore_space(s);
        
        int num = 0;   
        while (*s >= '0' && *s <= '9') {
            num = num * 10 + (*s ++ - '0');
        }
        
        ignore_space(s);
        return num;
    }
    
    int evaluate(const string& expr) {
        stack<int> sn;
        const char * s = expr.c_str();
              
        sn.push(getNum(s));
        
        while (*s) {
            char op = *s ++;        
            int num = getNum(s);
            
            if (op == '*') { sn.top() *= num; }
            else if (op == '/') { sn.top() /= num; }
            else if (op == '+') { sn.push(num); }
            else if (op == '-') { sn.push(- num); }
            else { sn.push(num); }
        }
        
        int v = 0;
        while(!sn.empty()) {
            v += sn.top();
            sn.pop();
        }
        
        return v;
    }
    
};

/**
Basic Calculator II
Difficulty: Medium

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / 
operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:

"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

Note: Do not use the eval built-in library function. 
 */
