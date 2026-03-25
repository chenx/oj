class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> List[int]:
        tuples = []

        n1, n2 = len(workers), len(bikes)
        for i in range(n1):
            for j in range(n2):
                dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])
                tuples.append( [dist, i, j] )
        
        tuples.sort()
        # This also works:
        # tuples.sort(key=lambda x : (x[0], x[1], x[2]))

        workerStatus = [-1] * n1
        bikeStatus = [-1] * n2
        count = 0
        for k in range(len(tuples)):
            dist, i, j = tuples[k]
            if workerStatus[i] == -1 and bikeStatus[j] == -1:
                workerStatus[i] = j
                bikeStatus[j] = i
                count += 1
                if count == n1: 
                    break
        return workerStatus
                


/**
1057. Campus Bikes
Solved
Medium
Topics
conpanies iconCompanies
Hint

On a campus represented on the X-Y plane, there are n workers and m bikes, with n <= m.

You are given an array workers of length n where workers[i] = [xi, yi] is the position of the ith worker. 
You are also given an array bikes of length m where bikes[j] = [xj, yj] is the position of the jth bike. 
All the given positions are unique.

Assign a bike to each worker. Among the available bikes and workers, we choose the (workeri, bikej) pair 
with the shortest Manhattan distance between each other and assign the bike to that worker.

If there are multiple (workeri, bikej) pairs with the same shortest Manhattan distance, we choose the pair 
with the smallest worker index. If there are multiple ways to do that, we choose the pair with the smallest 
bike index. Repeat this process until there are no available workers.

Return an array answer of length n, where answer[i] is the index (0-indexed) of the bike that the ith 
worker is assigned to.

The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.
 */
