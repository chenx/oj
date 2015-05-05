//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/3/2013
// @Last modified: 4/6/2013
//

//
// This works too.
// This has the same structure as the solution to SprialMtraix.
// This applies with final matrix's row and column are not equal.
// This obviously can be simplified since here row and column are equal.
// So here Solution2 is still the best.
//
class Solution3 {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > v(n, vector<int>(n, 0));
        if (n == 0) return v;
        
        int x = 0, X = n - 1, y = 0, Y = n - 1, i, j;
        int k = 1;
        
        while (x <= X && y <= Y) {
            for (i = x, j = y; j <= Y; ++ j) v[i][j] = k ++;
            for (i = x + 1, j = Y; i <= X; ++ i) v[i][j] = k ++;
            for (i = X, j = Y - 1; j >= y && i > x; -- j) v[i][j] = k ++;
            for (i = X - 1, j = y; i > x && j < Y; -- i) v[i][j] = k ++;
            
            ++ x, ++ y, -- X, -- Y;
        }
        
        return v;        
    }
};

//
// This works too. This is much better than the first solution!
// Note the use of vector initialization: m[i] = vector<int>(n).
// This code is adapted from the code of SpiralMatrix.cpp.
// @Author: Xin Chen.
//
class Solution2 {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > m(n);
        for (int i = 0; i < n; ++ i) {
            m[i] = vector<int>(n);
        }
        // Note: Initialization above can simplify to:
        // vector<vector<int> > m(n, vector<int>(n, 0));
        
        int x = 0, X = n-1, i, j, ct = 0;
        while (x <= X) {
            for (i = x, j = x; j <= X; ++ j) m[i][j] = ++ ct;
            for (i = x+1, j = X; i <= X; ++ i) m[i][j] = ++ ct;
            for (i = X, j = X-1; j >= x; -- j) m[i][j] = ++ ct;
            for (i = X-1, j = x; i > x; -- i) m[i][j] = ++ ct;
            
            ++ x, -- X;
        }
        
        return m;
    }
};


// Note: 
// 1) for each cycle, rows are i_start to i_start + h - 1,
// columns are j_start to j_start + w - 1.
// 2) each time i or j goes to the boundary, needs to back off 1 step.
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > vs;
        if (n == 0) return vs;
        
        int a[n][n];
        int h = n, w = n;
        int v = 0; // current value.
        int i_start = 0, j_start = 0, i, j;
        
        while (1) {
            // Top border: left to right. Note: should be j < j_start + w.
            for (i = i_start, j = j_start; j < j_start + w; ++ j) {
                a[i_start][j] = ++ v;
            }
            -- h;
            if (h == 0) break;
            // right border: top to bottom. Note: should be i < i_start + w.
            for (--j, ++ i; i <= i_start + h; ++ i) {
                a[i][j] = ++ v;
            }
            -- w;
            if (w == 0) break;
            // bottom border: right to left.
            for (--i, -- j; j >= j_start; -- j) {
                a[i][j] = ++ v;
            }
            -- h;
            if (h == 0) break;
            // left border: bottom to top.
            for (++j, -- i; i > i_start; -- i) {
                a[i][j] = ++ v;
            }
            -- w;
            if (w == 0) break;
            
            i_start += 1;
            j_start += 1;
        }
        
        // Output from a[][] to vs.
        for (int i = 0; i < n; ++ i) {
            vector<int> v(n);
            for (int j = 0; j < n; ++ j) {
                v[j] = a[i][j];
            }
            vs.push_back(v);
        }
        return vs;
    }
};

/*
Problem:
        
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
