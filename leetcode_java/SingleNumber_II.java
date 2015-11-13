public class Solution {
    public int singleNumber(int[] nums) {
        int v = 0;
        int len = nums.length;
        
        for (int i = 0; i < 32; ++ i) {
            int u = 1 << i;
            int ct = 0;
            for (int j = 0; j < len; ++ j) {
                if ((u & nums[j]) != 0) ++ ct; // must enclose & statement in "()".
            }
            
            if (ct % 3 != 0) v ^= u;
        }
        
        return v;
    }
}

/**
Single Number II
Difficulty: Medium

Given an array of integers, every element appears three times except for one. 
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory? 
 */
