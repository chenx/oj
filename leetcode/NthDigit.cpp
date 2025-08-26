// Works. From https://algo.monster/liteproblems/400
class Solution {
public:
   int findNthDigit(int n) {
       // Define variables:
       // k represents the number of digits in the numbers we're currently looking at
       // digitCount represents the total # of digits for the current k digits wide numbers
       int numDigits = 1;
       long digitCount = 9;

       // Loop to find the range in which n falls
       // 1 * 9 digits for numbers with 1 digit
       // 2 * 90 digits for numbers with 2 digits
       // 3 * 900 digits for numbers with 3 digits and so on.
       while (1ll * numDigits * digitCount < n) {
           n -= numDigits * digitCount;
           ++numDigits;
           digitCount *= 10;
       }

       // Once the correct range is found,
       // calculate the actual number where the nth digit is from
       int number = pow(10, numDigits - 1) + (n - 1) / numDigits;

       // Find the index within the number where the nth digit is located
       int indexInNumber = (n - 1) % numDigits;

       // Convert the number to a string to easily access any digit
       string numberStr = to_string(number);

       // Return the required digit converting it back to int
       return numberStr[indexInNumber] - '0';
   }
};

/**
Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

Example 1:

Input: n = 3
Output: 3

Example 2:

Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, 
             which is part of the number 10.
 */
