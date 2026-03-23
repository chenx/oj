# 2 pointers. Simulation.
# Time: O(n)
# Space: O(1)
class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        result = 0
        i, j, n = 0, 0, len(arr)
        while i < len(arr):
            j = i
            if j < n-1 and arr[j] < arr[j+1]:
                while j < n-1 and arr[j] < arr[j+1]:
                    j += 1

                if j < n-1 and arr[j] > arr[j+1]:
                    while j < n-1 and arr[j] > arr[j+1]:
                        j += 1
                    result = max(result, j - i + 1)
            
            i = max(i + 1, j)
        return result


/**
845. Longest Mountain in Array
Solved
Medium
Topics
conpanies iconCompanies

You may recall that an array arr is a mountain array if and only if:

    arr.length >= 3
    There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
        arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given an integer array arr, return the length of the longest subarray, which is a mountain. 
Return 0 if there is no mountain subarray.

 

Example 1:

Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

Example 2:

Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
 */
