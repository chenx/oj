//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//

// This works too. 10/26/2014
class Solution2 {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        
        int a = 1, b = 1;
        for (int i = 2; i <= n; ++ i) {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
    
    // This works too, and most simple.
    int climbStairs2(int n) {
        if (n <= 1) return 1;
        
        int a = 1, b = 1;
        for (int i = 2; i <= n; ++ i) {
            b = a + b;
            a = b - a;
        }
        return b;
    }    
};

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) return 1;
        if (n == 2) return 2;
        
        int f1 = 1;
        int f2 = 2;
        int f;
        for (int i = 3; i <= n; i ++) {
            f = f1 + f2; // f1, f2, f
            f1 = f2;
            f2 = f;
        }
        
        return f;
    }
};
