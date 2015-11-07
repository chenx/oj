public class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length, carry = 1;
        
        for (int i = len - 1; i >= 0; -- i) {
            digits[i] += carry;
            if (digits[i] >= 10) {
                digits[i] -= 10;
                carry = 1;
            }
            else {
                return digits;
            }
        }
        
        int[] digits2 = new int[len + 1];
        digits2[0] = 1;
        for (int i = 0; i < len; ++ i) {
            digits2[i + 1] = digits[i];
        }
        return digits2;
    }
}


/**
Plus One
Difficulty: Easy

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
 */
