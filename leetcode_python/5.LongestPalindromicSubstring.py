class Solution:
    def longestPalindrome(self, s: str) -> str:
        def getMaxLen(s, i, j):
            while i > 0 and j < self.n - 1 and s[i-1] == s[j+1]:
                i -= 1
                j += 1
            
            len = j - i + 1
            if len > self.maxLen:
                self.startIndex = i
                self.maxLen = j - i + 1

        self.n = len(s)
        self.maxLen = 0
        self.startIndex = 0

        for i in range(self.n):
            getMaxLen(s, i, i)
            if i > 0 and s[i-1] == s[i]:
                getMaxLen(s, i-1, i)
        
        return s[self.startIndex : self.startIndex + self.maxLen]

/**
5. Longest Palindromic Substring
Medium

Given a string s, return the longest in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"
 */
