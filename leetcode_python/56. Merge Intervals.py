class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        if n == 0:
            return []

        intervals.sort() #(key=lambda x : x[0])

        result = []
        for i in range(1, n):
            if intervals[i-1][1] < intervals[i][0]:
                result.append(intervals[i-1])
            elif intervals[i-1][1] <= intervals[i][1]:
                intervals[i][0] = intervals[i-1][0]
            else:
                intervals[i][0] = intervals[i-1][0]
                intervals[i][1] = intervals[i-1][1]
        result.append(intervals[n-1])

        return result

/**
56. Merge Intervals
Solved
Medium
Topics
conpanies iconCompanies

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
 */
