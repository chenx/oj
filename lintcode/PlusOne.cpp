class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;  // start with 1.
        for (int i = digits.size() - 1; i >= 0; -- i) {
            digits[i] += carry;
            if (digits[i] >= 10) {
                digits[i] -= 10;
                carry = 1;
            }
            else {
                carry = 0;
                break;
            }
        }
        
        if (carry == 1) digits.insert(digits.begin(), 1);
            
        return digits;
    }
};


/**
Plus One

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
Have you met this question in a real interview?
Example

Given [1,2,3] which represents 123, return [1,2,4].

Given [9,9,9] which represents 999, return [1,0,0,0].

 */
