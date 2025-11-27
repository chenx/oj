// See: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/editorial/
// Time: O(m + n)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0, j = n-1;

        for (int i = 0; i < m; ++ i) {
            for (; j >= 0 && grid[i][j] < 0; -- j) ;
            count += n - 1 - j;
        }
        return count;
    }
};


/**
1351. Count Negative Numbers in a Sorted Matrix
Easy

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, 
return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
 */
