class Solution3:
    def convert(self, s: str, numRows: int) -> str:
        rows = ["" for _ in range(numRows)]

        row = 0
        i = 0
        n = len(s)
        while i < n:
            for row in range(numRows):
                if i == n: break
                rows[row] += s[i]
                i += 1
            for row in range(numRows-2, 0, -1): 
                if i == n: break
                rows[row] += s[i]
                i += 1

        return "".join(rows)


class Solution2:
    def convert(self, s: str, numRows: int) -> str:
        rows = [''] * numRows
        k = 0
        n = len(s)
        while k < n:
            j = 0
            while j < numRows and k < n:
                rows[j] += s[k]
                k += 1
                j += 1
            
            j = numRows - 2
            while j >= 1 and k < n:
                rows[j] += s[k]
                k += 1
                j -= 1

        return "".join(rows)


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        rows = [''] * numRows
        k = 0
        n = len(s)
        while k < n:
            for j in range(numRows):
                rows[j] += s[k]
                k += 1
                if k == n:
                    break
            if k == n:
                break
            for j in range(numRows - 2, 0, -1):
                rows[j] += s[k]
                k += 1
                if k == n:
                    break
        return "".join(rows)


/**
6. Zigzag Conversion
Solved
Medium
Topics
conpanies iconCompanies

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
 */
