class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        indexMap : Dict[char, int] = {}

        for i in range(len(nums)):
            if nums[i] in indexMap:
               return [i, indexMap[nums[i]]]
            else:
                indexMap[target - nums[i]] = i
        
        return [0, 0]


/**
1. Two Sum
Solved
Easy
Topics
conpanies iconCompanies
Hint

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
 */
