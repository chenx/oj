class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        bool neg = (num < 0);
        if (neg) num = -num;
        string s;
        while (num > 0) {
            s = to_string(num % 7) + s;
            num /= 7;
        }
        if (neg) s = "-" + s;
        return s;
    }
};

/**
504. Base 7
Easy

Given an integer num, return a string of its base 7 representation.

 

Example 1:

Input: num = 100
Output: "202"

Example 2:

Input: num = -7
Output: "-10"
 */
