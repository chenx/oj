//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/27/2012
// @Last modified: 1/2/2013
//
// State machine: An acceptor.
#include <iostream>
using namespace std;

// Number := [ ]*(+|-)Real(e(+|-)[\d]+)[ ]*
// Real := [\d]+[\.][\d]+ or [\d]+[\.] or [\.][\d]+

// Works. Among best so far.
class Solution7 {
public:
    bool isNumber(string s) {
        // +-(d+.d+|d+.|.d+) e+-(d+)
        const char * p = s.c_str();
        while (isspace(*p)) ++ p;
        
        if (*p == '+' || *p == '-') ++ p;
        if (isdigit(*p)) {  // d+(.(d+))
            while (isdigit(*p)) ++ p;
            if (*p == '.') {
                ++ p;
                while (isdigit(*p)) ++ p;
            }
        } else if (*p == '.') {  // .(d+)
            ++ p;
            if (! isdigit(*p)) return false;
            while (isdigit(*p)) ++ p;
        } else {
            return false;
        }
        
        if (*p == 'e') {
            ++ p;
            if (*p == '+' || *p == '-') ++ p;
            if (! isdigit(*p)) return false;
            while (isdigit(*p)) ++ p;
        }
        
        while (isspace(*p)) ++ p;
        return ! *p;  // Or: return *p == '\0';
    }
};

class Solution {
public:
    bool isNumber(const char *s) {
        if (s == NULL) return false;
        
        while (*s && *s == ' ') { s ++; } // remove front spaces.
        return state0(s);
    }
    
    inline bool isDigit(const char *s) {
        return *s >= '0' && *s <= '9';
    }
    
    bool state0(const char * s) {
        if (*s == '+' || *s == '-') return state1(s + 1);
        return state1(s);
    }
    
    bool state1(const char * s) {
        if (isDigit(s)) return state2(s + 1);
        if (*s == '.') return state11(s + 1);
        if (*s == ' ') return state5(s + 1);
        return false;
    }
    
    bool state11(const char * s) {
        if (isDigit(s)) return state3(s + 1);
        return false;
    }
    
    bool state2(const char * s) {
        if (*s == 0) return true;
        if (isDigit(s)) return state2(s + 1);
        if (*s == '.') return state3(s + 1);
        if (*s == 'e') return state4(s + 1);
        if (*s == ' ') return state5(s + 1);
        return false;
    }
        
    bool state3(const char * s) {
        if (*s == 0) return true;
        if (isDigit(s)) return state3(s + 1);
        if (*s == 'e') return state4(s + 1);
        if (*s == ' ') return state5(s + 1);
        return false;
    }
    
    // after e, must be integer.
    bool state4(const char * s) {
        if (*s == '+' || *s == '-') return state41(s + 1);
        return state41(s);
    }
    
    bool state41(const char * s) {
        if (isDigit(s)) return state42(s + 1);
        return false;
    }
    
    bool state42(const char * s) {
        if (*s == 0) return true;
        if (isDigit(s)) return state42(s + 1);
        if (*s == ' ') return state5(s + 1);
        return false;
    }
    
    bool state5(const char * s) {
        if (*s == 0) return true;
        if (*s == ' ') return state5(s + 1);
        return false;
    }
};

// This works too. Is iterative version.
// Directly translated from Solution. 
// Can be further optimized by removing some states.
// Note: 1) must use if-else if-else, 2) must use break.
class Solution2 {
public:
    bool isNumber(const char *s) {
        if (s == NULL) return false;

        while (*s && *s == ' ') { s ++; } // remove front spaces.
        
        int state = 0;
        while(1) {
            switch(state) {
                case 0:
                    if (*s == '+' || *s == '-') s ++;
                    state = 1;
                    break;
                case 1:
                    if (isDigit(s)) { s ++ ; state = 2; }
                    else if (*s == '.') { s ++; state = 11; }
                    else if (*s == ' ') { s ++; state = 5; }
                    else return false;
                    break;
                case 11:
                    if (isDigit(s)) { s ++; state = 3; }
                    else return false;
                    break;
                case 2:
                    if (*s == 0) return true;
                    else if (isDigit(s)) { s ++; state = 2; }
                    else if (*s == '.') { s ++; state = 3; }
                    else if (*s == 'e') { s ++; state = 4; }
                    else if (*s == ' ') { s ++; state = 5; }
                    else return false;
                    break;
                case 3:
                    if (*s == 0) return true;
                    else if (isDigit(s)) { s ++; state = 3; }
                    else if (*s == 'e') { s ++; state = 4; }
                    else if (*s == ' ') { s ++; state = 5; }
                    else return false;
                    break;
                case 4:
                    if (*s == '+' || *s == '-') s ++;
                    state = 41;
                    break;
                case 41:
                    if (isDigit(s)) { s ++; state = 42; }
                    else return false;
                    break;
                case 42:
                    if (*s == 0) return true;
                    else if (isDigit(s)) { s ++; state = 42; }
                    else if (*s == ' ') { s ++; state = 5; }
                    else return false;
                    break;
                case 5:
                    if (*s == 0) return true;
                    else if (*s == ' ') { s ++; state = 5; }
                    else return false;
                    break;
            }
        }
    }
    
