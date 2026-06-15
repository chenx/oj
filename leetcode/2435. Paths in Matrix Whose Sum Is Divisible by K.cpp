// DP
// See: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/editorial/
// Time / Space: O(n * m * k)
typedef long long ll;
const int MOD = 1e9 + 7;

class Solution2 {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        auto dp = vector(m + 1, vector(n + 1, vector<ll>(k)));
        dp[1][1][grid[0][0] % k] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }

                int value = grid[i - 1][j - 1] % k;
                for (int r = 0; r < k; r++) {
                    int prevMod = (r - value + k) % k;
                    dp[i][j][r] =
                        (dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod]) % MOD;
                }
            }
        }

        return dp[m][n][0];
    }
};


// Timesout for large input.
// Time: O( C(n+m, n-1) )
// Space: O(m + n) comes from recursion.
class Solution {
    int m, n;
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        int count = 0;
        dfs(grid, k, 0, 0, 0, count);
        return count;
    }

    void dfs(vector<vector<int>>& grid, int k, int sum, int i, int j, int& count) {
        sum += grid[i][j];
        if (i == m-1 && j == n-1) {
            if (sum % k == 0) {
                count = (count + 1) % 1000000007;
            }
        }

        if (i < m-1) dfs(grid, k, sum, i + 1, j, count);
        if (j < n-1) dfs(grid, k, sum, i, j + 1, count);
    }
};

/**
2435. Paths in Matrix Whose Sum Is Divisible by K
Attempted
Hard
Topics
conpanies iconCompanies
Hint

You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) 
and you want to reach position (m - 1, n - 1) moving only down or right.

Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer 
may be very large, return it modulo 109 + 7.

 

Example 1:

Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
Output: 2
Explanation: There are two paths where the sum of the elements on the path is divisible by k.
The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.

Example 2:

Input: grid = [[0,0]], k = 5
Output: 1
Explanation: The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.

Example 3:

Input: grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
Output: 10
Explanation: Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.
 */
