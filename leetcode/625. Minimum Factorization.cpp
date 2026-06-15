// See: https://leetcode.com/problems/minimum-factorization/editorial/
class Solution {
public:
    int smallestFactorization(int num) {
        if (num < 2) return num;
        long long res = 0, mul = 1;
        for (int i = 9; i >= 2; i--) {
            while (num % i == 0) {
                num /= i;
                res = mul * i + res;
                mul *= 10;
            }
        }
        return num < 2 && res <= INT_MAX ? (int) res : 0;
    }
};

/**
625. Minimum Factorization
Solved
Medium
Topics
conpanies iconCompanies

Given a positive integer num, return the smallest positive integer x whose multiplication of 
each digit equals num. If there is no answer or the answer is not fit in 32-bit signed integer, return 0.

 

Example 1:

Input: num = 48
Output: 68

Example 2:

Input: num = 15
Output: 35
 */
