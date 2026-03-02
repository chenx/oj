class Solution2:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        inDegree = [0] * numCourses
        outDegree = [[] for _ in range(numCourses)]

        for p in prerequisites:
            inDegree[p[0]] += 1
            outDegree[p[1]].append(p[0])

        q = collections.deque()
        for course in range(numCourses):
            if inDegree[course] == 0:
                q.append(course)
        
        courses = []
        while q:
            course = q.popleft()
            courses.append(course)

            for nextCourse in outDegree[course]:
                inDegree[nextCourse] -= 1

                if inDegree[nextCourse] == 0:
                    q.append(nextCourse)

        return courses if len(courses) == numCourses else []


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        inDegree: dict[int, set[int]] = {}
        outDegree: dict[int, set[int]] = {}

        for p in prerequisites:
            if p[0] not in inDegree:
                inDegree[p[0]] = set()
            if p[1] not in outDegree:
                outDegree[p[1]] = set()
            inDegree[p[0]].add(p[1])
            outDegree[p[1]].add(p[0])
        
        q = deque()
        for course in range(numCourses):
            if not course in inDegree:
                q.append(course)
        
        visited = []
        while q:
            course = q.popleft()
            visited.append(course)

            if course in outDegree:
                for nextCourse in outDegree[course]:
                    inDegree[nextCourse].remove(course)
                    if len(inDegree[nextCourse]) == 0:
                        q.append(nextCourse)

        return visited if len(visited) == numCourses else []


/**
210. Course Schedule II
Solved
Medium
Topics
conpanies iconCompanies
Hint

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array 
prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any 
of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the 
correct course order is [0,1].
 */
