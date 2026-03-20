# Similar to Solution3.
# Time: O(n * 2^n)
# Space: O(1)
# e.g., n = 3, then 2^3 = 8 positions: [000,001,010,011,100,101,110,111], 
# For each position, pick a number to fill in if corresponding digit is 1.
class Solution32:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        n = len(nums)
        size = 1 << n

        for i in range(size): # 2^n
            result.append([])
            for j in range(n):
                if i & (1 << j):
                    result[-1].append(nums[j])
        return result


# Time: O(n * 2^n)
# Space: O(1). 
# Appending a list to a list of lists using the append() method is an O(1) amortized time complexity operation. 
# The size or content of the inner list does not affect the time complexity of the append() operation itself.
class Solution3:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        n = len(nums)
        size = 1 << n

        for i in range(size):
            item = []
            for j in range(n):
                if i & (1 << j):
                    item.append(nums[j])
            result.append(item)
        return result


# Time: O(n * 2^n). There are 2^n subsets, each has n/2 elements on average.
# Space: O(1)
class Solution2:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]

        for num in nums:
            count = len(result)
            for i in range(count):
                result.append(result[i].copy()) # or result[i][:]
                result[-1].append(num)
        return result


# Time: O(n * 2^n). To generate all subsets and then copy them into the output list.
#                   There are 2^n subsets, each has n/2 elements on average.
# Space: O(n * 2^n). For space used by new_items.
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]

        for num in nums:
            new_items = []
            for row in result:
                new_items.append(row[:])
                new_items[-1].append(num)
            result += new_items
        return result
      

/**
78. Subsets
Solved
Medium
Topics
conpanies iconCompanies

Given an integer array nums of unique elements, return all possible (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
 */
