class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)

        maxLen = 0
        while len(numSet) > 0:
            n = numSet.pop()

            count = 1
            m = n+1
            while m in numSet:
                count += 1
                numSet.remove(m)
                m += 1

            m = n-1
            while m in numSet:
                count += 1
                numSet.remove(m)
                m -= 1
            
            maxLen = max(maxLen, count)
            
        return maxLen


/**
128. Longest Consecutive Sequence
Solved
Medium
Topics
conpanies iconCompanies

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:

Input: nums = [1,0,1,2]
Output: 3
 */
