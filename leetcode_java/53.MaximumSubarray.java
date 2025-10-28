class Solution2 {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;

        int sum = 0, maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++ i) {
            if (sum < 0) sum = 0;
            sum += nums[i];
            maxSum = Math.max(maxSum, sum);
        }
        return maxSum;
    }
}

class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;

        int sum = nums[0], maxSum = nums[0];
        for (int i = 1; i < n; ++ i) {
            if (sum < 0) sum = 0;
            sum += nums[i];
            maxSum = Math.max(maxSum, sum);
        }
        return maxSum;
    }
}

/**
53. Maximum Subarray

Given an integer array nums, find the with the largest sum, and return its sum.
 */
