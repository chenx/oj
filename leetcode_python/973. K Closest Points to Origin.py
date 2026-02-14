# Quick sort
# Time: O(n), Space: O(n)
class Solution2:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        def dist(point):
            return (point[0]**2 + point[1]**2) # no need to use sqrt.
        arr = [[dist(p), p] for p in points]
        
        self.quickSelect(arr, 0, len(arr)-1, k)

        result = []
        for i in range(k):
            result.append(arr[i][1])
        return result

    def quickSelect(self, arr, left, right, k):
        if left >= right:
            return
        
        mid = left + (right - left) // 2
        arr[left], arr[mid] = arr[mid], arr[left]
        pivot = arr[left]
        L, R = left + 1, right

        while L <= R:
            # while L <= R and arr[L] <= pivot: 
            while L <= R and arr[L][0] <= pivot[0]:
                L += 1
            # while L <= R and arr[R] >= pivot: 
            while L <= R and arr[R][0] >= pivot[0]:
                R -= 1
            if L < R:
                arr[L], arr[R] = arr[R], arr[L]
                L += 1
                R -= 1
            else:
                L += 1
        
        arr[left], arr[R] = arr[R], arr[left]
        if k < R:
            self.quickSelect(arr, left, R-1, k)
        elif k > R:
            self.quickSelect(arr, R+1, right, k)
        # self.quickSelect(arr, left, R-1, k)
        # self.quickSelect(arr, R+1, right, k)


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