    inline bool isDigit(const char *s) {
        return *s >= '0' && *s <= '9';
    }
};

// This works too, is state machine approach.
// 6 symbol types: 
// +-, digit, ., e, ' ', '\0'
// 9 states, state no.: 
// 1) if negative, don't do ++s; 
// 2) else if positive, do ++s.
// 3) 0 - return false, 
// 4) INT_MAX - accept/return true.
class Solution3 {
public:
public:
    bool isNumber(const char *s) {
        if (s == NULL) return false;

        while (*s && *s == ' ') { s ++; } // remove front spaces.
        
        int T[9][7] = {                  // Transition table of state machine.
            {1, -1, -1, -1, -1, -1, 0},  // state 0
            {0, 3, 2, 0, 8, 0, 0},       // state 1
            {0, 4, 0, 0, 0, 0, 0},       // state 11
            {0, 3, 4, 5, 8, INT_MAX, 0}, // state 2
            {0, 4, 0, 5, 8, INT_MAX, 0}, // satte 3
            {6, -6, -6, -6, -6, -6, 0},  // satte 4
            {0, 7, 0, 0, 0, 0, 0},       // satte 41
            {0, 7, 0, 0, 8, INT_MAX, 0}, // satte 42
            {0, 0, 0, 0, 8, INT_MAX, 0}  // satte 5
        };
        
        int state = 0;
        int new_state;
        while(1) {
            new_state = T[state][ getSymbolIndex(*s) ];
            if (new_state == 0)  {
                return false;
            } 
            else if (new_state == INT_MAX) { 
                return true; 
            }
            else if (new_state > 0) {
                ++ s;
                state = new_state;
            }
            else { // new_state < 0
                state = - new_state;
            }
        }
    }
    
    int getSymbolIndex(const char c) {
        if (c == '+' || c == '-') return 0;
        else if (c >= '0' && c <= '9') return 1;
        else if (c == '.') return 2;
        else if (c == 'e') return 3;
        else if (c == ' ') return 4;
        else if (c == '\0') return 5;
        else return 6; // error.
    }
    
            /*
            switch(state) {
        0        case 0:
                    if (*s == '+' || *s == '-') s ++;
                    state = 1;
                    break;
        1        case 1:
                    if (isDigit(s)) { s ++ ; state = 2; }
                    else if (*s == '.') { s ++; state = 11; }
                    else if (*s == ' ') { s ++; state = 5; }
                    else return false;
                    break;
        2        case 11:
                    if (isDigit(s)) { s ++; state = 3; }
                    else return false;
                    break;
        3        case 2:
                    if (*s == 0) return true;
                    else if (isDigit(s)) { s ++; state = 2; }
                    else if (*s == '.') { s ++; state = 3; }
                    else if (*s == 'e') { s ++; state = 4; }
                    else if (*s == ' ') { s ++; state = 5; }
                    else return false;
                    break;
        4        case 3:
                    if (*s == 0) return true;
                    else if (isDigit(s)) { s ++; state = 3; }
                    else if (*s == 'e') { s ++; state = 4; }
                    else if (*s == ' ') { s ++; state = 5; }
                    else return false;
                    break;
        5        case 4:
                    if (*s == '+' || *s == '-') s ++;
                    state = 41;
                    break;
        6        case 41:
                    if (isDigit(s)) { s ++; state = 42; }
                    else return false;
                    break;
        7        case 42:
                    if (*s == 0) return true;
                    else if (isDigit(s)) { s ++; state = 42; }
                    else if (*s == ' ') { s ++; state = 5; }
                    else return false;
                    break;
        8        case 5:
                    if (*s == 0) return true;
                    else if (*s == ' ') { s ++; state = 5; }
                    else return false;
                    break;
                    
            }*/
};

