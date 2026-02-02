class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0: return 0
        if n == 1: return nums[0]

        # An = max(An-1, An-2 + nums[n])
        DP = [0] * n
        DP[0] = nums[0]
        DP[1] = max(nums[0], nums[1])
        for i in range(2, n):
            DP[i] = max(DP[i-1], DP[i-2] + nums[i])

        return DP[n-1]


/**
198. House Robber
Solved
Medium
Topics
conpanies iconCompanies

You are a professional robber planning to rob houses along a street. Each house has a certain amount 
of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses 
have security systems connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount 
of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
 */
