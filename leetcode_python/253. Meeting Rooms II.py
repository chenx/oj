import heapq
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        # Sort by start. Use a minHeap of meeting ends points.
        # For each new meeting, if its start >= end of the meeitng that ends first,
        # remove that meeting from minHeap, add the new meeting's end to minHeap.
        minHeap = []

        intervals.sort()
        for interval in intervals:
            if len(minHeap) > 0 and interval[0] >= minHeap[0]:
                # no overlap with the meeting that ends first, can remove this meeting.
                heapq.heappop(minHeap) 
            heapq.heappush(minHeap, interval[1])
        
        return len(minHeap)

/**
253. Meeting Rooms II
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number 
of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 */
