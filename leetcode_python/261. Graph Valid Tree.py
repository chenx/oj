class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]

    def find(self, i):
        while self.parent[i] != self.parent[self.parent[i]]:
            i = self.parent[i]
        return self.parent[i]
    
    def union(self, i, j):
        a = self.find(i)
        b = self.find(j)
        if a == b:
            return False

        self.parent[b] = a
        return True

# Time: O(n * alpha(n)), alpha(n) is the inverse Ackermann function, ~ O(1)
# Space: O(n)
class Solution2:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        # This detects if there are multiple parts.
        if len(edges) != n-1:
            return False

        # Union Find detects cycle.
        unionFind = UnionFind(n)
        
        for i, j in edges:
            if not unionFind.union(i, j):
                return False
        return True

        

from collections import deque

# BFS or DFS work here. Time: O(V+E), Space: O(V+E)
class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if n == 1:
            return len(edges) == 0
    
        graph : dict[int, set(int)] = {}
        for [i, j] in edges:
            if i not in graph: graph[i] = set()
            if j not in graph: graph[j] = set()
            graph[i].add(j)
            graph[j].add(i)
        
        start = -1
        for key, val in graph.items():
            if len(val) == 1:
                start = key
                break
        if start == -1:
            return False

        queue = deque([start])
        used = set([start])
        while queue:
            node = queue.popleft()

            for nextNode in graph[node]:
                graph[nextNode].remove(node)
                if nextNode in used:
                    return False
                else:
                    used.add(nextNode)
                    queue.append(nextNode)
        
        return len(used) == n
        

        

/**
261. Graph Valid Tree
Solved
Medium
Topics
conpanies iconCompanies
Hint

You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges 
where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.
 */
