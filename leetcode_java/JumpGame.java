// This works.
// From: https://leetcode.com/discuss/69187/simple-c-solution
public class Solution {
    public boolean canJump(int[] nums) {
        int len = nums.length;
        int target = len - 1;
        for (int i = len - 2; i >= 0; -- i) {
            if (nums[i] + i >= target) target = i;
        }
        return target == 0;
    }
}

// This works too, although not so obvious why.
// From: https://leetcode.com/discuss/65622/simple-c-solution
public class Solution2 {
    public boolean canJump(int[] nums) {
        int u = 1;
        for (int i = 0; i < nums.length; ++ i) {
            if (-- u < 0) return false;
            u = Math.max(u, nums[i]);
        }
        
        return true;
    }
}

/**
Jump Game
Difficulty: Medium

Given an array of non-negative integers, you are initially positioned 
at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
 */
