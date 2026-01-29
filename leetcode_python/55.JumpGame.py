class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        if n <= 1:
            return True
        
        target = n-1
        # Notice it's n-2 to -1, since -1 is not included, so it ends at 0!!!
        for i in range(n-2, -1, -1):
            if i + nums[i] >= target:
                target = i
        
        return target == 0

/**
55. Jump Game
Solved
Medium
Topics
conpanies iconCompanies

You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
 */
