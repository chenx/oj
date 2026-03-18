class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort()

        for i in range(1, len(intervals)):
            a, b = intervals[i-1], intervals[i]
            if a[1] > b[0]:
                return False
        return True

/**
252. Meeting Rooms
Solved
Easy
Topics
conpanies iconCompanies

Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
 */
