# BFS. 
# Time: O(N*E), Space: O(N*E)
from collections import deque

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph : dict[int, Set[List[int]]] = {} # U, [v, w]
        for [u, v, w] in times:
            if u not in graph:
                graph[u] = set()
            graph[u].add((v, w))

        queue = deque([(k)])
        arrivalTime = [sys.maxsize for _ in range(n + 1)]
        arrivalTime[k] = 0

        while queue:
            node = queue.popleft()

            if node in graph:
                for (nextNode, nextTime) in graph[node]:
                    if arrivalTime[node] + nextTime < arrivalTime[nextNode]:
                        arrivalTime[nextNode] = arrivalTime[node] + nextTime
                        queue.append(nextNode)
        
        result = 0
        arrivalTime.pop(0) # remove the first element, the position holder.
        for time in arrivalTime:
            if time == sys.maxsize:
                return -1
            result = max(result, time)

        return result


/**
743. Network Delay Time
Attempted
Medium
Topics
conpanies iconCompanies
Hint

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as 
directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time 
it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive 
the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 */
