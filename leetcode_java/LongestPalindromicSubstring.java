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
