class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(result, digits, s, pos):
            if pos == len(digits):
                result.append(s)
                return
            
            digit = digits[pos]
            for ch in self.pad[int(digit)]:
                dfs(result, digits, s + ch, pos + 1)

        self.pad = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        result = []
        s = ""
        dfs(result, digits, s, 0)
        return result

/**
17. Letter Combinations of a Phone Number
Solved
Medium
Topics
conpanies iconCompanies

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that 
the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does 
not map to any letters.
 */
