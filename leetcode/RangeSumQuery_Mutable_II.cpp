// Should work. But times out for large input.
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        mtrix = matrix;

        int m = matrix.size() + 1, n = matrix[0].size() + 1;
        sum.resize(m, vector<int>(n, 0));
        sum[1][1] = matrix[0][0];
        for (int i = 2; i < n; i++) {
            sum[1][i] = matrix[0][i - 1] + sum[1][i - 1];
        }
        for (int i = 2; i < m; i++) {
            sum[i][1] = matrix[i - 1][0] + sum[i - 1][1];
        }
        for (int i = 2; i < m; i++) {
            for (int j = 2; j < n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    void update(int row, int col, int val) {
        int m = sum.size(), n = sum[0].size(), diff = val - mtrix[row][col];
        for (int i = row + 1; i < m; ++ i) {
            for (int j = col + 1; j < n; ++ j) {
                sum[i][j] += diff;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1+1] - sum[row1+1][col2+1] + sum[row1+1][col1+1];
    }
    
    vector<vector<int>> sum, mtrix;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);

/**
Range Sum Query 2D - Mutable
Difficulty: Hard
Given a 2D matrix matrix, find the sum of the elements inside 
the rectangle defined by its upper left corner (row1, col1) 
and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by 
(row1, col1) = (2, 1) and (row2, col2) = (4, 3), 
which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10

Note:
1. The matrix is only modifiable by the update function.
2. You may assume the number of calls to update and 
   sumRegion function is distributed evenly.
3. You may assume that row1 ≤ row2 and col1 ≤ col2.
 */
