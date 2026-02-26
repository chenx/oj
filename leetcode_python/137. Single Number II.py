class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = 0

        for i in range(32):
            count = 0
            mask = 1 << i
            for num in nums:
                if num & mask:
                    count += 1
            if count % 3 != 0:
                result |= mask
        
        # Do not mistaken sign bit for MSB (most significant bit).
        # See solution 4 at https://leetcode.com/problems/single-number-ii/
        # C++ does not need this.
        if result >= (1 << 31):
            result -= (1 << 32)
            
        return result

/**
137. Single Number II
Solved
Medium
Topics
conpanies iconCompanies

Given an integer array nums where every element appears three times except for one, 
which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.
 */
