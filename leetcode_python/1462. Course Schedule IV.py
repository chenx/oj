# Time: O(N^3 + Q). N = numCourses, Q = len(queries)
# Space: O(N^2)
class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        isPre = [[False] * numCourses for _ in range(numCourses)]
        for p in prerequisites:
            isPre[p[0]][p[1]] = True
        
        // Floyd-warshall algorithm.
        for k in range(numCourses):
            for i in range(numCourses):
                for j in range(numCourses):
                    if isPre[i][k] and isPre[k][j]:
                        isPre[i][j] = True
        
        result = []
        for q in queries:
            result.append(isPre[q[0]][q[1]])
        return result

/**
1462. Course Schedule IV
Solved
Medium
Topics
conpanies iconCompanies
Hint

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given 
an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if 
you want to take course bi.

    For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.

Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite 
of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer 
whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
 */
