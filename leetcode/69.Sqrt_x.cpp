//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/18/2012
//

// Binary search.
class Solution3 {
public:
    int mySqrt(int x) {
        double left = 0, right = x;
        while (right - left > 0.000001) {
            double mid = (left + right) / 2;
            if (mid * mid <= x) left = mid;
            else right = mid;
        }
        return right;
    }
};

// Works too. Best.
class Solution2 {
public:
    int mySqrt(int x) {
        double y = x;
        while (y * y - x > 0.00001) {
            y = (y + x/y) / 2.0;
        }
        return y;
    }
};

class Solution {
public:
    // Newton-Ralphson's method: x' = (x + c/x) / 2. Better!
    int sqrt(int x) {
        double y = x;
        while(abs(y * y - x) > 0.000001) {
            y = (y + x/y)/2;
        }
        return y;
    }
    
    // bi-section method, must handle x = 1 separately, otherwise it rounds down to 0.
    int sqrt2(int x) { // assume x > 0.
        if (x == 1) return 1;
        double left = 0, right = x;
        double mid, diff;
        
        while(1) {
            mid = (left + right) / 2.0;
            diff = mid * mid - x;
            if (abs(diff) < 0.000001) break;
            
            if (diff > 0) { right = mid; }
            else if (diff < 0) { left = mid; }
        }
        
        return (mid);
    }

    // better newton-ralphson method.
    int n(int x) {
        double a0 = 0, a = x;
        
        while (abs(a - a0) > 0.00001) {
            a0 = a;
            a = (a0 + x/a0) / 2.0;
        }
        
        return (int) a;
    }
    
    // better bisection method.
    int b(int x) {
        double left = 0, right = x, m;
        
        while (right - left > 0.00001) {
            m = (left + right) / 2.0;
            if (m*m - x > 0) right = m;
            else left = m;
        }
        
        return right;
    }

};


