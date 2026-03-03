
class Solution2:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        def addPairToGraph(graph, a, b):
            if not a in graph:
                graph[a] = []
            if not b in graph:
                graph[b] = []
            graph[a].append(b)
            graph[b].append(a)

        def getGraph(root, graph):
            if root.left:
                addPairToGraph(graph, root.val, root.left.val)
                getGraph(root.left, graph)
            if root.right:
                addPairToGraph(graph, root.val, root.right.val)
                getGraph(root.right, graph)


        if not root:
            return 0

        graph : dict[int, list[int]] = {}
        getGraph(root, graph)

        q = collections.deque([(start)])
        used = set([start])
        time = -1

        while q:
            time += 1
            count = len(q)
            for _ in range(count):
                node = q.popleft()
                if node in graph: # node not in grah happens if root has no children.
                    for nextNode in graph[node]:
                        if not nextNode in used:
                            used.add(nextNode)
                            q.append((nextNode))
        return time


# Time: O(n), n = number of nodes. Each node is visited once.
# Space: O(n) for graph of the tree. A node with n nodes has n-1 edges, so 2*(n-1) relations in graph.
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        def addPairToGraph(graph, a, b):
            if not a in graph:
                graph[a] = []
            if not b in graph:
                graph[b] = []
            graph[a].append(b)
            graph[b].append(a)

        def getGraph(root, graph):
            if root.left:
                addPairToGraph(graph, root.val, root.left.val)
                getGraph(root.left, graph)
            if root.right:
                addPairToGraph(graph, root.val, root.right.val)
                getGraph(root.right, graph)


        if not root:
            return 0

        graph : dict[int, list[int]] = {}
        getGraph(root, graph)

        q = collections.deque([(start, 0)])
        used = set([start])
        time = 0

        while q:
                node, curTime = q.popleft()
                if node in graph: # node not in grah happens if root has no children.
                    for nextNode in graph[node]:
                        if not nextNode in used:
                            used.add(nextNode)
                            q.append((nextNode, curTime + 1))
                            time = max(time, curTime + 1)
        return time


/**
2385. Amount of Time for Binary Tree to Be Infected
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given the root of a binary tree with unique values, and an integer start. 
At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

    The node is currently uninfected.
    The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.
 */
