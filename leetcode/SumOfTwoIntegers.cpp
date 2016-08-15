class Solution {
public:
    int getSum(int a, int b) {  // getSum(sum, carry)
        if (a && b) return getSum(a^b, (a&b) << 1);
        else return a|b;
    }
};


/**
371. Sum of Two Integers    Difficulty: Easy

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3. 
*/
