//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/25/2012
// @Last modified: 12/25/2012
//

#include <iostream>
#include <vector>
using namespace std;

// Works. Best. Time: O(mn), Space: O(1).
// From: https://leetcode.com/problems/set-matrix-zeroes/editorial
class Solution5 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;

        int m = matrix.size(), n = matrix[0].size();
        bool row0 = false, col0 = false;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (matrix[i][j] == 0) {
                    // mark first row/col to be set to 0.
                    matrix[i][0] = matrix[0][j] = 0;
                    if (i == 0) row0 = true; // mark first row to be set to 0
                    if (j == 0) col0 = true; // mark first col to be set to 0
                }
            }
        }

        for (int i = 1; i < m; ++ i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; ++ j) matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < n; ++ j) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; ++ i) matrix[i][j] = 0;
            }
        }
        if (row0) {
            for (int j = 0; j < n; ++ j) matrix[0][j] = 0;
        }
        if (col0) {
            for (int i = 0; i < m; ++ i) matrix[i][0] = 0;
        }
    }
};

// Works. Best solution. Simpple, easy to understand. Time: O(mn), Space: O(m+n).
// First find all rows and columns that should be set to 0; then set them 0.
class Solution4 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();

        unordered_set<int> rows, cols;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int row : rows) {
            for (int j = 0; j < n; j ++) matrix[row][j] = 0;
        }
        for (int col : cols) {
            for (int i = 0; i < m; i ++) matrix[i][col] = 0;
        }
    }
};


void dumpMatrix(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); i ++) {
        for (int j = 0; j < matrix[0].size(); j ++) {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
    puts("");
}


// This works too. Slightly more cleaner, due to use of setRow0() and setCol().
class Solution3 {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int rows = matrix.size(), cols = matrix[0].size();
        int M = -1, N = -1;
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                if (matrix[i][j] == 0) {
                    M = i; N = j; 
                    break;
                }
            }
        }
        
        if (M == -1) return;
        
        for (int i = 0; i < rows; ++ i) {
            if (i == M) continue;
            for (int j = 0; j < cols; ++ j) {
                if (j == N) continue;
                if (matrix[i][j] == 0) {
                    matrix[i][N] = 0;
                    matrix[M][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < rows; ++ i) {
            if (i == M) continue; // must have this!
            if (matrix[i][N] == 0) setRow0(matrix, i);
        }
        for (int j = 0; j < cols; ++ j) {
            if (j == N) continue; // must have this!
            if (matrix[M][j] == 0) setCol0(matrix, j);
        }
        setRow0(matrix, M);
        setCol0(matrix, N);
    }
    
    void setRow0(vector<vector<int> > &matrix, int row) {
        for (int j = 0; j < matrix[0].size(); ++ j) matrix[row][j] = 0;
    }

    void setCol0(vector<vector<int> > &matrix, int col) {
        for (int i = 0; i < matrix.size(); ++ i) matrix[i][col] = 0;
    }
};

class Solution {
public:
    // This is more efficient than the other, since it labels with 0, not 1.
    void setZeroes(vector<vector<int> > &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // look for an element == 0, use its row/col as storage. 0 for clearable.
        int i, j, m = -1, n;
        for (i = 0; i < rows; i ++) {
            for (j = 0; j < cols; j ++) {
                if (matrix[i][j] == 0) {
                    m = i; n = j;
                    i = rows; 
                    break; // break out of loops.
                }
            }
        }
        
        if (m == -1) return; 
                
        // scan entire matrix.
        for (i = 0; i < rows; i ++) {
            if (i == m) continue; // don't forget this.
            for (j = 0; j < cols; j ++) {
                if (j == n) continue; // don't forget this.
                if (matrix[i][j] == 0) {
                    matrix[m][j] = 0;
                    matrix[i][n] = 0;
                }
            }
        }
        //dumpMatrix(matrix);
        
        // set 0s.
        for (i = 0; i < rows; i ++) {
            if (i == m) continue; // don't clear the label row.
            if (matrix[i][n] == 0) { // clear i-th row.
                for (int j = 0; j < cols; j ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        //dumpMatrix(matrix);

        for (j = 0; j < cols; j ++) {
            if (j == n) continue; // don't clear the label column.
            if (matrix[m][j] == 0) { // clear j-th col.
                for (int i = 0; i < rows; i ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        //dumpMatrix(matrix);
        
        // clear m-th row and n-th col.
        for (int i = 0; i < rows; i ++) matrix[i][n] = 0;
        for (int j = 0; j < cols; j ++) matrix[m][j] = 0;
    }
};


// This works too. But is less efficient since 0 is used for labeling.
// Has extra cycles.
class Solution2 {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // look for an element == 0, use its row/col as storage.
        int i, j, m = -1, n;
        for (i = 0; i < rows; i ++) {
            for (j = 0; j < cols; j ++) {
                if (matrix[i][j] == 0) {
                    m = i; n = j;
                    i = rows; 
                    break; // break out of loops.
                }
            }
        }
        
        if (m == -1) return; 
        
        // clear storage, set 1 if the pos contains 0!
        for (int i = 0; i < rows; i ++) 
            matrix[i][n] = (matrix[i][n] == 0) ? 1 : 0;
        for (int j = 0; j < cols; j ++) 
            matrix[m][j] = (matrix[m][j] == 0) ? 1 : 0;
        
        // scan entire matrix.
        for (i = 0; i < rows; i ++) {
            if (i == m) continue; // don't forget this.
            for (j = 0; j < cols; j ++) {
                if (j == n) continue; // don't forget this.
                if (matrix[i][j] == 0) {
                    matrix[m][j] = 1;
                    matrix[i][n] = 1;
                }
            }
        }
        
        // set 0s.
        for (i = 0; i < rows; i ++) {
            if (i == m) continue; // don't forget this.
            if (matrix[i][n] == 1) { // clear i-th row.
                for (int j = 0; j < cols; j ++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (j = 0; j < cols; j ++) {
            if (j == n) continue; // don't forget this.
            if (matrix[m][j] == 1) { // clear j-th col.
                for (int i = 0; i < rows; i ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // clear m-th row and n-th col.
        for (int i = 0; i < rows; i ++) matrix[i][n] = 0;
        for (int j = 0; j < cols; j ++) matrix[m][j] = 0;

    }
};

vector<int> makeVec(int a[], int len) {
    vector<int> v;
    for (int i = 0; i < len; i ++) {
        v.push_back(a[i]);
    }
    return v;
}


int main() {
    vector<vector<int> > matrix(5); // = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
    int a1[] = {0,0,0,5};
    matrix[0] = makeVec(a1, 4);
    int a2[] = {4,3,1,4};
    matrix[1] = makeVec(a2, 4);
    int a3[] = {0,1,1,4};
    matrix[2] = makeVec(a3, 4);
    int a4[] = {1,2,1,3};
    matrix[3] = makeVec(a4, 4);
    int a5[] = {0,0,1,1};
    matrix[4] = makeVec(a5, 4);
    dumpMatrix(matrix);
    
    Solution s;
    s.setZeroes(matrix);
    dumpMatrix(matrix);
            
    return 0;
}

