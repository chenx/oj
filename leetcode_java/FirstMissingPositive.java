public class Solution {
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        
        for (int i = 0; i < len; ++ i) {
            while (nums[i] > 0 && nums[i] <= len && nums[i] != i+1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        
        for (int i = 0; i < len; ++ i) {
            if (nums[i] != i + 1) return i + 1;
        }
        
        return len + 1;
    }
    
    private void swap(int[] nums, int L, int R) {
        int tmp = nums[L];
        nums[L] = nums[R];
        nums[R] = tmp;
    }
}

/**
First Missing Positive
Difficulty: Hard

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 
 */
