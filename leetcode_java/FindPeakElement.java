public class Solution {
    int findPeakElement(int[] nums) {
        int n = nums.length;
        if (n <= 1) return 0;

        int L = 0, R = n - 1;

        while (L <= R) {
            int M = L + (R - L)/2;
            
            if (M == 0) { if (nums[0] > nums[M+1]) return 0; }
            else if (M == n - 1) { if (nums[M] > nums[M-1]) return n - 1; }
            else if (nums[M] > nums[M-1] && nums[M] > nums[M+1]) { return M; }
            
            if (nums[M] < nums[M + 1]) L = M + 1;
            else R = M - 1; // same as: else if (num[M] < num[M - 1]) R = M - 1;
            
            // this does not work.
            //if (nums[M] < nums[M - 1]) R = M - 1;
            //else L = M + 1;
        }
        
        return 0;
    }    
}

/**
Find Peak Element
Difficulty: Medium

A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element 
and return its index.

The array may contain multiple peaks, in that case return the 
index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your 
function should return the index number 2.

click to show spoilers.
Note:

Your solution should be in logarithmic complexity.

 */
