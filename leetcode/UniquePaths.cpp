//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 1/21/2013
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        int i, j;
        int a[m][n];
        for (j = 0; j < n; j ++) { a[0][j] = 1; }
        
        for (i = 1; i < m; i ++) {
            a[i][0] = 1;
            for (j = 1; j < n; j ++) {
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        
        return a[m - 1][n - 1];
    }
};

/*
Problem:

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
 */

// This is the case of can only go by the upper right half of the square.
// The answer is Catalan number: http://en.wikipedia.org/wiki/Catalan_number
class CatalanNum {
public:
    int uniquePaths(int n) {
        int i, j;

        int a[n][n];
        for (j = 0; j < n; j ++) { a[0][j] = 1; }
        
        for (i = 1; i < n; i ++) {
            a[i][i-1] = 0;
            for (j = i; j < n; j ++) {
                a[i][j] = a[i-1][j] + a[i][j-1];
            }
        }
        
        return a[n - 1][n - 1];
    }
};