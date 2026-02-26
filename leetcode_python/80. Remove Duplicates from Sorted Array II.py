class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        
        k = 1
        ct = 1
        cur = nums[0]
        for i in range(1, n):
            if nums[i] == cur:
                if ct == 2:
                    continue
                ct += 1
                nums[k] = cur
                k += 1
            else:
                ct = 1
                cur = nums[i]
                nums[k] = cur
                k += 1
        
        return k

/**
80. Remove Duplicates from Sorted Array II
Solved
Medium
Topics
conpanies iconCompanies

Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that 
each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the 
result be placed in the first part of the array nums. More formally, if there are k elements after 
removing the duplicates, then the first k elements of nums should hold the final result. It does not 
matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place 
with O(1) extra memory.
 */
