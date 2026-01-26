class Solution:
    def addBinary(self, a: str, b: str) -> str:
        def add(sum):
            if sum >= 2:
                sum -= 2
                self.carry = 1
            else:
                self.carry = 0
            self.result = str(sum) + self.result
    
        if a == "" or a == "0": return b
        if b == "" or b == "0": return a

        self.result = ""
        self.carry = 0
        lena, lenb = len(a) - 1, len(b) - 1
        while lena >= 0 and lenb >= 0:
            add(int(a[lena]) + int(b[lenb]) + self.carry)
            lena -= 1
            lenb -= 1
        while lena >= 0:
            add(int(a[lena]) + self.carry)
            lena -= 1
        while lenb >= 0:
            add(int(b[lenb]) + self.carry)
            lenb -= 1
        if self.carry > 0:
            add(self.carry)

        return self.result

/**
67. Add Binary
Easy

Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 */
