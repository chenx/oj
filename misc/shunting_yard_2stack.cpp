#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int getNum(const char * &s) {
    int num = 0;   
    while (*s >= '0' && *s <= '9') {
        num = num * 10 + (*s ++ - '0');
    }
    return num;
}

int prec(char c) {
    if (c == '(' || c == ')') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    // else, error.
    return -1;
}

double calc(double a, double b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') {
        if (abs(b) < 0.0000001) return INT_MAX; // error
        else return a / b;
    }
    else if (op == '^') return pow(a, b);
    else return INT_MAX; // error
}

void dump(stack<double> s) { 
    while (s.size() > 0) { cout << s.top() << " "; s.pop(); }
    cout << endl;
}
void dump(stack<char> s) { 
    while (s.size() > 0) { cout << s.top() << " "; s.pop(); }
    cout << endl;
}

bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

// note before a 
double eval(string expr) {
    stack<double> s;
    stack<char> sop;
    
    const char * p = expr.c_str();
    
    while (*p == '(') sop.push(*p ++);
    s.push(getNum(p));
    
    while (*p) {
        while (is_op(*p)) sop.push(*p ++); // <-- needs tweak.
        if (*p) s.push(getNum(p)); 
        
        while (1) {
            char op = sop.top();
            sop.pop();
            //cout << "op: " << op << endl; dump(s); dump(sop); cout << endl;
            
            if (sop.empty()) { sop.push(op); break; }
            else if (sop.top() == '(' && op == ')') { sop.pop(); }
            else if (prec(op) > prec(sop.top())) {
                double b = s.top(); s.pop();
                double a = s.top(); s.pop();
                s.push( calc(a, b, op) );
            }
            else {
                sop.push(op);
                break;
            }
        }
    }
    
    while (! sop.empty()) {
        double b = s.top(); s.pop();
        double a = s.top(); s.pop();
        char op = sop.top(); sop.pop();
        double v = calc(a, b, op);
        s.push(v);
    }
    //dump(s); dump(sop); cout << endl;
    
    return s.top();
}

void test(string s, double v) {
    double a = eval(s);    
    cout << s << " = " << eval(s) << (a == v ? " .....ok" : " .....errrrrr") << endl;
}

int main() {
    test("1", 1);
    test("1+2", 3);
    test("1+2*3", 7);
    test("1+3/2", 2.5);
    test("1+2*(3+4)", 15);
    test("1+2*(3+4)/2", 8);
    test("1+2*(3+4)/2*3", 22);
    test("1+2*(3+4)/2*3/10", 3.1);
    test("1+2*(3+4)/2*3/10+(5-6)", 2.1);
    test("1+2*(3+4)/2*3/10+(5-6)*(4-3)", 2.1);
    return 0;
}
