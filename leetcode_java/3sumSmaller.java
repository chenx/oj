// Avoid duplicates by statements commented by "//<-", but not necessary.
public class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        if (nums.length <= 2) return 0;
        int ct = 0; 
        Arrays.sort(nums);
        
        for (int L = 0, len = nums.length; L < len - 2; ++ L) {
            if (L > 0 && nums[L] == nums[L - 1]) ++ L; //<-
            
            for (int M = L + 1, R = len - 1; M < R; ) {
                int sum = nums[L] + nums[M] + nums[R];
                
                if (sum <= target) {
                    if (sum < target) ++ ct;
                    ++ M;
                    if (M < R && nums[M] == nums[M-1]) ++ M; //<-
                }
                else {
                    -- R;
                    if (M < R && nums[R] == nums[R+1]) -- R; //<-
                }
            }
        }
        
        return ct;                
    }
}

/**
3Sum Smaller 
Difficulty: Medium

Given an array of integers nums and a target, find the number of triplets that 
satisfy the condition nums[i] + nums[j] + nums[k] < target, where i != j != k.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
 */
