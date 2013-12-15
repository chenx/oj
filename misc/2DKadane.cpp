//
// 2D kadane sum: given matrix of positive and negative integers, 
// find rectange of max sum.
//
// Note: this as to 1D Kadane sum, is like Maximal Rectangle as to Max
// rectangle in histogram. Both 2D versions use the same structure to
// use 1D result. The only difference is, here matrix values can be 
// positive, 0 or negative; there the values can only be non-negative.
//
// @Author: Xin Chen
// @Created on: 4/5/2013
// @Last modified: 4/5/2013
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kadane2D(vector<vector<int> > matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        if (cols == 0) return 0;
        
        int maxsum = INT_MIN;
        for (int i = 0; i < rows; ++ i) {
            vector<int> v(cols);
            for (int k = 0; k < cols; ++ k) v[k] = 0;
            
            for (int j = i; j < rows; ++ j) {
                for (int k = 0; k < cols; ++ k) {
                    v[k] += matrix[j][k];
                }
                maxsum = max(maxsum, kadane(v));
            }
        }
        
        return maxsum;
    }
    
    // also works. Same structure as maximal recctange using hist().
    int kadane2D_v2(vector<vector<int> > matrix) {
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        if (cols == 0) return 0;
        
        int maxsum = INT_MIN;
        for (int i = 0; i < rows; ++ i) {
            vector<int> v(cols);
            for (int k = 0; k < cols; ++ k) {
                v[k] = 0;
            }
            maxsum = max(maxsum, kadane(v));
            
            for (int j = i+1; j < rows; ++ j) {
                for (int k = 0; k < cols; ++ k) {
                    v[k] += matrix[j][k];
                }
                maxsum = max(maxsum, kadane(v));
            }
        }
        
        return maxsum;
    }    
    
    int kadane(vector<int> A) {
        int n = A.size();
        if (n < 1) return 0;
        
        int sum = A[0], maxsum = sum;
        for (int i = 1; i < n; ++ i) {
            if (sum < 0) sum = 0;
            sum += A[i];
            maxsum = max(sum, maxsum);
        }
        
        return maxsum;
    }
};

int main() {
    const int R = 4, C = 4;
    int a[][C] = {
        {1,1,0,0},
        {-1,-1,-1,1},
        {-1,1,1,1},
        {1,-1,0,1}
    };
    
    vector<vector<int> > m(R);
    for (int i = 0; i < R; ++ i) {
        vector<int> r(C);
        for (int j = 0; j < C; ++ j) {
            r[j] = a[i][j];
        }
        m[i] = r;
    }
    
    Solution s;
    cout << "maxsum    = " << s.kadane2D(m) << endl;
    cout << "maxsum_v2 = " << s.kadane2D_v2(m) << endl;
    return 0;
}
