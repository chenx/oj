public class Solution {
    public int jump(int[] nums) {
        int len = nums.length;
        int[] ct = new int[len];
        Arrays.fill(ct, -1);
        ct[len - 1] = 0;
        
        for (int i = len - 2; i >= 0; -- i) {
            if (nums[i] + i >= len - 1) {
                ct[i] = 1;
                continue;
            }
            for (int j = nums[i]; j > 0; -- j) {
                if (ct[i + j] >= 0) {
                    if (ct[i] == -1) ct[i] = 1 + ct[i + j];
                    else {
                        ct[i] = Math.min(ct[i], 1 + ct[i + j]);
                    }

                    if (ct[i] == 2) break;
                }
            }
        }
        
        return ct[0];        
    }
}

/**
Jump Game II
Difficulty: Hard

Given an array of non-negative integers, you are initially positioned at the 
first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from 
index 0 to 1, then 3 steps to the last index.) 
 */
