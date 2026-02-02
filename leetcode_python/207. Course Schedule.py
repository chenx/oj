# Kahn's topological algorithm of cycle detections
class Solution2:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        inDegree = [0] * numCourses
        outDegree = [[] for _ in range(numCourses)]

        for p in prerequisites:
            inDegree[p[1]] += 1
            outDegree[p[0]].append(p[1])
        
        q = collections.deque()
        for course in range(numCourses):
            if inDegree[course] == 0:
                q.append(course)
        visited = []

        while q:
            course = q.popleft()
            visited.append(course)

            for nextCourse in outDegree[course]:
                inDegree[nextCourse] -= 1

                if inDegree[nextCourse] == 0:
                    q.append(nextCourse)

        return len(visited) == numCourses


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        inDegree : dict[int, set(int)] = {}
        outDegree : dict[int, set(int)] = {}

        for p in prerequisites:
            if p[1] not in inDegree:
                inDegree[p[1]] = set()
            if p[0] not in outDegree:
                outDegree[p[0]] = set()
            inDegree[p[1]].add(p[0])
            outDegree[p[0]].add(p[1])
        
        q = collections.deque()
        for course in range(numCourses):
            if course not in inDegree:
                q.append(course)
        visited = set()

        while len(q) > 0:
            course = q.popleft()
            visited.add(course)

            if course in outDegree:
                for nextCourse in outDegree[course]:
                    inDegree[nextCourse].remove(course)

                    if len(inDegree[nextCourse]) == 0:
                        q.append(nextCourse)

        return len(visited) == numCourses

/**
207. Course Schedule
Solved
Medium
Topics
conpanies iconCompanies
Hint

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given 
an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if 
you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
 */
