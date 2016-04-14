// Works. 
// Converted from the solution to lc BasicCalculator I/II, 
// with minor changes 1) to 4) below.
// By: X.C., 4/13/2016

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> ans;
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        string s;
        for (auto e : expression) s += e;
        
        ans.clear();
        calculate(s);
        return ans;
    }
    
    int calculate(string s) {
        const char *p = s.c_str();
        return E(p);
    }

    void ignoreSpace(const char*& p) { while (isspace(*p)) ++ p; }
    void expect(const char *& p, char c) { ++ p; }

    int num(const char*& p) {
        int v = 0;
        while (isdigit(*p)) { v = v * 10 + (*p - '0'); ++ p; }
        return v;
    }

    int F(const char *& p) {
        ignoreSpace(p);

        int v = 0;
        if (*p == '(') v = E(++ p), expect(p, ')'); 
        else if (isdigit(*p)) v = num(p), ans.push_back(to_string(v));  // 1)
        else if (! *p) v = 0; 
        //else throw exception();  // 2)


        ignoreSpace(p);
        return v;
    }

    int T(const char *& p) {
        int v = F(p);
        while (*p == '*' || *p == '/') {
            char op = *p;  // 3.1)
            if (*p == '*') v *= F(++ p);
            else v /= F(++ p);
            
            ans.push_back(op == '*' ? "*" : "/");  // 3.2)
        }
        return v;
    }

    int E(const char *& p) {
        int v = T(p);
        while (*p == '+' || *p == '-') {
            char op = *p;  // 4.1)
            if (*p == '+') v += T(++ p);
            else v -= T(++ p);

            ans.push_back(op == '+' ? "+" : "-");  // 4.2)
        }
        return v;
    }
};


/**
 * http://www.lintcode.com/en/problem/convert-expression-to-reverse-polish-notation/

 Given an expression string array, return the Reverse Polish notation of 
 this expression. (remove the parentheses)
 
 Example

 For the expression [3 - 4 + 5] (which denote by ["3", "-", "4", "+", "5"]), 
 return [3 4 - 5 +] (which denote by ["3", "4", "-", "5", "+"])

 */
