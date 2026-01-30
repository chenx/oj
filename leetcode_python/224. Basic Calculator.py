# E = F + F | F - F
# F = T * T | T / T
# T = num | ( E ) | - T
class Solution:
    # def __init__(self):
    #     self.pos = 0

    def calculate(self, s: str) -> int:
        def E(s):
            val = F(s)
            while self.pos < len(s) and s[self.pos] in ['+', '-']:
                if s[self.pos] == '+':
                    self.pos += 1
                    val += F(s)
                elif s[self.pos] == '-':
                    self.pos += 1
                    val -= F(s)
            return val
        
        def F(s):
            val = T(s)
            while self.pos < len(s) and s[self.pos] in ['*', '/']:
                if s[self.pos] == '*':
                    self.pos += 1
                    val *= T(s)
                elif s[self.pos] == '/':
                    self.pos += 1
                    val = int(val / T(s))
            return val
        
        def T(s):
            val = 0
            ignoreSpace(s)

            if s[self.pos].isdigit():
                val = getNum(s)
            elif s[self.pos] == '(':
                self.pos += 1
                val = E(s)
                self.pos += 1 # ignore ')'
            elif s[self.pos] == '-':
                self.pos += 1
                val = - T(s)
            
            ignoreSpace(s)
            return val
        
        def getNum(s):
            val = 0
            while self.pos < len(s) and s[self.pos].isdigit():
                val = val * 10 + int(s[self.pos])
                self.pos += 1
            return val

        def ignoreSpace(s):
            while self.pos < len(s) and s[self.pos].isspace():
                self.pos += 1
        
        self.pos = 0
        return E(s)
        

/**
224. Basic Calculator
Solved
Hard
Topics
conpanies iconCompanies

Given a string s representing a valid expression, implement a basic calculator to evaluate it, 
and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical 
expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2

Example 2:

Input: s = " 2-1 + 2 "
Output: 3

Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 */
