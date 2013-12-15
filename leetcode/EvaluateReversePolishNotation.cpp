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