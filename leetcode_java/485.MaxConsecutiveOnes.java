class Solution2 {
    public int findMaxConsecutiveOnes(int[] nums) {
        int n = nums.length, len = 0, maxLen = 0;

        for (int i = 0; i < n; ++ i) {
            if (nums[i] == 1) {
                ++ len;
            } else {
                maxLen = Math.max(maxLen, len);
                len = 0;
            }
        }
        return Math.max(maxLen, len);
    }
}

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;

        int len = (nums[0] == 1) ? 1 : 0;
        int maxLen = len;

        for (int i = 1; i < n; ++ i) {
            if (nums[i] == 1) {
                ++ len;
            } else {
                maxLen = Math.max(maxLen, len);
                len = 0;
            }
        }
        maxLen = Math.max(maxLen, len);

        return maxLen;
    }
}

/**
485. Max Consecutive Ones
Easy

Given a binary array nums, return the maximum number of consecutive 1's in the array.
 */
