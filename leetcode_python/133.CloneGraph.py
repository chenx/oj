"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

# BFS
from collections import deque
class Solution3:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        map = {}
        q = deque([node])
        map[node] = Node(node.val)

        while q:
            next = q.popleft()
            for child in next.neighbors:
                if child not in map:
                    map[child] = Node(child.val)
                    q.append(child)
                map[next].neighbors.append(map[child])

        return map[node]



# DFS
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        visited : dict[Node, Node] = {}
        return clone(node, visited)
      
        def clone(node, visited):
            if node is None:
                return None
            if node in visited:
                return visited[node]
            
            visited[node] = Node(node.val)
            for neighbor in node.neighbors:
                visited[node].neighbors.append(clone(neighbor, visited))

            return visited[node]

        visited = {}
        return clone(node, visited)
    
    

/**
133. Clone Graph
Solved
Medium
Topics
conpanies iconCompanies

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 */
