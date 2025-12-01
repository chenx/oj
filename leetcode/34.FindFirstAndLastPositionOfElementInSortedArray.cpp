// Binary search.
// Time: O(logn)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);

        result[0] = getStartIndex(nums, target);
        result[1] = getStartIndex(nums, target + 1) - 1;

        if (result[1] < 0 || result[1] >= nums.size() || nums[result[1]] != target) {
            return {-1, -1};
        }
        return result;
    }

    int getStartIndex(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, ret = nums.size();
        while (left <= right) {
            int mid = left + (right - left)/2;

            if (nums[mid] >= target) {
                ret = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ret;
    }
};


/**
34. Find First and Last Position of Element in Sorted Array
Medium

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 */
