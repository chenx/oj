// From: https://leetcode.com/problems/increment-submatrices-by-one/editorial/
//
// 2D Difference + Prefix Sum
//   mat[i][j]=diff[i][j]+mat[i−1][j]+mat[i][j−1]−mat[i−1][j−1]
// Time complexity: O(n2).
// Space complexity: O(n2).
//
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector diff(n + 1, vector<int>(n + 1));
        for (const auto& query : queries) {
            int row1 = query[0], col1 = query[1];
            int row2 = query[2], col2 = query[3];
            diff[row1][col1] += 1;
            diff[row2 + 1][col1] -= 1;
            diff[row1][col2 + 1] -= 1;
            diff[row2 + 1][col2 + 1] += 1;
        }
        vector mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = (i == 0) ? 0 : mat[i - 1][j];
                int x2 = (j == 0) ? 0 : mat[i][j - 1];
                int x3 = (i == 0 || j == 0) ? 0 : mat[i - 1][j - 1];
                mat[i][j] = diff[i][j] + x1 + x2 - x3;
            }
        }
        return mat;
    }
};


/**
2536. Increment Submatrices by One
Medium

You are given a positive integer n, indicating that we initially have an n x n 0-indexed 
integer matrix mat filled with zeroes.

You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], 
you should do the following operation:

    Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and 
    the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for all 
    row1i <= x <= row2i and col1i <= y <= col2i.

Return the matrix mat after performing every query.
 */
