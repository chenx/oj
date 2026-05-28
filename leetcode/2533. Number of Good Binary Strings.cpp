// From: https://algo.monster/liteproblems/2533
// Time complexity is O(n), where n = maxLength
// Space complexity is O(n), where n = maxLength
class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        const int MOD = 1000000007;

        // dp[i] is the number of ways to form a good string of length i
        vector<int> dp(maxLength + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= maxLength; ++i) {
            // If we can append a group of ones to reach current length
            if (i - oneGroup >= 0) {
                dp[i] = (dp[i] + dp[i - oneGroup]) % MOD;
            }

            // If we can append a group of zeros to reach current length
            if (i - zeroGroup >= 0) {
                dp[i] = (dp[i] + dp[i - zeroGroup]) % MOD;
            }
        }

        int count = 0;
        for (int i = minLength; i <= maxLength; ++i) {
            count = (count + dp[i]) % MOD;
        }

        return count;
    }
};


/**
2533. Number of Good Binary Strings
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given four integers minLength, maxLength, oneGroup and zeroGroup.

A binary string is good if it satisfies the following conditions:

    The length of the string is in the range [minLength, maxLength].
    The size of each block of consecutive 1's is a multiple of oneGroup.
        For example in a binary string 00110111100 sizes of each block of consecutive ones are [2,4].
    The size of each block of consecutive 0's is a multiple of zeroGroup.
        For example, in a binary string 00110111100 sizes of each block of consecutive zeros are [2,1,2].

Return the number of good binary strings. Since the answer may be too large, return it modulo 109 + 7.

Note that 0 is considered a multiple of all the numbers.

 

Example 1:

Input: minLength = 2, maxLength = 3, oneGroup = 1, zeroGroup = 2
Output: 5
Explanation: There are 5 good binary strings in this example: "00", "11", "001", "100", and "111".
It can be proven that there are only 5 good strings satisfying all conditions.

Example 2:

Input: minLength = 4, maxLength = 4, oneGroup = 4, zeroGroup = 3
Output: 1
Explanation: There is only 1 good binary string in this example: "1111".
It can be proven that there is only 1 good string satisfying all conditions.
 */
