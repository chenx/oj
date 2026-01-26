// More efficient.
// From: https://leetcode.com/problems/kth-largest-element-in-an-array/editorial/
class Solution2:
    def findKthLargest(self, nums, k):
        def quick_select(nums, k):
            pivot = random.choice(nums)
            left, mid, right = [], [], []

            for num in nums:
                if num > pivot:
                    left.append(num)
                elif num < pivot:
                    right.append(num)
                else:
                    mid.append(num)
            
            if k <= len(left):
                return quick_select(left, k)
            
            if len(left) + len(mid) < k:
                return quick_select(right, k - len(left) - len(mid))
            
            return pivot
        
        return quick_select(nums, k)
        

// Times out for large input. The C++ version passes but only beats 5% of all submissions.
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def quickSelect(nums, left, right, k):
            if left >= right:
                return
            
            mid = left + (right - left) // 2
            nums[left], nums[mid] = nums[mid], nums[left]
            pivot = nums[left]
            L, R = left + 1, right

            while L <= R:
                while L <= R and nums[L] <= pivot: L += 1
                while L <= R and nums[R] >= pivot: R -= 1
                if L < R:
                    nums[L], nums[R] = nums[R], nums[L]
                    L += 1
                    R -= 1
                else:
                    L += 1
            
            nums[left], nums[R] = nums[R], nums[left]
            if k < R: quickSelect(nums, left, R-1, k)
            elif k > R: quickSelect(nums, R+1, right, k)

        n = len(nums)
        quickSelect(nums, 0, n-1, n-k)
        return nums[n-k]


/**
215. Kth Largest Element in an Array
Medium

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 */
