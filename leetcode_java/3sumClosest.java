// This works too. Avoid dupliate entries by statements labeled with "//<-", but not necessary.
public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        if (nums.length <= 2) return 0;
        int msum = 0, mdiff = Integer.MAX_VALUE;
        Arrays.sort(nums);
        
        for (int L = 0, len = nums.length; L < len - 2; ++ L) {
            if (L > 0 && nums[L] == nums[L - 1]) ++ L; //<-
            
            for (int M = L + 1, R = len - 1; M < R; ) {
                int sum = nums[L] + nums[M] + nums[R];
                int diff = Math.abs(sum - target);
                
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
}

/**
3Sum Closest
Difficulty: Medium

Given an array S of n integers, find three integers in S such that 
the sum is closest to a given number, target. Return the sum of the 
three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
