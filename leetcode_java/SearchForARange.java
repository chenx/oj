// This works.
// use findRightMost, ret starts with -1!
// if use findLeftMost, ret starts with nums.length.
public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[2];
        
        ans[0] = findRightMost(nums, target - 1) + 1;
        ans[1] = findRightMost(nums, target);
        
        if (ans[1] == -1 || nums[ans[1]] != target) {
            ans[0] = ans[1] = -1;
        }
        
        return ans;
    }
    
    private int findRightMost(int[] nums, int target) {
        int L = 0, R = nums.length - 1, M, ret = -1;    
        
        while (L <= R) {
            M = L + (R - L)/2;
            if (nums[M] <= target) {
                ret = M;
                L = M + 1;
            }
            else {
                R = M - 1;
            }
        }
        
        return ret;
    }
}


/**
Search for a Range
Difficulty: Medium

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
 */
