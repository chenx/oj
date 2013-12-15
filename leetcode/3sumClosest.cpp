//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 1/9/2013
//

// This works.
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int len = num.size();
        int sum, tmp_sum, diff, min_diff = INT_MAX;
        
        for (int L = 0; L < len - 2; L ++) {
            for (int M = L + 1, R = len - 1; M < R; ) {
                tmp_sum = num[M] + num[R] + num[L];
                diff = tmp_sum - target;
                if (abs(diff) < min_diff) {
                    min_diff = abs(diff);
                    sum = tmp_sum;
                }

                if (diff < 0) {
                    M ++;
                } else {
                    R --;
                }
            }
        }
        return sum;
    }    
};

// This does NOT work.
class Solution_bad {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int len = num.size();
        int sum, minSum = num[0] + num[1] + num[2], minDiff = INT_MAX;
        
        for (int L = 0; L < len - 2; L ++) {
            // search [L+1, len - 1] for 2 numbers whose sum = -num[L].
            for (int M = L + 1, R = len - 1; M < R; ) {
                sum = num[M] + num[R] + num[L];
                if (sum - target == 0) {
                    return target;
                }
                else if ( abs(minDiff) > abs(sum - target) ) {
                    minSum = sum;
                    minDiff = sum - target;
                }
                
                if (sum < 0 && minSum < 0) {
                    if (sum < minSum) M ++;
                    else R --; // R -- also gets it all right.
                } else if (sum > 0 && minSum > 0) {
                    if (sum > minSum) R --;
                    else M ++;
                } else if (sum < 0 && minSum > 0) {
                    if (- sum > minSum) M ++;
                    else R --;
                } else if (sum > 0 && minSum < 0) {
                    if (sum > - minSum) R --;
                    else M ++;
                } else {
                    M ++;
                }
            }
        }
        return minSum;
    }
};

/*
Problem:

Given an array S of n integers, find three integers in S such that 
the sum is closest to a given number, target. Return the sum of the 
three integers. You may assume that each input would have exactly 
one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 */
