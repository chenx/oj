//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//

class Solution {
public:
    int reverse(int x) {
        return (x < 0) ? - rev(-x) : rev(x);        
    }
    
    int rev(int x) {
        int r = 0, r0;
        while (x) {
            r0 = r;
            r = r * 10 + x % 10;
            if (r / 10 != r0) return INT_MAX; // overflowed
            x = x / 10;
        }
        return r;
    }


    // This works too, don't consider about overflow.
    int reverse_v2(int x) {
        int neg = (x < 0) ? -1 : 1;        
        x = x * neg;
        
        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        
        return y * neg;
    }

};
