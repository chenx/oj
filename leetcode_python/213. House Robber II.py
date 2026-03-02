class Solution:
    def rob(self, nums: List[int]) -> int:
        # A[n] = max(A[n-1], A[n-2] + nums[n])
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        
        A = [0] * n
        B = [0] * n
        A[0] = 0
        A[1] = nums[0]
        B[0] = 0
        B[1] = nums[1]

        for i in range(2, n):
            A[i] = max(A[i-1], A[i-2] + nums[i-1])
            B[i] = max(B[i-1], B[i-2] + nums[i])
        return max(A[n-1], B[n-1])


/**
213. House Robber II
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are a professional robber planning to rob houses along a street. Each house has a certain amount of 
money stashed. All houses at this place are arranged in a circle. That means the first house is the 
neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will 
automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of 
money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
 */
