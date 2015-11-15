public class Solution {
    public int removeDuplicates(int[] nums) {
        int len = nums.length;
        if (len <= 1) return len;
        
        int v = nums[0], L = 1;
        for (int i = 1; i < len; ++ i) {
            if (v != nums[i]) {
                v = nums[L] = nums[i];
                ++ L;
            }
        }
        
        return L;
    }
}

/**
Remove Duplicates from Sorted Array
Difficulty: Easy

Given a sorted array, remove the duplicates in place such that each element 
appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place 
with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums 
being 1 and 2 respectively. It doesn't matter what you leave beyond the new length. 
 */
