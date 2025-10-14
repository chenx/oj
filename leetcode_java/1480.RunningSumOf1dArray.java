class Solution {
    public int[] runningSum(int[] nums) {
        int n = nums.length;
        int[] ret = new int[n];
        if (n == 0) return ret;

        ret[0] = nums[0];
        for (int i = 1; i < n; ++ i) {
            ret[i] = ret[i-1] + nums[i];
        }
        return ret;
    }
}

/**
1480. Running Sum of 1d Array

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.
 */
