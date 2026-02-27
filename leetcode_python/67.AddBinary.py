// From: https://leetcode.com/problems/add-binary/editorial/
// zfill: string.zfill(width)
// '42'.zfill(5)	'00042'	The string is padded with three leading zeros to reach a total width of 5 characters.
// '12345'.zfill(3)	'12345'	The string is already longer than the specified width (3), so it remains unchanged.
// '-42'.zfill(5)	'-0042'	The zeros are added after the negative sign.
// 'abc'.zfill(6)	'000abc'	The method works on non-numeric strings as well.
class Solution4:
    def addBinary(self, a: str, b: str) -> str:
        n = max(len(a), len(b))
        a, b = a.zfill(n), b.zfill(n)

        carry = 0
        answer = []
        for i in range(n - 1, -1, -1):
            if a[i] == "1":
                carry += 1
            if b[i] == "1":
                carry += 1

            if carry % 2 == 1:
                answer.append("1")
            else:
                answer.append("0")

            carry //= 2

        if carry == 1:
            answer.append("1")
        answer.reverse()

        return "".join(answer)


class Solution3:
    def addBinary(self, a: str, b: str) -> str:
        def add(sum):
            nonlocal carry
            if sum >= 2:
                sum -= 2
                carry = 1
            else:
                carry = 0
            result.append(str(sum))
    
        result = []
        carry = 0
        lena, lenb = len(a) - 1, len(b) - 1
        while lena >= 0 and lenb >= 0:
            add(int(a[lena]) + int(b[lenb]) + carry)
            lena -= 1
            lenb -= 1
        while lena >= 0:
            add(int(a[lena]) + carry)
            lena -= 1
        while lenb >= 0:
            add(int(b[lenb]) + carry)
            lenb -= 1
        if carry > 0:
            add(carry)

        result.reverse()
        return "".join(result)

        
class Solution2:
    def addBinary(self, a: str, b: str) -> str:
        def add(sum):
            nonlocal carry, result
            if sum >= 2:
                sum -= 2
                carry = 1
            else:
                carry = 0
            result = str(sum) + result
    
        result = ""
        carry = 0
        lena, lenb = len(a) - 1, len(b) - 1
        while lena >= 0 and lenb >= 0:
            add(int(a[lena]) + int(b[lenb]) + carry)
            lena -= 1
            lenb -= 1
        while lena >= 0:
            add(int(a[lena]) + carry)
            lena -= 1
        while lenb >= 0:
            add(int(b[lenb]) + carry)
            lenb -= 1
        if carry > 0:
            add(carry)

        return result

        
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        def add(sum):
            if sum >= 2:
                sum -= 2
                self.carry = 1
            else:
                self.carry = 0
            self.result = str(sum) + self.result

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
