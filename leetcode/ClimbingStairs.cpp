//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//
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
