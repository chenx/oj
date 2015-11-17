public class Solution {
    public int search(int[] nums, int target) {
        int L = 0, R = nums.length - 1;
        while (L <= R) { // <-
            int M = L + (R-L)/2;
            if (nums[M] == target) return M; // <-
            
            if (nums[M] < nums[R]) { // right half is sorted
                if (nums[M] < target && target <= nums[R]) { // <-
                    L = M + 1;
                }
                else {
                    R = M - 1;
                }
             }
            else { // left half is sorted
                if (nums[L] <= target && target < nums[M]) { // <-
                    R = M - 1;
                }
                else {
                    L = M + 1;
                }
            }
        }
        
        return -1;        // <-
    }
}

/**
Search in Rotated Sorted Array
Difficulty: Hard

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its 
index, otherwise return -1.

You may assume no duplicate exists in the array.  
 */
