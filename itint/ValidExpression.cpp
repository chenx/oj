#include <string>
#include <iostream>
using namespace std;

// Code below works.
// Author: X.C. 11/07/2013

bool is_num(const char c) {
    return c >= '0' && c <= '9';
}

bool num(const char*& p) {
    //while (isspace(*p)) ++ p; // this allows space to be skipped.
    if (*p == '0') {
        ++ p;
        return ! is_num(*p);
    }
    else if (*p >= '1' && *p <= '9') {
        while (*p >= '0' && *p <= '9') { ++ p; }
        return true;
    }
    return false;
}

bool E(const char *& p);

bool F(const char *& p) {
    if (*p == '(') {
        ++ p;
        if (! E(p)) return false;
        if (*p == ')') { ++ p; return true; }
        else return false;
    }
    else if (is_num(*p)) {
        return num(p);
    }
    return false;
}

bool E(const char *& p) {
    if (! F(p)) return false;
    
    while (*p == '+' || *p == '-') {
        ++ p;
        if (! E(p)) return false;
    }
    return true;
}

// E: F +/- E | F
// F: (E) | n
// n: 0 | [1-9][0-9]*
bool validate(const string& expr) {
    int len = expr.size();
    const char * p = expr.c_str();
    return E(p) && *p == '\0';
}

int main() {
    string exp =  "(((1)-(2))+3+(4-50)+60)"; //"(1)+((2)-3)";
    exp = "1+(2+(3+4)+5)+6";
    //string exp = "(1)+2";
    cout << "input: " << exp << endl;
    cout << validate(exp);
    //calc(exp);
    return 0;
}
