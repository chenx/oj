#include <string>
#include <iostream>
using namespace std;

/*
bool is_num(const char c) {
    return c >= '0' && c <= '9';
}

bool num(const char*& p) {
    while (isspace(*p)) ++ p; // this allows space to be skipped.
    
    if (*p == '0') {
        ++ p;
        return ! is_num(*p);
    }
    else if (*p >= '1' && *p <= '9') {
        while (*p >= '0' && *p <= '9') ++ p;
        return true;
    }
    else {
        return false;
    }
}

bool expr(const char * &p, int &p_level) {
    if (*p == '\0' && p_level == 0) return true;
    
    cout << p << endl;
    
    if (*p == '(') {
        if (! expr(++p, ++p_level)) return false;
        if (*p == ')') {
            ++ p;
            -- p_level;
            return true;
        }
        else { return false; }
    }
    else if (is_num(*p)) {
        if (! num(p)) return false;
        if (*p == '+' || *p == '-') {
            ++ p;
            if (! expr(p, p_level)) return false;
            return true;
        }
        //else 
        if (p_level > 0 && *p == ')') return true;
        return *p == '\0'; 
        //return false; //true;
    }
    else {
        return false;
    }
}
*/

/*
bool num(const char*& p) {
    while (isspace(*p)) ++ p; // this allows space to be skipped.
    int v;
    if (*p == '0') {
        ++ p;
        v = 0;
        cout << v;
        return ! is_num(*p);
    }
    else if (*p >= '1' && *p <= '9') {
        v = 0;
        while (*p >= '0' && *p <= '9') { v = v*10 + (*p - '0'); ++ p; }
        cout << v;
        return true;
    }
    else {
         cout << "...";
        return false;
    }
}

void expr(const char * &p, int &p_level) {
//    if (*p == '\0' && p_level == 0) return true;
    
    if (*p == '(') {
        cout << "[";
        expr(++p, ++p_level);
        if (*p == ')') {
            cout << "]";
            ++ p;
            -- p_level;
        }

        if (*p == '+' || *p == '-') {
            cout << *p;
            ++ p;
            expr(p, p_level);
        }        
    }
    else if (is_num(*p)) {
        num(p);
        if (*p == '+' || *p == '-') {
            cout << *p;
            ++ p;
            expr(p, p_level);
        }
    }
    else {

    }
}

int calc(const string & exp) {
    const char * p = exp.c_str();
    int p_level = 0;
    expr(p, p_level);
}


bool num(const char*& p) {
    while (isspace(*p)) ++ p; // this allows space to be skipped.
    int v;
    if (*p == '0') {
        ++ p;
        v = 0;
        //cout << v;
        return ! is_num(*p);
    }
    else if (*p >= '1' && *p <= '9') {
        v = 0;
        while (*p >= '0' && *p <= '9') { v = v*10 + (*p - '0'); ++ p; }
        //cout << v;
        return true;
    }
    else {
        return false;
    }
}

void expr(const char * &p, int &p_level) {
    if (*p == '(') {
        //cout << "[";
        expr(++p, ++p_level);
        if (*p == ')') {
            //cout << "]";
            ++ p;
            -- p_level;
        }

        if (*p == '+' || *p == '-') {
            //cout << *p;
            ++ p;
            expr(p, p_level);
        }        
    }
    else if (is_num(*p)) {
        num(p);
        if (*p == '+' || *p == '-') {
            //cout << *p;
            ++ p;
            expr(p, p_level);
        }
    }
}
*/

// Code below works.
// Author: X.C. 11/07/2013

bool is_num(const char c) {
    return c >= '0' && c <= '9';
}

int num(const char*& p) {
    while (isspace(*p)) ++ p; // this allows space to be skipped.
    int v;
    if (*p == '0') {
        ++ p;
        v = 0;
    }
    else if (*p >= '1' && *p <= '9') {
        v = 0;
        while (*p >= '0' && *p <= '9') { v = v*10 + (*p - '0'); ++ p; }
    }
    cout << v;
    return v;
}

int E(const char *& p);

int F(const char *& p) {
    if (*p == '(') {
        cout << "[";
        ++ p;
        int v = E(p);
        if (*p == ')') { ++ p; cout << "]"; }
        return v;
    }
    else if (is_num(*p)) {
        return num(p);
    }
    return 0;
}

int E(const char *& p) {
    int v = F(p);
    //cout << ":" << v << endl;
    
    while (*p == '+' || *p == '-') {
        int sign = (*p == '+') ? 1 : -1;
        cout << *p;
        ++ p;
        v += sign * E(p);
        //cout << ":" << v << endl;
    }
    return v;
}

// E: F +/- E | F
// F: (E) | n
// n: 0 | [1-9][0-9]*
void calc(const string& expr) {
    int len = expr.size();
    const char * p = expr.c_str();
    int v = E(p);
    if (*p == '\0') {
        cout << "\nvalue = " << v << endl;
    }
    else {
        cout << "\nwrong expression" << endl;
    }
}

int main() {
    string exp =  "(((1)-(2))+3+(4-50)+60)"; //"(1)+((2)-3)";
    //exp = "1+(2+(3+4)+5)+6";
    //string exp = "(1)+2";
    cout << "input: " << exp << endl;
    calc(exp);
    //calc(exp);
    return 0;
}
