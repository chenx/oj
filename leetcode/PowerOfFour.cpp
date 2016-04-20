// Works too.
// "num > 0 && (num & (num - 1)) == 0" guarantees it is 2's power,
// thus in the format of 10....0
// num & 0x55555555 = num & 0b01010101010101010101010101010101, so
// 1 of num can only in position 0, 3, 5, ... thus is 4's power.
// See: https://leetcode.com/discuss/98410/c-one-line-bit-manipulation-solution-with-explanation
class Solution2 {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555);
    }
};

// Works.
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) return false;
        while (num % 4 == 0) num /= 4;
        return num == 1;
    }
};

/**
Power of Four  
Difficulty: Easy

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion? 
 */
