import heapq

class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        # self.rank = [1 for _ in range(n)]
    
    def find(self, i):
        while self.parent[i] != self.parent[self.parent[i]]:
            i = self.parent[i]
        return self.parent[i]
        # if i == self.parent[i]:
        #     return i
        # return self.find(self.parent[i])

    def union(self, i, j):
        a = self.find(i)
        b = self.find(j)
        self.parent[b] = a

        # if self.rank[a] > self.rank[b]:
        #     self.parent[b] = a
        #     self.rank[a] += self.rank[b]
        # else:
        #     self.parent[a] = b
        #     self.rank[b] = self.rank[a]


# Time: O(n^2 * log(n))
# Space: O(n^2)
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # kruskal's algorithm.
        # create minHeap of [cost, a, b]. get from heap, 
        # add to result if adding a,b don't form a cycle (a, b not in one set)
        minHeap = []
        n = len(points)
        for i in range(n-1):
            for j in range(i+1, n):
                dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                heapq.heappush(minHeap, (dist, [dist, i, j]))

        unionFind = UnionFind(n)

        minCost = 0
        edgeCount = 0
        while edgeCount < n-1:
            _, [dist, i, j] = heapq.heappop(minHeap)

            if unionFind.find(i) != unionFind.find(j):
                unionFind.union(i, j)
                minCost += dist
                edgeCount += 1

        return minCost


/**
1584. Min Cost to Connect All Points
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, 
where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path 
between any two points.
 */
