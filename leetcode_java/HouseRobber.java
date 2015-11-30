public class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        
        int[] mval = new int[n+1];
        mval[0] = 0;
        mval[1] = nums[0];
        
        for (int i = 1; i < n; ++ i) {
            mval[i+1] = Math.max(mval[i], mval[i-1] + nums[i]);
        }
        
        return mval[n];
    }
}

/**
House Robber
Difficulty: Easy

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint 
stopping you from robbing each of them is that adjacent houses have 
security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money 
of each house, determine the maximum amount of money you can rob tonight 
without alerting the police.
 */
