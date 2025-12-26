// From: https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/editorial/
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        map<int, vector<int>> hatsToPeople;

        for (int i = 0; i < n; i++) {
            for (int hat: hats[i]) {
                hatsToPeople[hat].push_back(i);
            }
        }
        
        int done = (int) pow(2, n) - 1;
        int MOD = 1000000007;
        
        vector<vector<int>> dp(42, vector<int>(done + 1, 0));
        for (int i = 0; i < dp.size(); i++) {
            dp[i][done] = 1;
        }
        
        for (int hat = 40; hat > 0; hat--) {
            for (int mask = done; mask >= 0; mask--) {
                int ans = dp[hat + 1][mask];
                if (hatsToPeople.contains(hat)) {
                    for (int person: hatsToPeople[hat]) {
                        if ((mask & (1 << person)) == 0) {
                            ans = (ans + dp[hat + 1][mask | (1 << person)]) % MOD;
                        }
                    }
                }
                
                dp[hat][mask] = ans;
            }
        }

        return dp[1][0];
    }
};


/**
1434. Number of Ways to Wear Different Hats to Each Other
Hard

There are n people and 40 types of hats labeled from 1 to 40.

Given a 2D integer array hats, where hats[i] is a list of all hats preferred by the ith person.

Return the number of ways that n people can wear different hats from each other.

Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: hats = [[3,4],[4,5],[5]]
Output: 1
Explanation: There is only one way to choose hats given the conditions. 
First person choose hat 3, Second person choose hat 4 and last one hat 5.
 */
