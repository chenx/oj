class Solution {
public:
    string toHex(int num) {
        string v[] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};

        unsigned int n = num;
        bool neg = (n < 0);
        if (neg) n = ~(-n) + 1; // 1's complement of number x: ~x

        string hex;
        while (n > 0) {
            hex = v[n % 16] + hex;
            n /= 16;
        }
        if (hex.empty()) hex = "0";

        return hex;
    }
};

/**
405. Convert a number to hexadecimal.

Given a 32-bit integer num, return a string representing its hexadecimal representation. 
For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, and there should not 
be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.

Example 1:

Input: num = 26
Output: "1a"

Example 2:

Input: num = -1
Output: "ffffffff"
 */
