class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return n
        
        cur = nums[0]
        k = 1
        for i in range(1, n):
            if nums[i] == cur:
                pass
            else:
                cur = nums[i]
                nums[k] = nums[i]
                k += 1
        return k


/**
26. Remove Duplicates from Sorted Array
Solved
Easy
Topics
conpanies iconCompanies
Hint

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that 
each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number 
of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements 
beyond index k - 1 can be ignored.
 */
