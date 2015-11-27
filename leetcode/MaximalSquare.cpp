class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        //int v[][] = new int[rows][cols];
        vector<vector<int> > v(rows, vector<int>(cols, 0));
        int mEdge = 0, i, j;
        
        for (j = 0; j < cols; ++ j) {
            v[0][j] = (matrix[0][j] == '0' ? 0 : 1);
            mEdge = max(mEdge, v[0][j]);
        }
        
        for (i = 1; i < rows; ++ i) {
            v[i][0] = (matrix[i][0] == '0' ? 0 : 1);
            mEdge = max(mEdge, v[i][0]);
            
            for (j = 1; j < cols; ++ j) {
                if (matrix[i][j] == '0') v[i][j] = 0;
                else {
                    v[i][j] = 1 + min(v[i-1][j-1], min(v[i][j-1], v[i-1][j]));
                    mEdge = max(mEdge, v[i][j]);
                }
            }
        }
        
        return mEdge * mEdge;        
    }
};

/**
Maximal Square
Difficulty: Medium

Given a 2D binary matrix filled with 0's and 1's, 
find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4. 
 */
