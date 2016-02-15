// Works. Tested. By: XC.
// Easily modified form solution to Course Schedule.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        
        // remove duplicates in prerequisites.
        vector<pair<int, int>> prereq;
        for (auto p : prerequisites) {
            if (find(prereq.begin(), prereq.end(), p) == prereq.end()) {
                prereq.push_back(p);
            }
        }
        
        vector<int> in(numCourses, 0);
        vector<vector<int>> pre(numCourses, vector<int>(0));
        for (auto p : prereq) {
            in[p.first] ++; // get in-degree.
            pre[p.second].push_back(p.first); // get courses dependent on pair.second.
        }
        
        set<int> courses;
        for (int i = 0; i < numCourses; ++ i) courses.insert(i);
        
        while (! courses.empty()) {
            bool found = false;
            for (auto c : courses) {
                if (in[c] == 0) {
                    ans.push_back(c);
                    found = true;
                    courses.erase(c);
                    for (int i = 0; i < pre[c].size(); ++ i) {
                        if (in[pre[c][i]] > 0) {
                            in[pre[c][i]] --;
                        }
                    }
                }
            }
            if (! found) break;
        }
        
        return courses.empty() ? ans : vector<int>(0);
    }
};


/**
Course Schedule II
Difficulty: Medium

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have 
to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return 
the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. 
If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have 
finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]

There are a total of 4 courses to take. To take course 3 you should have 
finished both courses 1 and 2. Both courses 1 and 2 should be taken after 
you finished course 0. So one correct course order is [0,1,2,3]. Another 
correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not 
adjacency matrices. Read more about how a graph is represented.

click to show more hints.
Hints:

    This problem is equivalent to finding the topological order in a 
    directed graph. If a cycle exists, no topological ordering exists 
    and therefore it will be impossible to take all courses.
    
    Topological Sort via DFS - A great video tutorial (21 minutes) on 
    Coursera explaining the basic concepts of Topological Sort.
    Topological sort could also be done via BFS.

 */
