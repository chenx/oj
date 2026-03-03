class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def getFirstIndex(nums, target):
            left, right, ret = 0, n-1, n

            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] >= target:
                    ret = mid
                    right = mid - 1
                else:
                    left = mid + 1
            return ret
        
        n = len(nums)
        ret = [
            getFirstIndex(nums, target), 
            getFirstIndex(nums, target+1)-1]
        if ret[1] >= 0 and ret[1] < n and nums[ret[1]] == target:
            return ret
        return [-1, -1]


/**
34. Find First and Last Position of Element in Sorted Array
Solved
Medium
Topics
conpanies iconCompanies

Given an array of integers nums sorted in non-decreasing order, find the starting and 
ending position of a given target value.

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
