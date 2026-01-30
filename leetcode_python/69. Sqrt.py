class Solution:
    def mySqrt(self, x: int) -> int:
        y = x
        while abs(y * y - x) > 0.00001:
            y = (y + x/y) / 2.0
        return int(y)
      
/*
69. Sqrt(x)
Solved
Easy
Topics
conpanies iconCompanies
Hint

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 */
