class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        sum = 0
        minLen = 0
        start = 0

        for i in range(len(nums)):
            sum += nums[i]
            while sum >= target:
                length = i - start + 1
                if minLen == 0 or minLen > length:
                    minLen = length

                sum -= nums[start]
                start += 1

        return minLen


/**
209. Minimum Size Subarray Sum
Solved
Medium
Topics
conpanies iconCompanies

Given an array of positive integers nums and a positive integer target, return the minimal length 
of a whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 */
