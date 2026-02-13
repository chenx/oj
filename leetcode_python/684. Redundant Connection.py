class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
    
    def find(self, i):
        if self.parent[i] == i:
            return i
        return self.find(self.parent[i])
    
    def union(self, i, j):
        a = self.find(i)
        b = self.find(j)
        self.parent[a] = b

# 
# Time complexity: O(N⋅α(N))
# We iterate over all edges, and for each edge, we invoke the doUnion function, which has a time complexity of O(α(N)), 
# given that both union by size and path compression are employed. Consequently, the overall time complexity of the algorithm 
# is O(N⋅α(N)). It is important to note that α(N) represents the inverse Ackermann function, which grows so slowly that it is 
# often considered asymptotically constant, or O(1).
# Space complexity: O(N)
#
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        unionFind = UnionFind(n)

        result = []
        for [i, j] in edges:
            if unionFind.find(i-1) != unionFind.find(j-1):
                unionFind.union(i-1, j-1)
            else:
                result = [i, j] # can return directly here. See Solution2.
        return result


class Solution2:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        unionFind = UnionFind(n)

        result = []
        for [i, j] in edges:
            if unionFind.find(i-1) != unionFind.find(j-1):
                unionFind.union(i-1, j-1)
            else:
                return [i, j]


/**
684. Redundant Connection
Solved
Medium
Topics
conpanies iconCompanies

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The 
graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge 
between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple 
answers, return the answer that occurs last in the input.
 */
