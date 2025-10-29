class Solution {
    public int missingElement(int[] nums, int k) {
        int count = 0, v = 0;
        for (int i = 0; i < nums.length - 1; ++ i) {
            v = nums[i];
            while (v < nums[i+1] - 1) {
                ++ v;
                ++ count;
                if (count == k) return v;
            }
        }
        for (v = nums[nums.length - 1]; count < k; ++ count) {
            ++ v;
        }
        return v;
    }
}

/**
1060. Missing Element in Sorted Array
Medium

Given an integer array nums which is sorted in ascending order and all of its elements are unique and given 
also an integer k, return the kth missing number starting from the leftmost number of the array.
 */
