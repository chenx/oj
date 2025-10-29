class Solution {
    public int search(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while (l <= r) {  // NOTE: "<="
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
}

/**
704. Binary Search
Easy

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to 
search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
 */
