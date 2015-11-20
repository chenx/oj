//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/20/2012
// @Last modified: 1/20/2013
//

/*
 * Note: 
 * 1) change string abc to #a#b#c#, at each position, search toward two sides.
 * 2) can't use: t += s[i] + "#";
 * This is O(n^2).
 * For O(n) solution, see http://www.akalin.cx/longest-palindrome-linear-time
 */

#include <iostream>
#include <string>
using namespace std;

// This works too. 11/18/2015
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), v;
        if (n <= 1) return s;
        L = R = maxLen = 0;
        
        for (int i = 0; i < n-1; ++ i) {
            getMaxLen(s, n, i, i);
            if (s[i] == s[i+1]) {
                getMaxLen(s, n, i, i + 1);
            }
        }
        
        return s.substr(L, R - L + 1); // note substring(start, end), end exclusive.
    }

private:    
    void getMaxLen(string s, int n, int a, int b) {
        int len = b - a + 1;
        for (-- a, ++ b; 
             a >= 0 && b < n && s[a] == s[b]; -- a, ++ b) {
            len += 2;
        }
        
        if (len > maxLen) {
            L = a + 1; R = b - 1;
            maxLen = len;        
        }
    }
    
    int L, R, maxLen; 
};

// This works too. Seems most clean. 11/7/2014
class Solution3 {
public:
    string longestPalindrome(string s) {
       int len = s.length();
       if (len == 0) return "";
       
       int mlen = 1; // max palindrome length.
       int mL = 0;   // start position (L) of max palindrome.
       
       for (int i = 0; i < len; ++ i) {
           check(s, i, i, mlen, mL);
           check(s, i, i+1, mlen, mL);
       }
       
       return s.substr(mL, mlen);
    }
    
    void check(string &s, int L, int R, int &mlen, int &mL) {
        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            -- L; ++ R;
        }
        ++ L; -- R;
        if (R - L + 1 > mlen) {
            mlen = R - L + 1;
            mL = L;
        }
    }
};

// This works too.
class Solution2 {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) return s;
        
        int len, L0, maxlen = 0;
        for (int i = 0; i <= n-2; ++ i) {
            len = findP(s, i, i);
            if (len > maxlen) {
                maxlen = len, L0 = i - (len-1)/2;
            }
            
            if (s[i] == s[i+1]) {
                len = findP(s, i, i+1);
                if (len > maxlen) {
                    maxlen = len, L0 = i - (len-2)/2; // Note: +1!
                }
            }
        }
        
        return s.substr(L0, maxlen);
    }
    
    // return length of palindrome, L/R is the range.
    int findP(string &s, int L, int R) {
        int n = R - L + 1, len = s.length() - 1;
        while (L > 0 && R < len) {
            if (s[-- L] != s[++ R]) break;
            n += 2;
        }
        
        return n;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return "";
        
        string p = "";
        string t = "#"; // assume # does not exist in s.
        int i, j;
        for (i = 0; i < s.length(); i ++) {
            t += s[i];
            t += "#";
        }
        
        int p_len = 0, p_pos;
        for (i = 1; i < t.length() - 1; i ++) {
            // search 2 sides from center t[i].
            for (j = 1; i - j >= 0 && i + j <= t.length() - 1; j ++) {
                if (t[i - j] != t[i + j]) break;
            }
            // length of palingdrome: 2*(j-1) + 1
            if (p_len < j - 1) {
                p_len = j - 1;
                p_pos = i;
            }
        }
        
        // Note: be care for of the offset here.
        if (p_pos % 2 == 1) p_pos = (p_pos - 1) / 2; 
        else p_pos = (p_pos) / 2; 
        
        p = s.substr(p_pos - p_len / 2, p_len);
        
        return p;
    }
};

int main() {
    Solution s;
    string x = "bb";
    cout << s.longestPalindrome(x) << endl;
    return 0;
}
