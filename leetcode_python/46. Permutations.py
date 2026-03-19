class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def perm(result, nums, pos):
            if pos == len(nums):
                result.append(nums[:])
                return
            
            for i in range(pos, len(nums)):
                nums[i], nums[pos] = nums[pos], nums[i]
                perm(result, nums, pos + 1)
                nums[i], nums[pos] = nums[pos], nums[i]
        
        result = []
        perm(result, nums, 0)
        return result


/**
46. Permutations
Solved
Medium
Topics
conpanies iconCompanies

Given an array nums of distinct integers, return all the possible . You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]
 */
