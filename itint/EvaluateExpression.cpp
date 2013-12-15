//返回表达式expr的值

#include <iostream>
#include <stack>
using namespace std;

// This works.
    double num(const char*& p) {
        while (isspace(*p)) ++ p; // this allows space to be skipped.

        bool bNeg = false;
        if (*p == '-') {
            bNeg = true;
            p++;
        }
    
        int res = 0;
        while (*p >= '0' && *p <= '9')
            res = res*10 + *p++ - '0';
    
        return bNeg ? -res : res;
    }
    
    double mul(const char*& p) {
        double res = num(p);
        while (isspace(*p)) ++ p; // this allows space to be skipped.

        while (*p == '*' || *p == '/') {
            if (*p == '*')
                res *= num(++p);
            else
                res /= num(++p);
        }
    
        return res;
    }

    double Add(const char*& p) {
        double res = mul(p);
        while (isspace(*p)) ++ p; // this allows space to be skipped.

        while (*p == '+' || *p == '-') {
            if (*p == '+')
                res += mul(++p);
            else
                res -= mul(++p);
        }
    
        return res;
    }

int evaluate(const string& expr) {
    const char * p = expr.c_str();
    return Add( p );
}

// This works too. Use the 2-stack algorithm. Has error checking.
class Solution {
public:

bool getNum(const char * &s, int &num) {
    num = 0;
    if (*s < '0' || *s > '9') return false;
    
    while (*s >= '0' && *s <= '9') {
        num = num * 10 + (*s - '0');
        ++ s;
    }
    return true;
}

bool getOp(const char * &s, char &op) {
    if (*s == '*' || *s == '+' || *s == '-') {
        op = *s;
        ++ s;
        return true;
    }
    return false;
}

int evaluate(const string& expr) {
    stack<int> sn;
    stack<char> sop;
    
    const char * s = expr.c_str();
    int num;
    char op;
    
    if (! getNum(s, num)) return num; 
    sn.push(num);
    
    while (*s) {
        if (!getOp(s, op)) break;
        sop.push(op);
        
        if (!getNum(s, num)) return 0; // error
        
        if (sop.top() == '*') {
            sn.top() *= num;
            sop.pop();
        }
        else if (sop.top() == '-') {
            // Note: don't store -, because it'll have complication on a-b-c.
            sn.push(- num);
            sop.pop();
            sop.push('+');
        }
        else {
            sn.push(num);
        }
    }
    
    int tmp = sn.top();
    sn.pop();
    while(!sop.empty()) {
        tmp += sn.top();
        sop.pop();
        sn.pop();
    }
    
    return tmp;
}
};

// This works too. simplified from Solution.
class Solution2 {

int getNum(const char * &s) {
    int num = 0;   
    while (*s >= '0' && *s <= '9') {
        num = num * 10 + (*s ++ - '0');
    }
    return num;
}

int evaluate(const string& expr) {
    stack<int> sn;
    stack<char> sop;
    const char * s = expr.c_str();
          
    sn.push(getNum(s));
    
    while (*s) {
        sop.push(*s ++);
        
        int num = getNum(s);
        
        if (sop.top() == '*') {
            sn.top() *= num;
            sop.pop();
        }
        else if (sop.top() == '-') {
            sn.push(- num);
            sop.pop();
            sop.push('+');
        }
        else {
            sn.push(num);
        }
    }
    
    int tmp = sn.top();
    sn.pop();
    while(!sop.empty()) {
        tmp += sn.top();
        sop.pop();
        sn.pop();
    }
    
    return tmp;
}
};

int main() {
    Solution so;
 
    cout << so.evaluate("1+2") << endl;;
    return 0;
}
