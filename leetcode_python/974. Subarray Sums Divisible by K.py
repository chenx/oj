from collections import defaultdict
class Solution2:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefixSum = 0
        modGroupMap : dict[int, int] = defaultdict(int) 
        modGroupMap[0] = 1
        result = 0

        for i in range(len(nums)):
            prefixSum += nums[i]
            mod = ((prefixSum) % k + k) % k
            result += modGroupMap[mod]
            modGroupMap[mod] += 1

        return result


# Time: O(n), n = len(nums)
# Space: O(k)
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefixSum = 0
        modGroupMap = {}
        modGroupMap[0] = 1
        result = 0

        for i in range(len(nums)):
            prefixSum += nums[i]
            mod = ((prefixSum) % k + k) % k
            result += modGroupMap[mod] if mod in modGroupMap else 0
            modGroupMap[mod] = modGroupMap.get(mod, 0) + 1
            
        return result


/**
974. Subarray Sums Divisible by K
Solved
Medium
Topics
conpanies iconCompanies

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:

Input: nums = [5], k = 9
Output: 0
 */
