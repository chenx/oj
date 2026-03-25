from collections import defaultdict
class Solution2:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixSum = 0
        sumCountMap : dict[int, int] = defaultdict(int) # {}
        sumCountMap[0] = 1
        result = 0

        for i in range(len(nums)):
            prefixSum += nums[i]
            result += sumCountMap[prefixSum - k]
            sumCountMap[prefixSum] += 1
        
        return result


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


========

A variation of this problem:

Given an array, return whether a contiguous subsequence can sum to target. 

1) If all numbers are positive, use a sliding window. 
2) If some numbers are negative, use prefix sum plus hashmap.

# 1) sliding window   
def getSubsequence(input, target): 
   sum = 0
   left = 0
   for i in range(len(input)):
       sum += input[i]

       while left < i and sum > target:
           sum -= input[left]
           left += 1

       if sum == target:
           return True
      
   return False


# 2) prefix sum + hashmap
def getSubsequence(input, target):
   prefixSum = 0
   map : dict[int, int] = {}
   map[0] = 1

   for num in input:
     prefixSum += num
     if (prefixSum - target) in map:
       return True
     map[prefixSum] = 1
   
   return False

 */
