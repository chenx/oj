public class Solution {
    
    public int findMin(int[] nums) {
        int L = 0, R = nums.length - 1;
        
        while (L < R) {
            int M = L + (R - L)/2;
            if (nums[M] < nums[R]) R = M;
            else L = M + 1;
        }
        
        return nums[L];
    }
}

/**
Find Minimum in Rotated Sorted Array
Difficulty: Medium

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
 */
