class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        n = len(profits)

        projects = []
        for i in range(n):
            projects.append([capital[i], profits[i]])
        # projects.sort(key= lambda x : x[0])
        projects.sort()

        maxHeap = []
        p = 0
        for i in range(k):
            while p < n and projects[p][0] <= w:
                # heapq.heappush_max(maxHeap, projects[p][1])
                heappush(maxHeap, - projects[p][1])
                p += 1
            
            if len(maxHeap) == 0:
                break;
            # w += heapq.heappop_max(maxHeap)
            w += - heappop(maxHeap)
            
        return w

/**
502. IPO
Hard

Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, 
LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited 
resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best 
way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of 
capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit 
will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return 
the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.
 */
