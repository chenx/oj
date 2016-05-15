// Modified from Solution2. This is easier to understand.
class Solution3 {
public:
    int addDigits(int num) {
        if (num <= 9) return num;
        num %= 9;
        if (num == 0) num = 9;
        return num;
    }
};

// This works too.
// For number that from 0 to 9, the answer is themselves.
// For number that is divisible by 9, the answer is 9.
// Otherwise, the answer is the reminder after divided by 9.
// From: https://leetcode.com/discuss/80037/java-one-line-simple-answer
class Solution2 {
public:
    int addDigits(int num) {
        return num > 9 ? (num % 9 == 0 ? 9 : num % 9) : num;
    }
};


class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};


/**
Add Digits
Difficulty: Easy

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hint:

    A naive implementation of the above process is trivial. Could you come up with other methods?
    What are all the possible results?
    How do they occur, periodically or randomly?
    You may find this Wikipedia article useful.

 */
