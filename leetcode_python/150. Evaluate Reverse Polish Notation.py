class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack : list[int] = []

        for token in tokens:
            if token in ['+', '-', '*', '/']:
                val = stack[-1]
                stack.pop()

                a = stack[-1]

                if token == '+': stack[-1] += val
                elif token == '-': stack[-1] -= val
                elif token == '*': stack[-1] *= val
                elif token == '/': stack[-1] = int(stack[-1] / val)
                # elif token == '/': stack[-1] //= val. # -6 / 127 = -1
                # print(f"{a} {token} {val} = {stack[-1]}")
            else:
                stack.append(int(token))
        
        return stack[-1]

/**
150. Evaluate Reverse Polish Notation
Solved
Medium
Topics
conpanies iconCompanies

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.

 */
