// From: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/editorial/
// Seems a math problem instead of algorithm problem.
//
// Enumeration.
// __builtin_popcountll is a GCC (GNU Compiler Collection) built-in function used in C and C++ to 
// efficiently count the number of set bits (bits with a value of 1) in an unsigned long long integer. 
// This is also known as the Hamming weight or population count.
//
// Time complexity: O(lognum1​)
// Space complexity: O(1).
//
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        while (true) {
            // long long x = num1 - static_cast<long long>(num2) * k;
            long long x = num1 - (long long) num2 * k;
            if (x < k) return -1;
            if (k >= __builtin_popcountll(x)) return k;
            ++ k;
        }
    }
};


/**
2749. Minimum Operations to Make the Integer Zero
Medium

You are given two integers num1 and num2.

In one operation, you can choose integer i in the range [0, 60] and subtract 2i + num2 from num1.

Return the integer denoting the minimum number of operations needed to make num1 equal to 0.

If it is impossible to make num1 equal to 0, return -1.

 

Example 1:

Input: num1 = 3, num2 = -2
Output: 3
Explanation: We can make 3 equal to 0 with the following operations:
- We choose i = 2 and subtract 22 + (-2) from 3, 3 - (4 + (-2)) = 1.
- We choose i = 2 and subtract 22 + (-2) from 1, 1 - (4 + (-2)) = -1.
- We choose i = 0 and subtract 20 + (-2) from -1, (-1) - (1 + (-2)) = 0.
It can be proven, that 3 is the minimum number of operations that we need to perform.
 */
