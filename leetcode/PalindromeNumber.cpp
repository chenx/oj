//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//
class Solution {
public:
    // Note: negative number is considered NOT palindrome.
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false; // x = -x;
        int r = rev(x);
        if (r == -1) return false;
        return r == x;
    }
    
    int rev(int x) {
        int r = 0, r0;
        while (x) {
            r0 = r;
            r = r * 10 + x % 10;
            if (r / 10 != r0) return -1; // overflowed
            x = x / 10;
        }
        return r;
    }
};


// This works too.
class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int y, y0 = 0, x0 = x;
        
        while(x) {
            y = y0 * 10 + x % 10;
            if (y/10 != y0) return false; // overflowed
            y0 = y;
            x /= 10;
        }
        
        return y0 == x0;
    }
};

/*
Problem:

Determine whether an integer is a palindrome. Do this without extra space.
 */