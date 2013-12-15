//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = A[0];
        int left = 0;
        int right = 0;
        int maxSum = sum;
        
        for (int i = 1; i < n; i ++) {
            if (sum < 0) {
                left = i+1;
                sum = 0;
            } 
            
            sum += A[i];
            if (maxSum < sum) {
                maxSum = sum;
                right = i;
            }
        }
        
        // [left, right] is the subarray's range.
        return maxSum;
    }
};

// This works too. Don't record left/right of range.
class Solution2 {
public:
    int maxSubArray(int A[], int n) {
        int msum = A[0], sum = A[0];
        for (int i = 1; i < n; ++ i) {
            if (sum < 0) sum = 0;
            sum += A[i];
            msum = max(msum, sum);
        }
        return msum;
    }
};