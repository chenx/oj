
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        arr = []
        n = len(nums)

        for i in range(n):
            if len(arr) == 0 or nums[i] > arr[-1]:
                arr.append(nums[i])
            else:
                left, right = 0, len(arr) - 1
                while left <= right:
                    mid = left + (right - left) // 2
                    if arr[mid] >= nums[i]:
                        right = mid - 1
                    else:
                        left = mid + 1
                
                arr[left] = nums[i]
        
        return len(arr)



/**
300. Longest Increasing Subsequence
Medium

Given an integer array nums, return the length of the longest strictly increasing .

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 */
