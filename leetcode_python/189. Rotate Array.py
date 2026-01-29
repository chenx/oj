class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def reverse(nums, begin, end):
            while begin < end:
                nums[begin], nums[end] = nums[end], nums[begin]
                begin += 1
                end -= 1
        
        n = len(nums)
        k %= n
        reverse(nums, 0, n-1)
        reverse(nums, 0, k-1)
        reverse(nums, k, n-1)
        

/**
189. Rotate Array
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 */
