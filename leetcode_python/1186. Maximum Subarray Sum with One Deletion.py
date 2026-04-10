class Solution3:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        if n == 0:
            return 0
        if n == 1:
            return arr[0]

        left, right = [0] * n, [0] * n
        
        left[0] = arr[0]
        for i in range(1, n):
            left[i] = max(left[i-1], 0) + arr[i]
            
        maxSum = max(left) # initialize maxSum

        right[n-1] = arr[n-1]
        for i in range(n-2, -1, 0-1):
            right[i] = max(right[i+1], 0) + arr[i]

        maxSum = max(maxSum, left[1], right[n-2])
        for i in range(1, n-1):
            maxSum = max(maxSum, left[i-1] + right[i+1])

        return maxSum


# See https://algo.monster/liteproblems/1186
class Solution2:
    def maximumSum(self, arr: List[int]) -> int:
        def maxSubArray(nums) -> int:
            sum = nums[0]
            maxSum = nums[0]

            for i in range(1, len(nums)):
                if sum < 0:
                    sum = 0
                sum += nums[i]
                maxSum = max(maxSum, sum)
            return maxSum
        
        n = len(arr)
        if n == 0:
            return 0
        if n == 1:
            return arr[0]
        maxSum = maxSubArray(arr)

        left, right = [0] * n, [0] * n
        
        left[0] = arr[0]
        for i in range(1, n):
            left[i] = max(left[i-1], 0) + arr[i]
            # if left[i-1] < 0:
            #     left[i] = arr[i]
            # else:
            #     left[i] = left[i-1] + arr[i]
        
        right[n-1] = arr[n-1]
        for i in range(n-2, -1, 0-1):
            right[i] = max(right[i+1], 0) + arr[i]

        maxSum = max(maxSum, left[1], right[n-2])
        for i in range(1, n-1):
            maxSum = max(maxSum, left[i-1] + right[i+1])

        return maxSum


# This times out for large input.
# Time: O(n^2)
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        def maxSubArray(nums) -> int:
            sum = nums[0]
            maxSum = nums[0]

            for i in range(1, len(nums)):
                if sum < 0:
                    sum = 0
                sum += nums[i]
                maxSum = max(maxSum, sum)
            return maxSum
        
        n = len(arr)
        if n == 0:
            return 0
        if n == 1:
            return arr[0]
        maxSum = maxSubArray(arr)

        for i in range(n):
            newArr = arr[:]
            newArr.pop(i)
            maxSum = max(maxSum, maxSubArray(newArr))

        return maxSum


/**
1186. Maximum Subarray Sum with One Deletion
Attempted
Medium
Topics
conpanies iconCompanies
Hint

Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) 
with at most one element deletion. In other words, you want to choose a subarray and optionally 
delete one element from it so that there is still at least one element left and the sum of the 
remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

 

Example 1:

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes 
the maximum value.

Example 2:

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.

Example 3:

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, 
then get an empty subarray to make the sum equals to 0.
 */
