class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> num2;
        while (k > 0) {
            num2.insert(num2.begin(), k % 10);
            k /= 10;
        }
        
        vector<int> result;
        int carry = 0, sum = 0, i = num.size() - 1, j = num2.size() - 1;
        for (; i >= 0 && j >= 0; -- i, -- j) {
            getSum(num[i] + num2[j] + carry, sum, carry);
            result.insert(result.begin(), sum);
        }
        for (; i >= 0; -- i) {
            getSum(num[i] + carry, sum, carry);
            result.insert(result.begin(), sum);
        }
        for (; j >= 0; -- j) {
            getSum(num2[j] + carry, sum, carry);
            result.insert(result.begin(), sum);
        }
        if (carry > 0) {
            result.insert(result.begin(), carry);
        }

        return result;
    }

    void getSum(int val, int& sum, int& carry) {
        if (val >= 10) {
            sum = val - 10;
            carry = 1;
        } else {
            sum = val;
            carry = 0;
        }
    }
};


/**
989. Add to Array-Form of Integer
Easy

The array-form of an integer num is an array representing its digits in left to right order.

    For example, for num = 1321, the array form is [1,3,2,1].

Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

 

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455

Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
 */
