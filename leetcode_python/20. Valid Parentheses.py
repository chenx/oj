class Solution:
    def isValid(self, s: str) -> bool:
        map = {'(' : ')', '[' : ']', '{' : '}'}
        stack = []

        for ch in list(s):
            if ch in ['(', '[', '{']:
                stack.append(map[ch])
            elif ch in [')', ']', '}']:
                if len(stack) == 0 or stack[-1] != ch:
                    return False
                stack.pop()
        
        return len(stack) == 0

/**
20. Valid Parentheses
Solved
Easy
Topics
conpanies iconCompanies
Hint

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true
 */
