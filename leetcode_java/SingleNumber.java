public class Solution {
    public int singleNumber(int[] nums) {
        int val = 0;
        for (int i = 0, len = nums.length; i < len; ++ i) {
            val ^= nums[i];
        }
        
        return val;
    }
}

/**
Single Number
Difficulty: Medium

Given an array of integers, every element appears twice except for one. 
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory? 
 */
