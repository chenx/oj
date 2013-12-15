//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/26/2012
// @Last modified: 12/26/2012
//
//
// Fast exponentiation, similar to Fibonacci. O(log(n)).
// Note: 1) be careful of n >>= 1 is not n >> 1, 2) consider n < 0.
//
class Solution {
public:
    double pow(double x, int n) {
        double R = 1, F = x;
        int neg = 0;
        if (n < 0) {
            neg = 1;
            n = - n;
        }
        while (n > 0) {
            if (n & 1) R *= F;
            n >>= 1; // don't confuse with n >> 1, which does not change n.
            if (n == 0) break;
            F = F * F;
        }
        
        return neg ? 1/R : R;
    }
};
