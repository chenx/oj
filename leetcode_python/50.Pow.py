class Solution:
    def myPow(self, x: float, n: int) -> float:
        neg = n < 0
        if neg:
            n = -n

        R = 1
        F = x

        while n > 0:
            if n & 1 == 1:
                R *= F
            F *= F
            n >>= 1

        return 1 / R if neg else R

/**
50. Pow(x, n)
Solved
Medium
Topics
conpanies iconCompanies

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
 */
