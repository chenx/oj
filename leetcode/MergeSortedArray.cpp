//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/18/2012
//

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // merge B into A. backward.[m --]
        int k = m + n - 1;
        -- n, -- m;
        while (n >= 0 && m >= 0) {
            if (A[m] > B[n]) A[k --] = A[m --];
            else A[k --] = B[n --];
        }
        
        //while (n >= 0) {} // do nothing
        while (n >= 0) { A[k --] = B[n --]; }
    }
};
