class Solution {
    public int longestOnes(int[] nums, int k) {
        // Same as finding the longest subarray with at most k zeros.
        int maxLen = 0, count = 0;
        for (int i = 0, left = 0; i < nums.length; ++ i) {
            if (nums[i] == 0) ++ count;

            while (count > k) {
                if (nums[left] == 0) -- count;
                ++ left;
            }

            maxLen = Math.max(maxLen, i - left + 1);
        }
        return maxLen;
    }
}

/**
1004. Max Consecutive Ones III
Medium

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
 */
