// From: https://leetcode.com/problems/sum-of-square-numbers/editorial/
// Time complexity : O(sqrt(c) * logc).
//
class Solution2 {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; ++ a) {
            double b = sqrt(c - a*a);
            if ((int) b == b) return true;
        }
        return false;
    }
};

// Fermat theorem.
// Time complexity : O(sqrt(c))
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; i++) {
            int count = 0;
            while (c % i == 0) {
                count++;
                c /= i;
            }
            if (i % 4 == 3 && count % 2 != 0) return false;
        }
        return c % 4 != 3;
    }
};

/**
633. Sum of Square Numbers
Medium

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

Input: c = 3
Output: false
 */
