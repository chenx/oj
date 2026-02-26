class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 0
        for i in range(len(digits) - 1, -1, -1):
            digits[i] += 1
            if digits[i] >= 10:
                digits[i] -= 10
                carry = 1
            else:
                carry = 0
                break
        
        if carry == 1:
            digits.insert(0, 1)
        return digits

/**
66. Plus One
Solved
Easy
Topics
conpanies iconCompanies

You are given a large integer represented as an integer array digits, where each digits[i] is the 
ith digit of the integer. The digits are ordered from most significant to least significant in 
left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

 

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
 */
