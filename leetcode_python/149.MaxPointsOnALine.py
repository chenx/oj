class Solution2:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n <= 2:
            return n
        
        result = 2
        for i in range(n-1):
            slopeCount = {}
            verticalCount = 0
            for j in range(i+1, n):
                if points[i][0] == points[j][0]:
                    verticalCount += 1
                else:
                    slope = (points[i][1] - points[j][1]) / (points[i][0] - points[j][0])
                    slopeCount[slope] = slopeCount.get(slope, 0) + 1
            
            for slope, count in slopeCount.items():
                result = max(result, count + 1)
            result = max(result, verticalCount + 1)

        return result 
        

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        if n <= 1:
            return n

        maxNum = 0
        for i in range(n-1):
            p = points[i]

            slopes = {} # or use: dict()
            for j in range(i+1, n):
                q = points[j]
                slope = sys.maxsize if (p[0] == q[0]) else (1.0 * (p[1] - q[1]) / (p[0] - q[0]))
                slopes[slope] = slopes.get(slope, 0) + 1
            
                # for _, count in slopes.items():
                for count in slopes.values():
                    maxNum = max(maxNum, 1 + count)
        
        return maxNum

/**
149. Max Points on a Line
Hard

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
return the maximum number of points that lie on the same straight line.
 */
