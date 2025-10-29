class Solution {
    int carry, sum;
    StringBuilder sb;

    public String addStrings(String num1, String num2) {
        sb = new StringBuilder();

        carry = 0; sum = 0;
        int i = num1.length() - 1, j = num2.length() - 1;
        for (; i >= 0 && j >= 0; -- i, -- j) {
            // add(Character.getNumericValue(num1.charAt(i)) + Character.getNumericValue(num2.charAt(j)) + carry);
            add(num1.charAt(i) - '0' + num2.charAt(j) - '0' + carry);
        }
        for (; i >= 0; -- i) {
            add(Character.getNumericValue(num1.charAt(i)) + carry);
        }
        for (; j >= 0; -- j) {
            add(Character.getNumericValue(num2.charAt(j)) + carry);
        }
        if (carry > 0) {
            add(carry);
        }

        return sb.toString();
    }

    private void add(int sum) {
        carry = 0;
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        }
        sb.insert(0, String.valueOf(sum));
    }
}

/**
415. Add Strings
Easy

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). 
You must also not convert the inputs to integers directly.
 */
