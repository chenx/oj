class Solution:
    def longestPalindrome(self, s: str) -> str:
        def getMaxLen(i, j):
            nonlocal maxLen, maxStart
            while i > 0 and j < n-1 and s[i-1] == s[j+1]:
                i -= 1
                j += 1
            
            size = j-i+1
            if maxLen < size:
                maxLen = size
                maxStart = i

        n = len(s)
        maxLen = 0
        maxStart = 0
        for i in range(n):
            getMaxLen(i, i)
            if i < n-1 and s[i] == s[i+1]:
                getMaxLen(i, i+1)
        
        return s[maxStart : maxStart + maxLen]


/**
5. Longest Palindromic Substring
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given a string s, return the longest in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"
 */
