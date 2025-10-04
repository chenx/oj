class Solution2 {
    int maxLen = 0, start = 0;
    
    public String longestPalindrome(String s) {
        int len = s.length();
        
        for (int i = 0; i < len; ++ i) {
            getVal(s, i, i);
            if (i < len-1 && s.charAt(i) == s.charAt(i+1)) {
                getVal(s, i, i+1);
            }
        }
        return s.substring(start, start + maxLen); // substring(start, end)
    }
    
    void getVal(String s, int L, int R) {
        while (L > 0 && R < s.length() - 1) {
            if (s.charAt(L-1) != s.charAt(R+1)) break;
            -- L;
            ++ R;
        }
        int len = R - L + 1;
        if (len > maxLen) {
            maxLen = len;
            start = L;
        }
    }
}

public class Solution {
    public String longestPalindrome(String s) {
        int n = s.length(), v;
        if (n <= 1) return s;
        L = R = maxLen = 0;
        
        for (int i = 0; i < n-1; ++ i) {
            getMaxLen(s, n, i, i);
            if (s.charAt(i) == s.charAt(i+1)) {
                getMaxLen(s, n, i, i + 1);
            }
        }
        
        return s.substring(L, R + 1); // note substring(start, end), end exclusive.
    }
    
    private void getMaxLen(String s, int n, int a, int b) {
        int len = b - a + 1;
        for (-- a, ++ b; 
             a >= 0 && b < n && s.charAt(a) == s.charAt(b); -- a, ++ b) {
            len += 2;
        }
        
        if (len > maxLen) {
            L = a + 1; R = b - 1;
            maxLen = len;        
        }
    }
    
    private int L, R, maxLen;
}

/**
Longest Palindromic Substring
Difficulty: Medium

Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there 
exists one unique longest palindromic substring.
 */
