// DP
// From: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/editorial/
// Let m,n be the number of rows and columns of coins.
// Time complexity: O(mn).
// Space complexity: O(n).
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins[0].size();
        vector dp(n + 1, vector<int>(3, INT_MIN / 2));

        for (int i = 0; i < 3; i++) {
            dp[1][i] = 0;
        }
        for (auto& row : coins) {
            for (int j = 1; j <= n; j++) {
                int x = row[j - 1];
                dp[j][2] = max(
                    {dp[j - 1][2] + x, dp[j][2] + x, dp[j - 1][1], dp[j][1]});
                dp[j][1] = max(
                    {dp[j - 1][1] + x, dp[j][1] + x, dp[j - 1][0], dp[j][0]});
                dp[j][0] = max(dp[j - 1][0], dp[j][0]) + x;
            }
        }

        return dp[n][2];
    }
};


/**
3418. Maximum Amount of Money Robot Can Earn
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to 
reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point 
in time.

The grid contains a value coins[i][j] in each cell:

    If coins[i][j] >= 0, the robot gains that many coins.
    If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of 
coins[i][j] coins.

The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing 
them from stealing coins in those cells.

Note: The robot's total coins can be negative.

Return the maximum profit the robot can gain on the route.

 

Example 1:

Input: coins = [[0,1,-1],[1,-2,3],[2,-3,4]]

Output: 8
 */
