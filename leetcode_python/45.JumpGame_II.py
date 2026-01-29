class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0
        
        DP = [-1 for _ in range(n)]
        DP[n-1] = 0

        for i in range(n-2, -1, -1):
            if i + nums[i] >= n-1:
                DP[i] = 1
            else:
                for j in range(0, nums[i] + 1): # j = 0; j <= nums[i]; ++ j
                    if i + j < n and DP[i + j] > 0:
                        if DP[i] == -1 or DP[i] > 1 + DP[i + j]:
                            DP[i] = 1 + DP[i + j]

        return DP[0]

/**
45. Jump Game II
Solved
Medium
Topics
conpanies iconCompanies

You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, 
if you are at index i, you can jump to any index (i + j) where:

    0 <= j <= nums[i] and
    i + j < n

Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, 
then 3 steps to the last index.
 */
