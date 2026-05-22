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
