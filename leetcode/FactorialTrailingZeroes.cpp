
//
// This works.
//
class Solution {
public:
    int trailingZeroes(int n) {
        int v = 0;
        
        while (n > 0) {
            v += n/5;
            n = n/5;
        }
        
        return v;
    }
};

/**
Factorial Trailing Zeroes 
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
 */
