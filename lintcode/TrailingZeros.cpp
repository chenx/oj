// This works. And is O(log N) time.
class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        long long ct = 0;
        
        for (; n >= 5; n = n/5) {
            ct += n/5;
        }
        
        return ct;
    }
};

/**
Trailing Zeros

Write an algorithm which computes the number of trailing zeros in n factorial.

E.g.,
11! = 39916800, so the out should be 2

Challenge: O(log N) time.
 */
