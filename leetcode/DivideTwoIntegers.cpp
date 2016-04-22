//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/9/2013
//

// Works. 
// Seems this solved the ambiguous issue.
// The only case that overflows is: INT_MIN / -1.
class Solution5 {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        long long a = dividend, b = divisor;
        bool neg = (a < 0) ^ (b < 0);
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        
        int d = 0;
        while ((b << d) <= a) ++ d;
        
        int q = 0;
        for (-- d; d >= 0; -- d) {
            long long tmp = b << d;
            if (a >= tmp) {
                a -= tmp;
                q += 1 << d;
            }
        }
        
        if (neg) q = -q;
        return q;
    }
};


// Has similar ambiguous issue of Solution3.
class Solution4 {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return 0;
        
        long long a = dividend, b = divisor;
        
        bool neg = (a > 0 && b < 0) || (a < 0 && b > 0);
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        
        int d = 0;
        while (b << d <= a) ++ d;
        -- d;
        
        long long q = 0;
        for (; d >= 0; -- d) {
            long long tmp = b << d;
            if (tmp <= a) {
                a -= tmp;
                q += 1 << d;
            }
        }
        
        q = neg ? -q : q;
        if (q == INT_MIN) q = INT_MAX; // overflow.

        return q;
    }
};

//
// What is different from solution1 and solution2 is the handling of overflow:
// input: -2147483648, -1
// expected: 2147483648, but this overflowed, so return 2147483647.
// This is leetcode's recent change. However there is issue with this:
// If input is (2147483647, 1), then expected output is 2147483647, so
// there is no way to tell this apart from the overflow case.
//
class Solution3 {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; // overflow        
        
        long long a = dividend;
        long long b = divisor;
        bool neg = (a > 0 && b < 0) || (a < 0 && b > 0);
        
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        
        int d = 0;
        while ((b << d) <= a) ++ d;
        -- d;
        
        int q = 0;
        for (; d >= 0; -- d) {
            long long tmp = b << d;
            if (tmp <= a) {
                a -= tmp;
                q += 1 << d;
            }
        }
        
        if (neg) q = -q; 

        return q;
    }
};

// Adapted from Solution1. This works.
class Solution2 {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return 0;

        long long a = dividend;
        long long b = divisor;
                
        // ask for a/b.
        bool neg = (a > 0 && b < 0) || (a < 0 && b > 0);
        
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        
        int d = 0; // Note: d is initialized to 0.
        while ((b << d) <= a) ++ d; // Note: use <=, not <
        -- d; // min val d, s.t., b^d > a.
        
        int q = 0; // quotient. Note: q is initialized to 0.
        
        for (; d >= 0; -- d) {
            long long tmp = (b << d); // Note: tmp is long long type.
            if (tmp <= a) {           // Note: use <=, not <
                q += 1 << d;  // Note: q |= 1 << i; i.e., somthing like: q += ...,8,4,2,1. '+=' ok too.
                a -= tmp;
            }
        }
        
        return neg ? - q : q;
    }
};


// This works!
// From: http://www.mitbbs.com/article_t/JobHunting/32099545.html
// Also see: http://blog.csdn.net/maqingli87/article/details/7980026
class Solution1 {
public:
    int divide(int dividend, int divisor) // return c=a/b;
    {
        long long a = dividend;
        long long b = divisor;

        if (b == 0) return 0;

        bool neg = false;
        if (a < 0) neg = !neg;
        if (b < 0) neg = !neg;

        a = abs(a);
        b = abs(b);

        int d = 0;
        while (b << d <= a)  ++ d;

        int c = 0;

        for (int i = d; i >= 0; i--) {
            if (b << i <= a) {
                c |= 1 << i; 
                a -= b << i;
            }
        }

        return (neg) ? -c : c;
    }    
};

// Solution 2: use bit operation, but I don't understand yet:
// http://blog.unieagle.net/2012/09/17/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Adivide-two-integers/

// Solution 3: using log: a/b = exp(log(a) - log(b));
// See: http://tianrunhe.wordpress.com/2012/07/14/division-without-using-or-divide-two-integers/

/*
Problem:

 Divide two integers without using multiplication, division and mod operator.
 */



//
// Multiply 2 integers m, n in log(n) time.
//
// @Author: Xin Chen
// @Created on: 4/7/2013
// @Last modified: 4/7/2013
//
#include <iostream>
using namespace std;

int mul(int m, int n) {
    if (n < 0) m = -m;

    int R = 0, F = m;

    while (n > 0) {
        if (n & 1) R += F;
        F += F;
        n >>= 1;
    }

    return R;
}

int main() {
    int m = 6, n = 5;
    cout << "mul(" << m << ", " << n << ") = " << mul(m, n) << endl;
    return 0;
}

