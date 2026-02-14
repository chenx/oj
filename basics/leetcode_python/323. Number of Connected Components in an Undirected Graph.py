class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
    
    def find(self, i):
        if i == self.parent[i]:
            return self.parent[i]
        return self.find(self.parent[i])
    
    def union(self, i, j):
        a = self.find(i)
        b = self.find(j)
        if a == b:
            return False
        self.parent[a] = b
        return True

# Union Find.
# Time: O(n + E*alpha(n)), alpha is inverse Ackermann function.
# Space: O(n)
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        unionFind = UnionFind(n)

        components = n
        for edge in edges:
            if unionFind.union(edge[0], edge[1]):
                # If union is false, already in one group; otherwise in different groups.
                components -= 1
        return components


# BFS
# Time: O(E+n)
# Space: O(E+n)
from collections import deque

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph : dict[int, set[int]] = {}
        for a, b in edges:
            if a not in graph: graph[a] = set()
            if b not in graph: graph[b] = set()
            graph[a].add(b)
            graph[b].add(a)
        
        nodes = set([i for i in range(n)])
        groupCount = 0
        
        while nodes:
            node = nodes.pop()
            # print(f"pop random node {node}")
            q = deque([node]) # pop random node.
            groupCount += 1

            while q:
                node = q.popleft()
                # print(f"BFS: get random node {node}")

                if node in graph:
                    for nextNode in graph[node]:
                        if node in graph[nextNode]:
                            graph[nextNode].remove(node)
                        # print(f"BFS: check nextNode {nextNode}")
                        q.append(nextNode)
                        if nextNode in nodes: nodes.remove(nextNode)

        return groupCount


/**
323. Number of Connected Components in an Undirected Graph
Solved
Medium
Topics
conpanies iconCompanies

You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] 
indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.
 */
