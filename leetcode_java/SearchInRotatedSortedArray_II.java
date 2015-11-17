// O(N).
public class Solution {
    public boolean search(int[] nums, int target) {
        int L = 0, R = nums.length - 1;
        while (L <= R) {
            int M = L + (R-L)/2;
            if (nums[M] == target) return true;
            
            if (nums[M] == nums[R]) { // <- only difference from SearchInRotatedSortedArray I.
                -- R;
            }
            else if (nums[M] < nums[R]) { // right half is sorted
                if (nums[M] < target && target <= nums[R]) {
                    L = M + 1;
                }
                else {
                    R = M - 1;
                }
            }
            else { // left half is sorted
                if (nums[L] <= target && target < nums[M]) {
                    R = M - 1;
                }
                else {
                    L = M + 1;
                }
            }
        }
        
        return false;        
    }
}

/**
Search in Rotated Sorted Array II
Difficulty: Medium

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
 */
