/* Works. Further cleaned from Solution7, and ignored unnecessary details. Very good.
 * http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
    E --> T {( "+" | "-" ) T}
    T --> F {( "*" | "/" ) F}
    F --> num | "(" E ")"
 * Note: F could be: - T
 */
class Solution8 {
public:
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
        else if (isdigit(*p)) v = num(p); 
        else if (! *p) v = 0; 
        else throw exception(); 

        ignoreSpace(p);
        return v;
    }

    int T(const char *& p) {
        int v = F(p);
        while (*p == '*' || *p == '/') {
            if (*p == '*') v *= F(++ p);
            else v /= F(++ p);
        }
        return v;
    }

    int E(const char *& p) {
        int v = T(p);
        while (*p == '+' || *p == '-') {
            if (*p == '+') v += T(++ p);
            else v -= T(++ p);
        }
        return v;
    }
};

// Works. Best so far.  Works for both BasicCalculator and BasicCalculator_II.
// use isdigit(), and expect. Put all ignoreSpace() to F().
// See: https://github.com/chenx/oj/blob/master/misc/BasicCalculator_III.cpp
/*
 * http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
    E --> T {( "+" | "-" ) T}
    T --> F {( "*" | "/" ) F}
    F --> num | "(" E ")"
 * Note: F could be: - T
 */
class Solution7 {
public:
    int calculate(string s) {
        const char *p = s.c_str();
        return E(p);
    }

    void ignoreSpace(const char*& p) { while (isspace(*p)) ++ p; }
    void expect(const char *& p, char c) {
        if (*p != c) {
            cout << "error: expect: " << c << endl;
            throw exception();
        }
        ++ p;
    }

    int num(const char*& p) {
        int v = 0;
        while (isdigit(*p)) { v = v * 10 + (*p - '0'); ++ p; }
        return v;
    }

    int F(const char *& p) {
        ignoreSpace(p);

        int v = 0;
        if (*p == '(') {
            v = E(++ p);
            expect(p, ')');
        }
        else if (isdigit(*p)) {
            v = num(p);
        }
        else if (! *p) { // useful for situation such as input is "".
            v = 0;
        }
        else {
            cout << "F: invalid input: " << p  << endl;
            throw exception();
        }

        ignoreSpace(p);
        return v;
    }

    int T(const char *& p) {
        int v = F(p);

        while (*p == '*' || *p == '/') {
            char op = *p;
            int u = F(++ p);
            if (op == '*') v *= u;
            else if (op == '/') v /= u;
        }
        return v;
    }

    int E(const char *& p) {
        int v = T(p);

        while (*p == '+' || *p == '-') {
            char op = *p;
            int u = T(++ p);
            if (op == '+') v += u;
            else if (op == '-') v -= u;
        }
        return v;
    }
};


// Works too. Best so far. Recursive descent.
// Allows num, +-*/()
// Note ignoreSpace() is called only in num() and expect().
// See: http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
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
    
    // use this if number can be negative.
    int num2(const char *& p) {
        ignoreSpace(p); // can be omitted, since getNextToken() is used.

        bool neg = (*p == '-');
        if (neg) ++ p;
        if (! isdigit(*p)) throw exception();

        int v = 0;
        while (isdigit(*p)) {
            v = v*10 + *p - '0';
            ++ p;
        }
        if (neg) v = -v;

        ignoreSpace(p);
        return v;
    }

    
    void expect(const char *& p, char c) {
        ignoreSpace(p);
        if (*p == c) {
            ++ p;
            return;
        }
        // print error msg.
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
