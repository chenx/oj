class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def gen(n, left, right, cur):
            if left == n and right == n:
                result.append(cur)
                return

            if left < n:
                gen(n, left + 1, right, cur + '(')
            if left > right:
                gen(n, left, right + 1, cur + ')')

        result = []
        gen(n, 0, 0, "")
        return result


/**
22. Generate Parentheses
Solved
Medium
Topics
conpanies iconCompanies

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]
 */
