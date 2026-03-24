class Solution2:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        def has_conflict(i, colors, graph):
            if not i in graph:
                return False
            for j in graph[i]:
                if colors[j] == 0:
                    colors[j] = - colors[i]
                    if has_conflict(j, colors, graph):
                        return True
                elif colors[j] == colors[i]:
                    return True # has conflict
            return False

        graph : dict[int, set(int)] = {}
        for [a, b] in dislikes:
            if not a in graph: graph[a] = set()
            if not b in graph: graph[b] = set()
            graph[a].add(b)
            graph[b].add(a)
        
        colors = [0] * (n + 1)

        for i in range(n):
            if colors[i] == 0:
                colors[i] = 1
                if has_conflict(i, colors, graph):
                    return False
        return True


class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        def dfs(i, group, graph) -> bool:
            if i in graph:
                for j in graph[i]:
                    if group[j] == 0:
                        group[j] = - group[i]
                        if not dfs(j, group, graph):
                            return False
                    elif group[j] == group[i]:
                        return False
            return True

        graph : dict[int, set[int]] = {}
        for [a, b] in dislikes:
            if a not in graph:
                graph[a] = set()
            if b not in graph:
                graph[b] = set()
            graph[a].add(b)
            graph[b].add(a)
        
        group = [0] * (1 + n)

        for i in range(n):
            if group[i] == 0:
                group[i] = 1
                if not dfs(i, group, graph):
                    return False
        return True


/**
886. Possible Bipartition
Solved
Medium
Topics
conpanies iconCompanies

We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may 
dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled 
ai does not like the person labeled bi, return true if it is possible to split everyone into two groups 
in this way.

 

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].

Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
 */
