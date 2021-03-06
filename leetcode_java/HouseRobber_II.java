public class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // rob nums[0..n-1].
        int[] mval = new int[n];
        mval[0] = 0;
        mval[1] = nums[0];
        for (int i = 1, len = n - 1; i < len; ++ i) {
            mval[i+1] = Math.max(mval[i], mval[i-1] + nums[i]);
        }
        
        // rob nums[1..n]. Be careful of indexing in for loop.
        int[] mval2 = new int[n];
        mval2[0] = 0;
        mval2[1] = nums[1];
        for (int i = 2; i < n; ++ i) {
            mval2[i] = Math.max(mval2[i-1], mval2[i-2] + nums[i]);
        }
        
        return Math.max(mval[n-1], mval2[n-1]);
    }
}

/**
House Robber II
Difficulty: Medium

Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself 
a new place for his thievery so that he will not get too much attention. 
This time, all houses at this place are arranged in a circle. That means 
the first house is the neighbor of the last one. Meanwhile, the security 
system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money 
of each house, determine the maximum amount of money you can rob tonight 
without alerting the police.
 */
