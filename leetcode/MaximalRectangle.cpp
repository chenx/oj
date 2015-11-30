//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 4/3/2013
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// This works. Passed small and large test sets.
// From: http://discuss.leetcode.com/questions/260/maximal-rectangle
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int n = matrix[0].size();
        vector<int> H(n); // default to 0s.
        vector<int> L(n); // default to 0s.
        vector<int> R(n, n);

        int ret = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            int left = 0, right = n;
            // calculate L(i, j) from left to right
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++H[j];
                    L[j] = max(L[j], left);
                }
                else {
                    left = j+1;
                    H[j] = 0; L[j] = 0; R[j] = n;
                }
            }
            // calculate R(i, j) from right to right
            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right);
                    ret = max(ret, H[j]*(R[j]-L[j]));
                }
                else {
                    right = j;
                }
            }
        }

        return ret;
    }
};


//
// This works. O(nm^2). m = rows, n = cols.
//
// Idea: i = 0 to rows-1, j = i+1 to rows-1, there are O(n^2) combinations,
// each forms a histogram, whose max area can be calculated using hist().
//
// This times out for the last 2 test cases of the large test set,
// where matrix size is 200. But the result are correct: 48 and 147.
// The time spent were not that bad either, should be ~ 1sec.
//
class Solution2 {
public:
    // Note, here the 2 loop is redundant. See Solution3. 1/20/2013.
    int maximalRectangle(vector<vector<char> > &matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        if (cols == 0) return 0;
        int ma = 0;
        
        for (int i = 0; i < rows; ++ i) {
            vector<int> H(cols);
            for (int k = 0; k < cols; ++ k) {
                H[k] = matrix[i][k] - '0';
            }
            ma = max(ma, hist(H));
        
            // each time, new histogram base is on row j.    
            for (int j = i+1; j < rows; ++ j) {
                for (int k = 0; k < cols; ++ k) {
                    H[k] = (matrix[j][k] == '0') ? 0 : H[k] + 1; 
                } 
                ma = max(ma, hist(H));
            }
        }

        return ma;
    }
    
    int hist(vector<int> & H) {
        stack<int> s;
        H.push_back(0);
        int i = 0, ma = 0;
        
        while (i < H.size()) {
            if (s.empty() || H[i] >= H[s.top()]) {
                s.push(i ++);
            }
            else {
                int t = s.top();
                s.pop();
                ma = max(ma, H[t] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        
        return ma;
    }
};


//
// This works. O(nm). m = rows, n = cols.
//
// Idea: Solution 2 is actually redundant in the calculation.
// Only need to go through the row once. 
// Each row sum forms a histogram, whose max area can be calculated using hist().
//
class Solution3 {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        
        vector<int> v(cols+1, 0); // extra 0, avoid H.push_back(0) in hist().
        int marea = 0;
        
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                v[j] = ( matrix[i][j] == '0' ? 0 : v[j] + 1 );
            }
            marea = max(marea, hist(v));
        }
        return marea;
    }
    
    int hist(vector<int> & H) {
        stack<int> s;
        //H.push_back(0);
        int i = 0, ma = 0;
        
        while (i < H.size()) {
            if (s.empty() || H[i] >= H[s.top()]) {
                s.push(i ++);
            }
            else {
                int t = s.top();
                s.pop();
                ma = max(ma, H[t] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        
        return ma;
    }
};


int main() {
    string in[] = {"00","00"};
    int n = sizeof(in) / sizeof(in[0]);
    vector<vector<char> > input(n);
    cout << "n = " << n << endl;
    for (int i = 0; i < n; ++ i) {
        vector<char> v(in[i].length());
        for (int j = 0; j < in[i].length(); ++ j) {
            v[j] = in[i][j];
        }
        input[i] = v;
    }
    
    Solution2 s;
    cout << "max area = " << s.maximalRectangle(input) << endl;
    return 0;
}

/*
Problem:
        
Maximal Rectangle.

http://www.drdobbs.com/database/the-maximal-rectangle-problem/184410529?pgno=1
Method 1: brutal force. O(m^3 * n^3) in time. O(1) in space.


 */
