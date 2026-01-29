class Solution:
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
 */
