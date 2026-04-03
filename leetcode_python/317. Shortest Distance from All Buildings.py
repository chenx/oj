from collections import deque
class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        options = [[-1,0], [0,1], [1,0], [0,-1]]
        distSum = [[0] * n for _ in range(m)]
        minDist = 0
        emptyLand = 0
        building = 1

        for i in range(m):
            for j in range(n):
                if grid[i][j] != building:
                    continue
                
                # is a building. start BFS from it.
                q = deque([(i, j, 0)])
                visited = set([(i, j)])
                minDist = sys.maxsize

                while q:
                    x0, y0, dist = q.popleft()

                    for option in options:
                        x, y = x0 + option[0], y0 + option[1]
                        if x >= 0 and x < m and y >= 0 and y < n:
                            if grid[x][y] == emptyLand and not (x, y) in visited:
                                visited.add((x, y))
                                q.append((x, y, dist + 1))

                                grid[x][y] -= 1 # marked as empty land for next cycle.
                                # if not marked, we know it's not reachable from a previous
                                # building and we don't use it.

                                distSum[x][y] += dist + 1
                                if minDist > distSum[x][y]:
                                    minDist = distSum[x][y]
                if minDist == sys.maxsize:
                    return -1
                emptyLand -= 1
        
        return minDist


/**
317. Shortest Distance from All Buildings
Solved
Hard
Topics
conpanies iconCompanies

You are given an m x n grid grid of values 0, 1, or 2, where:

    each 0 marks an empty land that you can pass by freely,
    each 1 marks a building that you cannot pass through, and
    each 2 marks an obstacle that you cannot pass through.

You want to build a house on an empty land that reaches all buildings in the shortest total travel distance. 
You can only move up, down, left, and right.

Return the shortest travel distance for such a house. If it is not possible to build such a house according 
to the above rules, return -1.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.
 */
