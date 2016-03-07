// Works too. Tested.
class Solution3 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++ i) {
            string t = tokens[i];
            if (isOp(t)) calc(s, t);
            else s.push(stoi(t));
        }
        
        return s.top();
    }
    
    bool isOp(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    
    void calc(stack<int> & s, string op) {
        if (s.size() < 2) return; // or throw underflow exception.
        int b = s.top(); s.pop();
        int a = s.top(); s.pop();
        
        if (op == "+") s.push(a + b);
        else if (op == "-") s.push(a - b);
        else if (op == "*") s.push(a * b);
        else if (op == "/") {
            if (b == 0) s.push(0);  // or throw divideBy0 exception.
            else s.push(a/b);
        }
        else s.push(0); // or throw unknownOp exception.
    }
};

// This also works. Although maybe Solution looks better.
class Solution2 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); ++ i) {
            if (! isOp(tokens[i])) s.push(toInt(tokens[i]));
            else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(calc(a, b, tokens[i]));
            }
        }
        return s.top();
    }
    
    int calc(int a, int b, string op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return b == 0 ? 0 : a / b;
        return 0;
    }
    
    // Another way to convert string to int. 
    int toInt2(string s) {
        istringstream iss(s);
        int val;
        iss >> val;
        return val;
    }
    
    int toInt(string s) {
        int val = 0, i = 0;
        bool neg = s[0] == '-';
        if (neg) ++ i;
        else if (s[0] == '+') ++ i;
        
        for (; i < s.length(); ++ i) {
            val = val * 10 + s[i] - '0';
        }
        
        if (neg) val = - val;
        return val;
    }
    
    bool isOp(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
};

//
// This works.
//
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 0) return 0;
        
        stack<int> v;
        for (int i = 0; i < tokens.size(); ++ i) {
            string s = tokens[i];
            if (s == "+") {
                int a = v.top(); v.pop(); 
                int b = v.top(); v.pop();
                v.push(a + b);
            }
            else if (s == "-") {
                int a = v.top(); v.pop(); 
                int b = v.top(); v.pop();
                v.push(b - a);
            }
            else if (s == "*") {
                int a = v.top(); v.pop(); 
                int b = v.top(); v.pop();
                v.push(a * b);
            }
            else if (s == "/") {
                int a = v.top(); v.pop(); 
                int b = v.top(); v.pop();
                v.push(b / a);
            }
            else {
                istringstream iss(s);
                int val;
                iss >> val;
                v.push(val);
            }
        }
        
        return v.top();
    }
};


/*
Evaluate Reverse Polish Notation
Total Accepted: 1386 Total Submissions: 7271

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/
