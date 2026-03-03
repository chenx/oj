# Most pythonic way to reverse a string: s[::-1]
class Solution4:
    def minRemoveToMakeValid(self, s: str) -> str:
        def removeExtraRightPar(s, open, close):
            balance = 0
            t = ''
            for ch in s:
                if ch == open:
                    balance += 1
                elif ch == close:
                    if balance == 0:
                        continue
                    balance -= 1
                t += ch
            return t
        
        t = removeExtraRightPar(s, '(', ')')
        t = removeExtraRightPar(t[::-1], ')', '(')
        return t[::-1]


class Solution3:
    def minRemoveToMakeValid(self, s: str) -> str:
        balance = 0
        t = []
        for ch in s:
            if ch == '(':
                balance += 1
            elif ch == ')':
                if balance == 0:
                    continue
                balance -= 1
            t.append(ch)
        
        balance = 0
        result = []
        for i in range(len(t)-1, -1, -1):
            ch = t[i]
            if ch == ')':
                balance += 1
            elif ch == '(':
                if balance == 0:
                    continue
                balance -= 1
            result.append(ch)
                
        return ''.join(reversed(result))


class Solution2:
    def minRemoveToMakeValid(self, s: str) -> str:
        def removeExtraRightParenthesis(s: list[str], open, close):
            balance = 0
            t = []
            for ch in s:
                if ch == open:
                    balance += 1
                elif ch == close:
                    if balance == 0:
                        continue
                    balance -= 1
                t.append(ch)
            return t

        t = removeExtraRightParenthesis(list(s), '(', ')')
        t.reverse()
        t = removeExtraRightParenthesis(t, ')', '(')
        t.reverse()
        
        return ''.join(t)
        

class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        openCount, balance = 0, 0

        t = ''
        for ch in s:
            if ch == '(':
                openCount += 1
                balance += 1
            elif ch == ')':
                if balance == 0:
                    continue
                balance -= 1
            t += ch
        
        openToKeep = openCount - balance
        result = ''
        for ch in t:
            if ch == '(':
                if openToKeep == 0:
                    continue
                openToKeep -= 1
            result += ch
        
        return result


/**
1249. Minimum Remove to Make Valid Parentheses
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that 
the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

    It is the empty string, contains only lowercase characters, or
    It can be written as AB (A concatenated with B), where A and B are valid strings, or
    It can be written as (A), where A is a valid string.

 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
 */
