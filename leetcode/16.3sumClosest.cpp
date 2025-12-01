//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 1/9/2013
//

class Solution4 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), minDiff = INT_MAX, minDiffSum = 0;
        for (int i = 0; i < n - 2; ++ i) {
            if (i > 0 && nums[i-1] == nums[i]) continue;

            for (int j = i + 1, k = n - 1; j < k; ) {
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);

                if (diff < minDiff) {
                    minDiff = diff;
                    minDiffSum = sum;
                }

                if (sum <= target) {
                    ++ j;
                } else {
                    -- k;
                }
            }
        }
        return minDiffSum;
    }
};

// Works.
class Solution3 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n <= 2) return 0;
        
        sort(nums.begin(), nums.end());
        
        int minDiff = INT_MAX, minSum = 0;
        for (int L = 0; L < n - 2; ++ L) {
            if (L > 0 && nums[L-1] == nums[L]) continue;
            
            for (int M = L + 1, R = n - 1; M < R; ) {
                int sum = nums[L] + nums[M] + nums[R];
                
                int diff = abs(sum - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    minSum = sum;
                }
                
                if (sum <= target) 
                    while (M < R && nums[M] == nums[++ M]) ;
                else 
                    while (M < R && nums[R] == nums[-- R]) ;
            }
        }
        
        return minSum;
    }
};

// This works too. Avoid dupliate entries by statements labeled with "//<-"
class Solution2 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() <= 2) return 0;
        int msum = 0, mdiff = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int L = 0, len = nums.size(); L < len - 2; ++ L) {
            if (L > 0 && nums[L] == nums[L - 1]) ++ L; //<-
            
            for (int M = L + 1, R = len - 1; M < R; ) {
                int sum = nums[L] + nums[M] + nums[R];
                int diff = abs(sum - target);
                
                if (diff < mdiff) {
                    mdiff = diff;
                    msum = sum;
                }
                
                if (sum <= target) {
                    ++ M;
                    if (M < R && nums[M] == nums[M-1]) ++ M; //<-
                }
                else {
                    -- R;
                    if (M < R && nums[R] == nums[R+1]) -- R; //<-
                }
            }
        }
        
        return msum;
    }
};

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
16. 3Sum Closest
Medium

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.


    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 */

