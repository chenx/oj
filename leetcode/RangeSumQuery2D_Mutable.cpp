// Should work. Teste locally.
// Modified from NumMatrix2. Use Binary Indexed Tree.
// See: https://github.com/chenx/oj/blob/master/leetcode/RangeSumQuery_Mutable.cpp
class NumMatrix4 {
public:
    NumMatrix(vector<vector<int> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        rows = matrix.size(), cols = matrix[0].size();

        base.resize(rows, vector<int>(cols, 0));
        BIT.resize(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 0; i < rows; ++ i)
            for (int j = 0; j < cols; ++ j)
                add(i + 1, j + 1, matrix[i][j]);
        //dumpMatrix(BIT);
    }

    void update(int row, int col, int val) {
        add(row + 1, col + 1, val - base[row][col]);
        base[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2 + 1, col2 + 1) - sum(row2 + 1, col1) - sum(row1, col2 + 1) + sum(row1, col1);
    }

private:
    int rows, cols;
    vector<vector<int> > base;
    vector<vector<int> > BIT;

    void add(int row, int col, int diff) {
        for (int i = row; i <= rows; i += parent(i)) 
            for (int j = col; j <= cols; j += parent(j)) 
                BIT[i][j] += diff;
    }

    int sum(int row, int col) {
        int s = 0;
        for (int i = row; i > 0; i -= parent(i)) 
            for (int j = col; j > 0; j -= parent(j)) 
                s += BIT[i][j];

        return s;
    }

    int parent(int i) { return i & -i; }
};


// Works. 
// Quad-tree based solution. Essentially, it is a divide and conquer 
// algorithm that divide the whole matrix into 4 sub-matrices recursively. 
// It can be shown that the algorithm is O(max(m, n)) per update/query.
// From: https://leetcode.com/discuss/71025/c-quad-tree-736ms-and-indexed-tree-492ms-based-solutions
class NumMatrix3 {
    struct TreeNode {
        int val = 0;
        TreeNode* neighbor[4] = {NULL, NULL, NULL, NULL};
        pair<int, int> leftTop = make_pair(0,0);
        pair<int, int> rightBottom = make_pair(0,0);
        TreeNode(int v):val(v){}
    };
public:
    NumMatrix(vector<vector<int>> &matrix) {
        nums = matrix;
        if (matrix.empty()) return;
        int row = matrix.size();
        if (row == 0) return;
        int col= matrix[0].size();
        root = createTree(matrix, make_pair(0,0), make_pair(row-1, col-1));
    }

    void update(int row, int col, int val) {
        int diff = val - nums[row][col];
        if (diff == 0) return;
        nums[row][col] = val;
        updateTree(row, col, diff, root);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        if (root != NULL)
            sumRegion(row1, col1, row2, col2, root, res);
        return res;
    }

private:
    TreeNode* root = NULL;
    vector<vector<int>> nums;
    TreeNode* createTree(vector<vector<int>> &matrix, pair<int, int> start, pair<int, int> end) {
        if (start.first > end.first || start.second > end.second)
            return NULL;
        TreeNode* cur = new TreeNode(0);
        cur->leftTop = start;
        cur->rightBottom = end;
        if (start == end) {
            cur->val = matrix[start.first][start.second];
            return cur;
        }

        int midx = ( start.first + end.first ) / 2;
        int midy = (start.second + end.second) / 2;
        cur->neighbor[0] = createTree(matrix, start, make_pair(midx, midy));
        cur->neighbor[1] = createTree(matrix, make_pair(start.first, midy+1), make_pair(midx, end.second));
        cur->neighbor[2] = createTree(matrix, make_pair(midx+1, start.second), make_pair(end.first, midy));
        cur->neighbor[3] = createTree(matrix, make_pair(midx+1, midy+1), end);
        for (int i = 0; i < 4; i++) {
            if (cur->neighbor[i])
                cur->val += cur->neighbor[i]->val;
        }
        return cur;
    }

    void sumRegion(int row1, int col1, int row2, int col2, TreeNode* ptr, int &res) {
        pair<int, int> start = ptr->leftTop;
        pair<int, int> end = ptr->rightBottom;
        // determine whether there is overlapping
        int top = max(start.first, row1);
        int bottom = min(end.first, row2);
        if (bottom < top) return;
        int left = max(start.second, col1);
        int right = min(end.second, col2);
        if (left > right) return;


        if (row1 <= start.first && col1 <= start.second && row2 >= end.first && col2 >= end.second) {
            res += ptr->val;
            return;
        }

        for (int i = 0; i < 4; i ++) 
            if (ptr->neighbor[i]) 
                sumRegion(row1, col1, row2, col2, ptr->neighbor[i], res);

    }


    void updateTree(int row, int col, int diff, TreeNode* ptr){
        if (row >= (ptr->leftTop).first && row <= (ptr->rightBottom).first &&
            col >= (ptr->leftTop).second && col <= (ptr->rightBottom).second)
        {
            ptr->val += diff;
            for (int i = 0; i < 4; i++)
                if (ptr->neighbor[i])
                    updateTree(row, col, diff, ptr->neighbor[i]);

        }
    }
};

// Works. 
// The 2D indexed-tree solution. It is a simple generalization of the 
// 1D indexed tree solution. The complexity should be O(log(m)log(n)).
// From: https://leetcode.com/discuss/71025/c-quad-tree-736ms-and-indexed-tree-492ms-based-solutions
class NumMatrix2 {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        nrow = matrix.size();
        ncol = matrix[0].size();
        nums = matrix;
        BIT = vector<vector<int>> (nrow+1, vector<int>(ncol+1, 0));
        for (int i = 0; i < nrow; i++)
            for (int j = 0; j < ncol; j++)
                add(i, j, matrix[i][j]);

    }

    void update(int row, int col, int val) {
        int diff = val - nums[row][col];
        add(row, col, diff);
        nums[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int regionL = 0, regionS = 0;
        int regionLeft = 0, regionTop = 0;

        regionL = region(row2, col2);

        if (row1 > 0 && col1 > 0) regionS = region(row1-1, col1-1);
        if (row1 > 0) regionTop  = region(row1-1, col2);
        if (col1 > 0) regionLeft = region(row2, col1-1);       

        return regionL - regionTop - regionLeft + regionS;
    }
private:
    vector<vector<int>> nums;
    vector<vector<int>> BIT;
    int nrow = 0;
    int ncol = 0;
    void add(int row, int col, int val) {
        row++;
        col++;
        while(row <= nrow) {
            int colIdx = col;
            while(colIdx <= ncol) {
                BIT[row][colIdx] += val;
                colIdx += (colIdx & (-colIdx));
            }
            row +=  (row & (-row));
        }
    }

    int region(int row, int col) {
        row++;
        col++;
        int res = 0;
        while(row > 0) {
            int colIdx = col;
            while(colIdx > 0) {
                res += BIT[row][colIdx];
                colIdx -= (colIdx & (-colIdx));
            }
            row -= (row & (-row));
        }
        return res;
    }
};

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
