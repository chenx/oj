class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;

        int carry = 0;
        int i = num1.length() - 1, j = num2.length() - 1;
        for (; i >= 0 && j >= 0; -- i, -- j) {
            add(result, num1[i] - '0' + num2[j] - '0' + carry, carry);
        }
        for (; i >= 0; -- i) {
            add(result, num1[i] - '0' + carry, carry);
        }
        for (; j >= 0; -- j) {
            add(result, num2[j] - '0' + carry, carry);
        }
        if (carry > 0) {
            add(result, carry, carry);
        }

        return result;
    }

    void add(string& result, int sum, int& carry) {
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result = (char)('0' + sum) + result;
    }
};


/**
415. Add Strings
Easy

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 */
