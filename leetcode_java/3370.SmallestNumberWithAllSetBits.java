// From: https://leetcode.com/problems/smallest-number-with-all-set-bits/editorial/
// O(log(n)) in time.
class Solution {
    public int smallestNumber(int n) {
        int x = 1;
        while (x < n) {
            x = x * 2 + 1;
        }
        return x;
    }
}

class Solution {
    public int smallestNumber(int n) {
        int v = n, count = 0;
        while (n > 0) {
            // if (n % 2 == 0) {
            if ((n & 1) == 0) {  // Need () since & is lower in precedence than ==
                v += (1 << count);
            }
            n >>= 1;
            ++ count;
        }
        return v;
    }
}

/**
3370. Smallest Number With All Set Bits
Easy

You are given a positive number n.

Return the smallest number x greater than or equal to n, such that the binary representation of x contains only 
 */
