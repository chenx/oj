// From: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/editorial
// O(n) time, O(1) space.
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;

        int inversionCount = 0;

        // For every pair, count the number of inversions.
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                ++inversionCount;
                if (inversionCount > 1) return false;
            }
        }

        // Also check between the last and
        // the first element due to rotation
        if (nums[n - 1] > nums[0]) {
            ++inversionCount;
        }

        return inversionCount <= 1;
    }
};


/**
1752. Check if Array Is Sorted and Rotated
Easy

Given an array nums, return true if the array was originally sorted in non-decreasing order, 
then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that 
B[i] == A[(i+x) % A.length] for every valid index i.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].

Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 */
