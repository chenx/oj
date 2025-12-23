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

// Works. Tested.
class Solution4 {
public:
    double myPow(double x, long long n) {
        bool neg = n < 0;
        if (neg) n = -n;
        
        double R = 1, F = x;
        while (n > 0) {
            if (n & 1) R *= F;
            F *= F;
            n >>= 1;
        }
        
        if (neg) R = 1 / R;
        return R;
    }
    
};

// Works. Tested.
// Note previous solutions failed for e.g.: n = INT_MIN, x = 2.0. -n overflows.
// Only change is to convert "int n" to "long long m".
class Solution3 {
public:
    double myPow(double x, int n) {
        long long m = n;
        bool neg = (m < 0);
        if (neg) m = -m;
        
        double R = 1, F = x;
        
        while (m > 0) {
            if (m & 1) R *= F;
            F *= F;
            m >>= 1;
        }
        
        if (neg) R = 1/R;
        return R;
    }
};    
    
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

// This works too, and is probably better.
// Note: cannot use: if (n < 0) return 1 / myPow(x, -n);
// If do want to use it, change function signature to: pow(double x, long long n)
class Solution2 {
public:
    double pow(double x, int n) {
        if (n == 0) return abs(x) < 0.000001 ? 0 : 1;
        bool neg = n < 0;
        if (neg) n = -n;
        
        double R = 1.0, F = x;
        while (n > 0) {
            if (n & 1) R *= F;
            n = n >> 1; // n >>= 1;
            if (n == 0) break;
            F *= F;
        }
        
        return neg ? 1 / R : R;
    }
};

/**
Pow(x, n)
Difficulty: Medium

Implement pow(x, n). 
 */
