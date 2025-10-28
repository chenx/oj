public class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        if (n <= 1) return;
        
        for (int row = 0, m = n/2; row < m; ++ row) {
            int first = row, last = n - 1 - first;
            
            for (int i = first; i < last; ++ i) {
                int offset = i - first;
                
                int tmp = matrix[first][i];
                matrix[first][i] = matrix[last - offset][first];
                matrix[last - offset][first] = matrix[last][last - offset];
                matrix[last][last - offset] = matrix[i][last];
                matrix[i][last] = tmp;
            }
        }
    }
}

/**
Rotate Image
Difficulty: Medium

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
 */
