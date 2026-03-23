# Time: O(n)
# Space: O(1)
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        minVal = sys.maxsize
        maxVal = - sys.maxsize - 1

        found = False
        for i in range(1, n):
            if nums[i-1] > nums[i]:
                found = True
            if found:
                minVal = min(minVal, nums[i])

        found = False
        for i in range(n-2, -1, -1):
            if nums[i] > nums[i+1]:
                found = True
            if found:
                maxVal = max(maxVal, nums[i])
        
        x, y = 0, n-1
        while x < n and nums[x] <= minVal:
            x += 1
        while y >= 0 and nums[y] >= maxVal:
            y -= 1
        return y-x+1 if y >= x else 0


/**
581. Shortest Unsorted Continuous Subarray
Solved
Medium
Topics
conpanies iconCompanies

Given an integer array nums, you need to find one continuous subarray such that if you only sort 
this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted 
in ascending order.

Example 2:

Input: nums = [1,2,3,4]
Output: 0

Example 3:

Input: nums = [1]
Output: 0
 */
