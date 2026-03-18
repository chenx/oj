class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)

        openCount = 0
        for i in range(n):
            openCount += 1 if (s[i] == '(' or s[i] == '*') else -1
            if openCount < 0:
                return False
        
        openCount = 0
        for i in range(n-1, -1, -1):
            openCount += 1 if (s[i] == ')' or s[i] == '*') else -1
            if openCount < 0:
                return False
        
        return True


/**
678. Valid Parenthesis String
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "(*)"
Output: true

Example 3:

Input: s = "(*))"
Output: true
 */
