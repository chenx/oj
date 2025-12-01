class Solution2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<int> result(m*n);
        int direction = 1, ct = 0;

        for (int i = 0, j = 0; i < m && j < n; ) {
            result[ct ++] = mat[i][j];

            int x = i - direction; // These 2 lines are the only difference from Solution.
            int y = j + direction;

            if (x >= 0 && x < m && y >= 0 && y < n) {
                i = x;
                j = y;
            } else {
                if (direction == 1) {
                    if (j == n-1) i += 1;
                    else j += 1;
                } else {
                    if (i == m-1) j += 1;
                    else i += 1;
                }
                direction = - direction;
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans(m*n, 0);
        int ct = 0, direction = 1; // 1: go up right; -1: down left

        for (int i = 0, j = 0; i < m && j < n; ) {
            ans[ct ++] = mat[i][j];

            int x = i + (direction == 1 ? -1 : 1);
            int y = j + (direction == 1 ? 1 : -1);
            
            if (x >= 0 && x < m && y >= 0 && y < n) {
                i = x, j = y;
            } else {
                if (direction == 1) {
                    if (j == n-1) i += 1;
                    else j += 1;
                } else {
                    if (i == n-1) j += 1;
                    else i += 1;
                }
                direction = - direction;
            }
        }
        return ans;        
    }
};

/**
498. Diagonal Traverse
Medium

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
 */
