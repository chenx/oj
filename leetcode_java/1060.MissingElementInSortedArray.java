// Binary search
// From https://leetcode.com/problems/missing-element-in-sorted-array/editorial
class Solution3 {
    public int missingElement(int[] nums, int k) {
        int n = nums.length;
        int left = 0, right = n - 1;
        
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (nums[mid] - nums[0] - mid < k) {
                left = mid;
            } else{
                right = mid - 1;
            }
        }
        
        return nums[0] + k + left;
    }
}

// From https://leetcode.com/problems/missing-element-in-sorted-array/editorial
class Solution2 {
    public int missingElement(int[] nums, int k) {
        int n = nums.length;
        
        for (int i = 1; i < n; ++i) {
            int missedInGap = nums[i] - nums[i - 1] - 1;
            if (missedInGap >= k) {
                return nums[i - 1] + k;
            }
            k -= missedInGap;
        }
        
        return nums[n - 1] + k;
    }
}

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
