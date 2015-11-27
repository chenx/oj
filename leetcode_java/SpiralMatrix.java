public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> v = new ArrayList<Integer>();
        if (matrix.length == 0 || matrix[0].length == 0) return v;
        int x = 0, y = 0, X = matrix.length - 1, Y = matrix[0].length - 1, i, j;

        while (x <= X && y <= Y) {
            for (i = x, j = y; j <= Y; ++ j) v.add(matrix[i][j]);

            for (-- j, ++ i; i <= X; ++ i) v.add(matrix[i][j]);

            if (-- i == x) break; // be careful here.
            for (-- j; j >= y; -- j) v.add(matrix[i][j]);

            if (++ j == Y) break; // be careful here.
            for (-- i; i > x; -- i) v.add(matrix[i][j]);

            ++ x; -- X; ++ y; -- Y;
        }
        
        return v;        
    }
}

/**
Spiral Matrix
Difficulty: Medium

Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 
 */
