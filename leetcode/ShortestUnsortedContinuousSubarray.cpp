class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minV = INT_MAX, maxV = INT_MIN;
        bool flag = false;
        for (int i = 1; i < n; ++ i) {
            if (nums[i-1] > nums[i]) flag = true;
            if (flag) minV = min(minV, nums[i]);
        }
        flag = false;
        for (int j = n-2; j >= 0; -- j) {
            if (nums[j] > nums[j+1]) flag = true;
            if (flag) maxV = max(maxV, nums[j]);
        }

        int x, y;
        for (x = 0; x < n && nums[x] <= minV; ++ x) ;
        for (y = n-1; y >= 0 && nums[y] >= maxV; -- y) ;

        return y > x ? y - x + 1 : 0;
    }
};

/**
from lhs, find first e[i] > e[i+1]
from rhs, find first e[j] > e[j+1] 

from lhs, find first e[x] > e[i]
from rhs, find first e[y] < e[j]

sort the range [x .. y]
 */

/**
581. Shortest Unsorted Continuous Subarray

Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray 
in non-decreasing order, then the whole array will be sorted in non-decreasing order.

Return the shortest such subarray and output its length.
 */
