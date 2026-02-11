# use defaultdict, so no need to always have to check key in map.
from collections import defaultdict

class DetectSquares:

    def __init__(self):
        self.xMap : dict[int, dict[list[int], int]] = {} # map<x, map<[x,y], count>>
        

    def add(self, point: List[int]) -> None:
        x, y = point[0], point[1]
        if x not in self.xMap:
            self.xMap[x] = defaultdict(int)
        self.xMap[x][(x, y)] += 1
        

    def count(self, point: List[int]) -> int:
        x, y = point[0], point[1]
        p = (x, y)
        if x not in self.xMap:
            return 0 

        totalCount = 0
        for (x, j), count in self.xMap[x].items():
            if j == y:
                continue # area is 0
            
            side = abs(j - y)

            # other 2 points
            if x + side in self.xMap:
                count1 = self.xMap[x + side][(x + side, y)]
                count2 = self.xMap[x + side][(x + side, j)]
                totalCount += count * count1 * count2

            if x - side in self.xMap:
                count1 = self.xMap[x - side][(x - side, y)]
                count2 = self.xMap[x - side][(x - side, j)]
                totalCount += count * count1 * count2

        return totalCount
        


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)

/**
2013. Detect Squares
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given a stream of points on the X-Y plane. Design an algorithm that:

    Adds new points from the stream into a data structure. Duplicate points are allowed and should be treated 
        as different points.
    Given a query point, counts the number of ways to choose three points from the data structure such that 
        the three points and the query point form an axis-aligned square with positive area.

An axis-aligned square is a square whose edges are all the same length and are either parallel or perpendicular 
to the x-axis and y-axis.

Implement the DetectSquares class:

    DetectSquares() Initializes the object with an empty data structure.
    void add(int[] point) Adds a new point point = [x, y] to the data structure.
    int count(int[] point) Counts the number of ways to form axis-aligned squares with point point = [x, y] as described above.
 */
