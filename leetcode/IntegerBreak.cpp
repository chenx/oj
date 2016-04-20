// Works. log(n) solution.
//
// 1) A factor >= 4 is not needed. 
//    If there is a factor f >= 4, then 2 * (f - 2) = 2f - 4 > f.
// 2) There can be at most two 2s. If there are three or more 2s,
//    then 2 + 2 + 2 = 3 + 3, and 2 * 2 * 2 < 3 * 3, so we can 
//    always convert three 2s into two 3s.
//
// See:
// https://leetcode.com/discuss/98285/c-easy-to-understand-solution
// https://leetcode.com/discuss/98173/o-log-n-time-solution-with-explanation
// https://leetcode.com/discuss/98276/why-factor-2-or-3-the-math-behind-this-problem
//
class Solution2 {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n % 3 == 0) return pow(3, n/3);
        if (n % 3 == 1) return pow(3, (n-4)/3) * 4;
        else return pow(3, (n-2)/3) * 2; // or: pow(3, n/3) * 2; // n % 3 == 2.
    }
};


// Works. DP. O(n^2)
// See: https://leetcode.com/discuss/98352/easy-understand-o-n-2-dp-solution
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; ++i){
            for(int j = 1; j < i; ++j){
                dp[i] = max (dp[i], max(dp[j],j)* max(dp[i - j], i-j));
            }
        }   

        return dp[n];  
    }
};

/**
Integer Break  
Difficulty: Medium

Given a positive integer n, break it into the sum of at least 
two positive integers and maximize the product of those integers. 
Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, 
return 36 (10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.

Hint:

    There is a simple O(n) solution to this problem.
    You may check the breaking results of n ranging from 7 to 10 
    to discover the regularities.

 */
