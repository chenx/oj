# BFS
# Time: O(N + E*K), Space: O(N + E*K)
from collections import deque
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = {}
        for [frm, to, price] in flights:
            if frm not in graph:
                graph[frm] = set()
            graph[frm].add((to, price))
        
        prices = [sys.maxsize for _ in range(n)]
        q = deque([(src, 0)])
        prices[src] = 0

        while q and k >= 0:
            k -= 1
            count = len(q)
            for i in range(count):
                node, price = q.popleft()
                if node in graph:
                    for nextNode, nextPrice in graph[node]:
                        if price + nextPrice < prices[nextNode]:
                            prices[nextNode] = price + nextPrice
                            q.append((nextNode, prices[nextNode]))

        return -1 if prices[dst] == sys.maxsize else prices[dst] 


/**
787. Cheapest Flights Within K Stops
Solved
Medium
Topics
conpanies iconCompanies

There are n cities connected by some number of flights. You are given an array flights where 
flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi 
with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst 
with at most k stops. If there is no such route, return -1.

 

Example 1:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
 */
