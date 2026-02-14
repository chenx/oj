# Maxheap.
# Time: O(n log(k))
# Space: O(k)
import heapq

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        maxHeap = [] # if no point is closer to 0 than top element of maxHeap, add to maxHeap.

        for point in points:
            dist = sqrt(point[0]**2 + point[1]**2)
            if len(maxHeap) < k:
                heapq.heappush(maxHeap, (-dist, point))
            else:
                if dist < - maxHeap[0][0]:
                    heapq.heappop(maxHeap)
                    heapq.heappush(maxHeap, (-dist, point))
        
        result = []
        while maxHeap:
            _, point = heapq.heappop(maxHeap)
            result.append(point)

        return result


/**
973. K Closest Points to Origin
Solved
Medium
Topics
conpanies iconCompanies

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
 */
