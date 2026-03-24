class Solution:
    def findNthDigit(self, n: int) -> int:
        numDigits = 1
        digitCount = 9

        # Loop to find the range in which n falls
        # 1 * 9 digits for numbers with 1 digit
        # 2 * 90 digits for numbers with 2 digits
        # 3 * 900 digits for numbers with 3 digits and so on.
        while numDigits * digitCount < n:
            n -= numDigits * digitCount
            numDigits += 1
            digitCount *= 10
        
        # Once the correct range is found, 
        # calculate the actual number where the nth digit is from
        number = 10 ** (numDigits - 1) + (n - 1) // numDigits

        # Find the index within the number where the nth digit is located
        indexInNumber = (n - 1) % numDigits

        # Convert the number to a string to easily access any digit
        numberStr = str(number)

        # Return the required digit converting it back to int
        return int(numberStr[indexInNumber])


/**
400. Nth Digit
Solved
Medium
Topics
conpanies iconCompanies

Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

 

Example 1:

Input: n = 3
Output: 3

Example 2:

Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 */
