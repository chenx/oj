class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        result = []

        nums.sort()
        n = len(nums)
        for i in range(0, n-2):
            if i > 0 and nums[i-1] == nums[i]:
                continue
            
            j, k = i+1, n-1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0:
                    result.append([nums[i], nums[j], nums[k]])
                    while j < k:
                        j += 1
                        if nums[j - 1] != nums[j]:
                            break
                elif sum < 0:
                    j += 1
                else:
                    k -= 1
        return result


/**
15. 3Sum
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, 
and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
 */
