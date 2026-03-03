class Solution:
    def longestValidParentheses(self, s: str) -> int:
        def getMaxLen(isOpen):
            nonlocal maxLen, openCount, totalCount
            openCount += 1 if isOpen else -1
            totalCount += 1
            
            if openCount == 0:
                maxLen = max(maxLen, totalCount)
            elif openCount < 0:
                totalCount = 0
                openCount = 0


        maxLen, openCount, totalCount = 0, 0, 0
        for ch in s:
            getMaxLen(ch == '(')
        
        openCount, totalCount = 0, 0
        for ch in s[::-1]:
            getMaxLen(ch == ')')

        return maxLen

        

/**
32. Longest Valid Parentheses
Solved
Hard
Topics
conpanies iconCompanies

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses .

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:

Input: s = ""
Output: 0
 */
