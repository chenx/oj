// From: https://leetcode.com/discuss/61269/0ms-8-lines-c-solution
class Solution {
public:
    int countDigitOne(int n) {
        if(n<1)return 0;
        long ones=0;
        for(long m=1;m<=n;m*=10){
            long a=n/m;
            long b=n%m;
            ones += (a+8)/10*m+(a%10==1)*(b+1);
        }
        return ones;
    }
};

/**
Number of Digit One
Difficulty: Medium

Given an integer n, count the total number of digit 1 appearing in 
all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 
1, 10, 11, 12, 13.

Hint:

    Beware of overflow.

 */
