// Works too. Best so far. Recursive descent.
// Note ignoreSpace() is called only in num().
class Solution2 {
public:
    int calculate(string s) {
        const char * p = s.c_str();
        return E(p);
    }
    
    // E := F | F +- F
    // F := T | T */ T
    // T := num | (E)
    int E(const char *& p) {
        int n = F(p);
        while (*p == '+' || *p == '-') {
            char op = *p;
            ++ p;
            int m = F(p);
            if (op == '+') n += m;
            else n -= m;
        }
        return n;
    }
    
    int F(const char *& p) {
        int n = T(p);
        while (*p == '*' || *p == '/') {
            char op = *p;
            ++ p;
            int m = T(p);
            if (op == '*') n *= m;
            else {
                if (m == 0) throw exception(); // divide by 0.
                n /= m;
            }
        }
        return n;
    }

    int T(const char *& p) {
        if (isNum(p)) {
            return num(p);
        }
        else {
            expect(p, '(');
            int n = E(p);
            expect(p, ')');
            return n;
        }
    }

    int num(const char *& p) {
        ignoreSpace(p);

        int v = 0;
        while (isDigit(*p)) {
            v = v * 10 + *p - '0';
            ++ p;
        }
        ignoreSpace(p);

        return v;
    }
    
    void expect(const char * p, char c) {
        if (*p == c) return;
        throw exception();
    }
    
    bool isNum(const char * p) {
        while (isspace(*p)) ++ p;
        return isdigit(*p);
    }
    
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    
    void ignoreSpace(const char *& p) {
        while (isspace(*p)) ++ p;
    }
};


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
