//
// Given integer n, return the next palindrome greater than n.
//
// Idea: n: L M R, M can be empty, or one digit number 0-9.
// If rev(L) > R, then let R = rev(L)
// else, L += 1, let R = rev(L)
//
// The first case is easy. For the second case, since we have to change L,
// we change it such that the change is the smallest.
//
// @Author: Xin Chen
// @Created on: 3/21/2013
// @Last modified: 3/21/2013
//
#include <iostream>
using namespace std;

class Solution {
public:
    int rev(int n) {
        int r = 0, r0;
        while (n) {
            r0 = r * 10 + n % 10;
            if (r0 / 10 != r) {
                return 0; // overflowed.
            }
            r = r0;
            n /= 10;
        }
        return r;
    }
    
    int nextPalindrome(int n) {
        int p = n;
        
        int len = 0;
        while (p > 0) {
            p /= 10;
            ++ len;
        }
        
        if (len == 1) return n;
        
        // Get L, M, R
        int L, M, R, base = 1;
        if (len & 1) { // len is odd
            int t = (len - 1) / 2;
            while (t) { 
                base *= 10;
                -- t;
            }
            L = n / (base * 10);
            M = n / base - L * 10;
            R = n % base;
        } else { // len is even.
            int t = len / 2;
            while (t) {
                base *= 10;
                -- t;
            }
            L = n / base;
            M = 0;
            R = n % base;
        }
        
        cout << "L/M/R: " << L << ", " << M << ", " << R << endl;
        
        if (L == R) return n; // n is already a palindrome.
        
        // if rev(L) > R, then R = rev(L)
        // else, L += 1, R = rev(L).
        int r = rev(L);
        if (r < R) {
            L += 1;
            r = rev(L);
        }
        
        R = r;
        
        // reassembly.
        if (len & 1) {
            p = L * base * 10 + M * base + R;
        } else {
            p = L * base + R;
        }
        
        return p;
    }
};

void test(int n) {
    Solution so;
    cout << "next palindrome of " << n << " is " << so.nextPalindrome(n) << endl;
}

int main() {
    test(123320);
    test(1237320);
    test(913320);
    test(9137320);
    
    test(32323);
    test(327723);
    return 0;
}
