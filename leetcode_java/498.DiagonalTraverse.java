// Same as Solution. 
// From: https://leetcode.com/problems/diagonal-traverse/editorial/
class Solution2 {
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return new int[0];
       
        int N = matrix.length, M = matrix[0].length;
        int row = 0, column = 0;

        int direction = 1; // The direction we are processing the current diagonal
        
        int[] result = new int[N*M]; // The final result array
        int r = 0;
        
        while (row < N && column < M) {
            result[r++] = matrix[row][column]; // Add the current element to the result matrix. 
            
            int new_row = row + (direction == 1 ? -1 : 1);
            int new_column = column + (direction == 1 ? 1 : -1);

            if (new_row < 0 || new_row == N || new_column < 0 || new_column == M) {
                if (direction == 1) { // If the current diagonal was going in the upwards direction.
                    row += (column == M - 1 ? 1 : 0) ;
                    column += (column < M - 1 ? 1 : 0);
                } else {
                    column += (row == N - 1 ? 1 : 0);
                    row += (row < N - 1 ? 1 : 0);
                }
                
                direction = 1 - direction; // Flip the direction
            } else {
                row = new_row;
                column = new_column;
            }
        }
        return result;      
    }
}

class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return new int[0];
       
        int N = matrix.length, M = matrix[0].length;
        int row = 0, column = 0;

        int direction = 1; // The direction we are processing the current diagonal
        
        int[] result = new int[N*M]; // The final result array
        int r = 0;
        
        while (row < N && column < M) {
            result[r++] = matrix[row][column]; // Add the current element to the result matrix. 
            
            // Move along in the current diagonal depending upon the current direction.
            // [i, j] -> [i - 1, j + 1] if going up, [i, j] -> [i + 1][j - 1] if going down.
            int new_row = row + (direction == 1 ? -1 : 1);
            int new_column = column + (direction == 1 ? 1 : -1);

            // Checking if the next element in the diagonal is outside the bounds
            if (new_row < 0 || new_row == N || new_column < 0 || new_column == M) {
                // If the current diagonal was going in the upwards direction.
                if (direction == 1) {
                    // For an upwards going diagonal having [i, j] as its tail
                    // If [i, j + 1] is within bounds, then it becomes
                    // the next head. Otherwise, the element directly below
                    // i.e. the element [i + 1, j] becomes the next head
                    row += (column == M - 1 ? 1 : 0) ;
                    column += (column < M - 1 ? 1 : 0);
                } else {
                    // For a downwards going diagonal having [i, j] as its tail
                    // if [i + 1, j] is within bounds, then it becomes
                    // the next head. Otherwise, the element directly below
                    // i.e. the element [i, j + 1] becomes the next head
                    column += (row == N - 1 ? 1 : 0);
                    row += (row < N - 1 ? 1 : 0);
                }
                
                direction = 1 - direction; // Flip the direction
            } else {
                row = new_row;
                column = new_column;
            }
        }
        return result;      
    }
}

/**
498. Diagonal Traverse
Medium

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
 */
