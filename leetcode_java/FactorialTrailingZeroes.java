/**
 * x = 1 + Math.floor(n/5) + Math.floor(n/5^2) + ...
 */
public class Solution {
    public int trailingZeroes(int n) {
        int x = 0;
        while (n > 0) {
            x += n/5;
            n /= 5;
        }
        
        return x;
    }
}

/**
Factorial Trailing Zeroes
Difficulty: Easy

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
 */
