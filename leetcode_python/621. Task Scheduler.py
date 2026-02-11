# put all tasks with count on maxHeap.
# each cycle: take each task from heap, put in an array with count -= 1
#   update the cooldown for each task. increment interval if a task is used.
# if no tasks is used, just add in an interval

import heapq
from collections import defaultdict

class Solution2:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        taskCount = defaultdict(int)
        for task in tasks:
            taskCount[task] += 1

        cooldowns = {task: 0 for task in taskCount.keys()}
        
        maxHeap = []
        for task, count in taskCount.items():
            heapq.heappush(maxHeap, (-count, (count, task)))
        
        totalIntervals = 0
        while maxHeap:
            if not 0 in cooldowns.values():
                cooldowns = {key: value - 1 for key, value in cooldowns.items()}
                totalIntervals += 1 
                continue

            newMaxHeap = []
            foundNextTask = False
            while maxHeap:
                _, (count, task) = heapq.heappop(maxHeap)
                if cooldowns[task] == 0 and not foundNextTask:
                    #print(f"next task: {task}")
                    totalIntervals += 1
                    cooldowns[task] = n
                    foundNextTask = True
                    count -= 1
                    if count > 0:
                        heapq.heappush(newMaxHeap, (-count, (count, task)))
                else:
                    if cooldowns[task] > 0:
                        cooldowns[task] -= 1
                    heapq.heappush(newMaxHeap, (-count, (count, task)))

            if not foundNextTask:
                totalIntervals += 1

            maxHeap = newMaxHeap

        return totalIntervals


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        taskCount = defaultdict(int)
        for task in tasks:
            taskCount[task] += 1

        cooldowns = {task: 0 for task in taskCount.keys()}
        
        maxHeap = []
        for task, count in taskCount.items():
            heapq.heappush(maxHeap, (-count, (count, task)))
        
        totalIntervals = 0
        while maxHeap:
            if not 0 in cooldowns.values():
                cooldowns = {key: value - 1 for key, value in cooldowns.items()}
                totalIntervals += 1 
                continue

            elements = []
            foundNextTask = False
            while maxHeap:
                _, (count, task) = heapq.heappop(maxHeap)
                if cooldowns[task] == 0 and not foundNextTask:
                    #print(f"next task: {task}")
                    totalIntervals += 1
                    cooldowns[task] = n
                    foundNextTask = True
                    if count > 1:
                        elements.append((count - 1, task))
                else:
                    if cooldowns[task] > 0:
                        cooldowns[task] -= 1
                    elements.append((count, task))

            if not foundNextTask:
                totalIntervals += 1

            for (count, task) in elements:
                heapq.heappush(maxHeap, (-count, (count, task)))

        return totalIntervals
        

/**
621. Task Scheduler
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval 
can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: 
there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 
3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals 
have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.
 */
