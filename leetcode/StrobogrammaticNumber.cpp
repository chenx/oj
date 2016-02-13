// Works. Tested. By: XC.
class Solution {
public:
    bool isStrobogrammatic(string num) {
        int L = 0, R = num.length() - 1;
        
        for (; L <= R; ++ L, -- R) {
            if (! ((num[L] == '0' && num[R] == '0') ||
                   (num[L] == '1' && num[R] == '1') ||
                   (num[L] == '8' && num[R] == '8') ||
                   (num[L] == '6' && num[R] == '9') ||
                   (num[L] == '9' && num[R] == '6'))
               ) return false;
        }
        return true;
    }
};

/**
Strobogrammatic Number
Difficulty: Easy

A strobogrammatic number is a number that looks the same when 
rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. 
The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
 */
