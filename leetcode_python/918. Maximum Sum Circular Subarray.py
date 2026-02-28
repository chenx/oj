class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        def maxSubArray(nums: List[int]) -> int:
            n = len(nums)
            if n == 0:
                return 0
            
            maxSum = nums[0]
            sum = nums[0]
            for i in range(1, n):
                if sum < 0:
                    sum = 0
                sum += nums[i]
                maxSum = max(maxSum, sum)
            return maxSum
        
        maxSum1 = maxSubArray(nums)
        total = sum(nums)
        for i in range(len(nums)):
            nums[i] = - nums[i]
        
        maxSum2 = maxSubArray(nums)
        if total + maxSum2 == 0:
            return maxSum1
        return max(maxSum1, total + maxSum2)

/**
918. Maximum Sum Circular Subarray
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given a circular integer array nums of length n, return the maximum possible sum of a 
non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. 
Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element 
of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. 
Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist 
i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
 */
