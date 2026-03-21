# Time: O(n)
# Space: O(n) for the sumCountMap.
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixSum = 0
        sumCountMap : dict[int, int] = {}
        sumCountMap[0] = 1
        result = 0

        for i in range(len(nums)):
            prefixSum += nums[i]
            result += sumCountMap[prefixSum - k] if (prefixSum - k) in sumCountMap else 0
            sumCountMap[prefixSum] = sumCountMap.get(prefixSum, 0) + 1
        
        return result


/**
560. Subarray Sum Equals K
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 */
