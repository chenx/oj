class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x : x[1])

        prevEnd = -sys.maxsize - 1
        result = 0
        for x, y in intervals:
            if x < prevEnd:
                result += 1
            else:
                prevEnd = y
        return result

/**
435. Non-overlapping Intervals
Solved
Medium
Topics
conpanies iconCompanies

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of 
intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
 */
