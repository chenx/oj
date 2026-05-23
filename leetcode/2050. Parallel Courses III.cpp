// Similar to Solution.
// Note that in relations, course numbers are [1, .. n], when using the time array, use time[course - 1].
class Solution2 {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, set<int>> inDegree, outDegree;
        for (auto& e : relations) {
            inDegree[e[1]].insert(e[0]);
            outDegree[e[0]].insert(e[1]);
        }

        queue<int> q;
        unordered_map<int, int> maxTime;
        // vector<int> maxTime(n + 1, 0);
        for (int i = 1; i <= n; ++ i) {
            if (inDegree[i].empty()) {
                q.push(i);
                maxTime[i] = time[i - 1];
            }
        }

        while (! q.empty()) {
            int course = q.front();
            q.pop();

            for (int nextCourse : outDegree[course]) {
                maxTime[nextCourse] = max(maxTime[nextCourse], maxTime[course] + time[nextCourse - 1]);
                inDegree[nextCourse].erase(course);
                if (inDegree[nextCourse].empty()) {
                    q.push(nextCourse);
                }
            }
        }

        int result = 0;
        for (int i = 1; i <= n; ++ i) {
            result = max(maxTime[i], result);
        }
        return result;
    }
};


// From: https://leetcode.com/problems/parallel-courses-iii/editorial/
// Time, Space: O(V + E)
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) { 
        unordered_map<int, vector<int>> graph;
        vector<int> indegree = vector(n, 0);

        for (vector<int>& edge: relations) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            graph[x].push_back(y);
            indegree[y]++;
        }
        
        queue<int> queue;
        vector<int> maxTime = vector(n, 0);
        
        for (int node = 0; node < n; node++) {
            if (indegree[node] == 0) {
                queue.push(node);
                maxTime[node] = time[node];
            }
        }
        
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            for (int neighbor: graph[node]) {
                maxTime[neighbor] = max(maxTime[neighbor], maxTime[node] + time[neighbor]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    queue.push(neighbor);
                }
            }
        }
        
        int ans = 0;
        for (int node = 0; node < n; node++) {
            ans = max(ans, maxTime[node]);
        }
        
        return ans;
    }
};


/**
2050. Parallel Courses III
Solved
Hard
Topics
conpanies iconCompanies
Hint

You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 
2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has 
to be completed before course nextCoursej (prerequisite relationship). Furthermore, you are given a 0-indexed 
integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.

You must find the minimum number of months needed to complete all the courses following these rules:

    You may start taking a course at any time if the prerequisites are met.
    Any number of courses can be taken at the same time.

Return the minimum number of months needed to complete all the courses.

Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).

 

Example 1:

Input: n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
Output: 8
Explanation: The figure above represents the given graph and the time required to complete each course. 
We start course 1 and course 2 simultaneously at month 0.
Course 1 takes 3 months and course 2 takes 2 months to complete respectively.
Thus, the earliest time we can start course 3 is at month 3, and the total time required is 3 + 5 = 8 months.
 */
