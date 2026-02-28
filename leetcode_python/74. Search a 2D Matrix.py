class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n, left = len(matrix), len(matrix[0]), 0
        right = m * n - 1

        while left <= right and 1:
            mid = left + (right - left) // 2
            row, col = mid // n, mid % n

            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                right = mid - 1
            else:
                left = mid + 1
        
        return False


/**
74. Search a 2D Matrix
Solved
Medium
Topics
conpanies iconCompanies

You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
 */