//
// This works too. Use brutal force method.
//
class Solution4 {
public:
    bool isNumber(const char *s) {
        while (isspace(*s)) ++ s;
        if (*s == '+' || *s == '-') ++ s;
        //while (isspace(*s)) ++ s; // leetcode does not allow space here.
        
        if (*s == '.') { // something like: .3
            ++ s;
            if (! isdigit(*s)) return false;
            while (isdigit(*s)) ++ s;
        }
        else { // e.g.: 5, 3., or 3.1
            if (! isdigit(*s)) return false;
            // leetcode considers this valid.
            //if (*s == '0' && isdigit(*(s+1))) return false; // 0 cannot be followed by another digit.
            
            while (isdigit(*s)) ++ s;
            if (*s == '.') {
                ++ s;
                while (isdigit(*s)) ++ s;
            }
        }
        //while (isspace(*s)) ++ s; // leetcode does not allow space here.
        
        if (*s == 'e') {
            ++ s;
            if (*s == '+' || *s == '-') ++ s;
            if (! isdigit(*s)) return false;
            while(isdigit(*s)) ++ s;
        }
        
        while (isspace(*s)) ++ s;
        return *s == '\0';
    }
    
    bool isspace(char c) {
        if (c == ' ' || c == '\t' || c == '\b') return true;
        return false;
    }
    
    bool isdigit(char c) {
        if (c >= '0' && c <= '9') return true;
        return false;
    }

    // note: can use this to ignore space.
    void ignore_space(const char *& s) {
        while (isspace(*s)) ++ s;
    }
};

// This works too.
class Solution5 {
public:
    bool isNumber(string s) {
        int p = 0, len = s.length();
        
        while (isspace(s[p])) ++ p;
        if (p == len) return false;
        
        if (s[p] == '-' || s[p] == '+') ++ p;
        
        if (isdigit(s[p])) {
            while (isdigit(s[p])) { ++ p; }
            if (s[p] == '.') ++ p;
            while (isdigit(s[p])) { ++ p; }
        }
        else if (s[p] == '.') {
            ++ p;
            if (! isdigit(s[p])) return false;
            while (isdigit(s[p])) { ++ p; }
        }
        else { return false; }
        
        if (s[p] == 'e') {
            ++ p;
            if (s[p] == '+' || s[p] == '-') ++ p;
            if (! isdigit(s[p])) return false;
            while (isdigit(s[p])) { ++ p; }
        }
        
        while (isspace(s[p])) ++ p;
        return p == len;
    }
    
    bool isdigit(char c) {
        return c >= '0' && c <= '9';
    }
};

// Works. May be best so far.
class Solution6 {
public:
    bool isNumber(string s) {
        // +-(d+.d+|d+.|.d+)e+-(d+)
        
        int n = s.length(), i = 0;
        
        while (i < n && isspace(s[i])) ++ i;
        if (i == n) return false;
        
        if (s[i] == '+' || s[i] == '-') ++ i;
        if (i == n) return false;
        
        if (isdigit(s[i])) {
            while (i < n && isdigit(s[i])) ++ i;
            //if (i == n) return true; //
            
            if (s[i] == '.') {
                ++ i;
                while (i < n && isdigit(s[i])) ++ i;
                //if (i == n) return true; //
            }
        }
        else if (s[i] == '.') {
            ++ i;
            if (i == n || ! isdigit(s[i])) return false;
            while (i < n && isdigit(s[i])) ++ i;
            //if (i == n) return true; //
        }
        else {
            return false;
        }
        
        if (i < n && s[i] == 'e') {
            ++ i;
            if (i == n) return false;
            if (s[i] == '+' || s[i] == '-') ++ i;
            if (i == n || ! isdigit(s[i])) return false;
            while (isdigit(s[i])) ++ i;
        }
        
        while (i < n && isspace(s[i])) ++ i;
        return i == n;
    }
};


int main() {
    return 0;
}

/*
Problem:

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one. 

Note 2: format of leetcode: (+|-)num(exp), num: [.][d]+ or [d]+([.]([d]+)), exp: e(+|-)[d]+
Here "()" means the enclosed part happens 0 or 1 time. There can be space before or after, but not in between.
 */

