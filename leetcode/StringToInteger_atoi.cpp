//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/1/2013
// @Last modified: 1/1/2013
//
class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL || strlen(str) == 0) return 0;
        
        while (*str == ' ' || *str == '\t' || *str == '\n') ++ str;
        
        int sign = 1;
        if (*str == '+' || *str == '-') {
            if (*str == '-') sign = -1;
            ++ str;
        }
        
        if (! isDigit(*str)) return 0;
        
        int val = *str - '0', val0;
        while(1) {
            ++ str;
            if (! isDigit(*str)) break;
            
            val0 = val * 10 + (*str - '0');
            
            if (val0 / 10 != val) { // overflow, 
                // Note this includes the case INT_MIN.
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            val = val0;
        }
                
        return sign * val;
    }
    
    bool isDigit(const char c) {
        return c >= '0' && c <= '9';
    }
};

// This works too. Slightly better than Solution.
class Solution2 {
public:
    int atoi(const char *str) {
        if (! str || ! *str) return 0;
        
        while (*str == ' ' || *str == '\t' || *str == '\n') ++ str;
        
        int sign = 1;
        if (*str == '+') ++ str;
        else if (*str == '-') {
            sign = -1;
            ++ str;
        }
            
        int y0 = 0, y;
        while( isDigit(*str) ) {
            y = y0 * 10 + (*str - '0');
            
            if (y / 10 != y0) { // overflow, 
                // Note this includes the case INT_MIN.
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            y0 = y;
            ++ str;
        }
                
        return sign * y0;
    }
    
    bool isDigit(const char c) {
        return c >= '0' && c <= '9';
    }
};

// This works too.
class Solution3 {
public:
    int myAtoi(string str) {
        int v = 0, v0, i = 0;
        bool neg = false;
        
        if (str == "") return 0;
        while (str[i] == ' ') ++ i;

        if (str[i] == '-') {
            neg = true; 
            ++ i;
        }
        else if (str[i] == '+') {
            ++ i;
        }
        
        if (i == str.length() || ! isDigit(str[i])) return 0;
        
        for (int n = str.length(); i < n && isDigit(str[i]); ++ i) {
            v0 = v;
            v = v * 10 + (str[i] - '0');
            if (v0 != v/10) return neg ? INT_MIN : INT_MAX;
        }
        
        if (neg) v = -v;
        
        return v;
    }
    
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
};

/*
Problem:
        
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given 
input specs). You are responsible to gather all the input requirements up front.

Requirements for atoi:

The function first discards as many whitespace characters as necessary 
until the first non-whitespace character is found. Then, starting from 
this character, takes an optional initial plus or minus sign followed 
by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the 
integral number, which are ignored and have no effect on the behavior of 
this function.

If the first sequence of non-whitespace characters in str is not a valid 
integral number, or if no such sequence exists because either str is empty 
or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If 
the correct value is out of the range of representable values, 
INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

 */
