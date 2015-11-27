public class Solution {
    public int[][] generateMatrix(int n) {
        int[][] v = new int[n][n];
        int k = 0, x = 0, X = n-1, i, j;
        
        while (x <= X) {
            for (i = x, j = x; j <= X; ++ j) v[i][j] = ++ k;
            for (-- j, ++ i; i <= X; ++ i) v[i][j] = ++ k;
            for (-- i, -- j; j >= x; -- j) v[i][j] = ++ k;
            for (++ j, -- i; i > x; -- i) v[i][j] = ++ k;
            
            ++ x; -- X;
        }
        
        return v;
    }
}

/**
Spiral Matrix II
Difficulty: Medium

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 */
