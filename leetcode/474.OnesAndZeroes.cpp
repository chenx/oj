// Dynamic Programming
// From: https://leetcode.com/problems/ones-and-zeroes/editorial/
// Time complexity : O(l∗m∗n). Three nested loops are their, where l is the length of strs, m and n are the number of zeroes and ones respectively.
// Space complexity : O(m∗n). dp array of size m∗n is used.
//
class Solution2 {
public:
    int findMaxForm(vector<string> strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string s : strs) {
            vector<int> count = countzeroesones(s);
            for (int zeroes = m; zeroes >= count[0]; -- zeroes)
                for (int ones = n; ones >= count[1]; -- ones)
                    dp[zeroes][ones] = max(
                        1 + dp[zeroes - count[0]][ones - count[1]], dp[zeroes][ones]);
        }
        return dp[m][n];
    }

    vector<int> countzeroesones(string& s) {
        vector<int> c(2);
        for (int i = 0; i < s.length(); i++) {
            c[s[i] - '0']++;
        }
        return c;
    }
};


// From: https://leetcode.com/problems/ones-and-zeroes/editorial/
// Time complexity : O(l∗m∗n). memo array of size l∗m∗n is filled, where l is the length of strs, m and n are the number of zeroes and ones respectively.
// Space complexity : O(l∗m∗n). 3D array memo is used.
//
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> 
            memo(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        return calculate(strs, 0, m, n, memo);
    }

    int calculate(vector<string>& strs, int i, int zeroes, int ones, 
                  vector<vector<vector<int>>>& memo) {
        if (i == strs.size()) return 0;

        if (memo[i][zeroes][ones] != 0) return memo[i][zeroes][ones];

        auto count = countzeroesones(strs[i]);
        int taken = -1; // whether strs[i] is taken / used.
        if (zeroes - count[0] >= 0 && ones - count[1] >= 0)
            taken = calculate(strs, i + 1, zeroes - count[0], ones - count[1], memo) + 1;
        int not_taken = calculate(strs, i + 1, zeroes, ones, memo);
        memo[i][zeroes][ones] = max(taken, not_taken);
        return memo[i][zeroes][ones];
    }

    vector<int> countzeroesones(string& s) {
        vector<int> c(2);
        for (int i = 0; i < s.length(); ++ i) {
            ++ c[s[i]-'0'];
        }
        return c;
    }
};

/**
474. Ones and Zeroes
Medium

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

 

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
 */
