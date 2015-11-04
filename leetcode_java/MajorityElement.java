public class Solution {
    public int majorityElement(int[] nums) {
        int len = nums.length;
        if (len == 0) return -1;
        
        int e = nums[0], ct = 1;
        for (int i = 1; i < len; ++ i) {
            if (nums[i] == e) ++ ct;
            else {
                -- ct;
                if (ct == 0) {
                    e = nums[i];
                    ct = 1;
                }
            }
        }
        
        return e;
    }
}

/**
Majority Element
Difficulty: Easy

Given an array of size n, find the majority element. The majority element 
is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always 
exist in the array.
 */
