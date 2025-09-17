// Works. But Solution2 is the best.
class Solution3 {
public:
    int trailingZeroes(int n) {
        int ct = 0;
        for (int i = 5; i <= n; ++ i) {
            int k = i;
            while (k % 5 == 0 && k > 0) {
                ++ ct;
                k /= 5;
            }
        }
        return ct;
    }
};

// Works too. Saved one division than Solution.
class Solution2 {
public:
    int trailingZeroes(int n) {
        int ct = 0;
        while (n > 0) {
            n /= 5;
            ct += n;
        }
        return ct;
    }
};

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
