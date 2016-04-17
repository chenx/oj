class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxEdge = 0;
        
        for (int i = 0; i < m; ++ i) 
            if (matrix[i][0] == 1) maxEdge = 1;
        for (int j = 0; j < n; ++ j)
            if (matrix[0][j] == 1) maxEdge = 1;
            
        for (int i = 1; i < m; ++ i) {
            for (int j = 1; j < n; ++ j) {
                if (matrix[i][j] == 0) ;
                else { // Note: use "min", not "max" in DP!
                    matrix[i][j] = 1 + 
                        min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1]));
                    maxEdge = max(maxEdge, matrix[i][j]);
                }
            }
        }
        
        return maxEdge * maxEdge;
    }
};


/**
Maximal Square

Given a 2D binary matrix filled with 0's and 1's, find the largest square 
containing all 1's and return its area.

Example

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.

 */
