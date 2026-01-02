class Solution7 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int>> inDegree, outDegree;
        for (auto p : prerequisites) {
            inDegree[p[0]].insert(p[1]);
            outDegree[p[1]].insert(p[0]);
        }

        queue<int> q;
        for (int course = 0; course < numCourses; ++ course) {
            if (inDegree[course].empty()) q.push(course);
        }

        int courseCount = 0;
        while (! q.empty()) {
            int curCourse = q.front();
            q.pop();

            ++ courseCount;

            for (auto nextCourse : outDegree[curCourse]) {
                inDegree[nextCourse].erase(curCourse);
                if (inDegree[nextCourse].empty()) {
                    q.push(nextCourse);
                }
            }
        }
        return courseCount == numCourses;
    }
};

// BFS (Topological Sort Using Kahn's Algorithm).
// Here, n be the number of courses and m be the size of prerequisites.
// Time complexity: O(m+n)
// Space complexity: O(m+n)
class Solution6 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        set<int> courses;
        for (int i = 0; i < numCourses; ++ i) courses.insert(i);

        map<int, set<int>> in, out;
        for (auto pre : prerequisites) {
            in[pre[0]].insert(pre[1]);
            out[pre[1]].insert(pre[0]);
        }

        queue<int> q;

        for (int course : courses) {
            if (in[course].size() == 0) {
                q.push(course);
            }
        }

        int count = 0;
        while (! q.empty()) {
            int course = q.front();
            q.pop();
            ++ count;

            for (int nextCourse : out[course]) {
                in[nextCourse].erase(course);
                if (in[nextCourse].empty()) {
                    q.push(nextCourse);
                }
            }
        }
        return count == numCourses;
    }
};

class Solution5 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        set<int> courses;
        for (int i = 0; i < numCourses; ++ i) courses.insert(i);

        map<int, set<int>> in, out;
        for (auto pre : prerequisites) {
            in[pre[0]].insert(pre[1]);
            out[pre[1]].insert(pre[0]);
        }

        while (! courses.empty()) {
            bool found = false; // found next course to finish first.
            for (int course : courses) {
                if (in[course].size() == 0) {
                    found = true;

                    for (int nextCourse : out[course]) {
                        // remove course from prerequeist list of nextCourse.
                        in[nextCourse].erase(course); 
                    }
                    courses.erase(course);
                    // break; // works with or without this.
                }
            }
            if (!found) return false;
        }
        return true;
    }
};

// Works. Shorter and easier to understand.
class Solution4 {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        set<int> courses;
        for (int i = 0; i < numCourses; ++ i) courses.insert(i);
        
        // use set, so no need to remove duplicates from prerequisites.
        map<int, set<int>> in, out; 
        
        for (auto p : prerequisites) {
            in[p.first].insert(p.second);
            out[p.second].insert(p.first);
        }
        
        while (! courses.empty()) {
            bool found = false;  // Important to avoid infinite cycle.
            for (auto course : courses) { // find in courses, not in "in".
                // This does not work: if (!in.contains(course))
                if (in[course].size() == 0) { // in degree is 0. Course has no prerequisite.
                    found = true;

                    for (auto c : out[course]) {
                        in[c].erase(course);
                    }
                    courses.erase(course);
                    // Works with or without the below 2 lines.
                    // in.erase(course);
                    // out.erase(course);
                }
            }
            if (found == false) break;
        }
        
        return courses.empty();
    }
};

// Works. Tested. 
// Modified from Solution2. Use unordered_map, and check for existence in while loop.
class Solution3 {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // remove duplicates.
        vector<pair<int, int>> pre;
        for (auto p : prerequisites) {
            if (find(pre.begin(), pre.end(), p) == pre.end())
                pre.push_back(p);
        }
        
        set<int> courses;
        for (int i = 0; i < numCourses; ++ i) courses.insert(i);
        
        // get edges and indegrees.
        unordered_map<int, vector<int>> edges;
        unordered_map<int, int> in;
        
        for (auto p : pre) {
            in[p.first] ++;
            edges[p.second].push_back(p.first);
        }
        
        while (! courses.empty()) {
            bool found = false;
            for (auto c : courses) {
                if (in[c] == 0) {
                    found = true;
                    courses.erase(c);
                    
                    // need this, otherwise has run time error, when edges[c] not exist.
                    if (edges.find(c) != edges.end()) {
                        for (auto e : edges[c]) {
                            if (in[e] > 0) in[e] --;
                        }
                    }
                }
            }
            if (! found) break;
        }
        
        return courses.empty();
    }
    
};

// Works too. Tested. By: XC. 
// Modified from Solution, by using "auto" data type.
// Note, have to use set here, instead of unordered_set, or it'll have runtime
// error, when delete from the unordered_set in while loop.
// This may have to do with how iterator of unordered_set is implemented as a hashtable.
class Solution2 {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        
        set<int> courses; // NOTE: if use unordered_set here, will have runtime error.
        for (int i = 0; i < numCourses; ++ i) courses.insert(i);
        
        while (! courses.empty()) {
            bool found = false;
            for (auto c : courses) {
                if (in[c] == 0) {
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
        
        return courses.empty();
    }
    
};


// Works. Tested. By: XC. 
class Solution {
public:
    bool canFinish2(int numCourses, vector<pair<int, int> >& prerequisites) {
        // remove duplicates in prerequisites.
        vector<pair<int, int> > prereq;
        for (int i = 0; i < prerequisites.size(); ++ i) {
            pair<int, int> p = prerequisites[i];
            if (find(prereq.begin(), prereq.end(), p) == prereq.end()) {
                prereq.push_back(p);
            }
        }

        vector<int> in(numCourses, 0);
        vector<vector<int> > pre(numCourses, vector<int>(0));
        for (int i = 0; i < prereq.size(); ++ i) {
            pair<int, int> pair = prereq[i];
            in[pair.first] ++; // get in-degree.
            pre[pair.second].push_back(pair.first); // get courses dependent on pair.second.
        }

        set<int> courses;
        for (int i = 0; i < numCourses; ++ i) courses.insert(i);

        // in loop, each time remove courses whose in-degree is 0, and
        // decrease the in-degree of those courses dependent on this course.
        // Standard topological sort procedure.
        while (! courses.empty()) {
            bool found = false;
            for (set<int>::iterator it = courses.begin(); it != courses.end(); ++ it) {
                int c = *it;
                if (in[c] == 0) {
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

        return courses.empty();
    }
};


/**
207. Course Schedule
Difficulty: Medium

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have 
to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it 
possible for you to finish all courses?

For example:

2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have 
finished course 0. So it is possible.

2, [[1,0],[0,1]]

There are a total of 2 courses to take. To take course 1 you should have 
finished course 0, and to take course 0 you should also have finished 
course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not 
adjacency matrices. Read more about how a graph is represented.

click to show more hints.
Hints:

    This problem is equivalent to finding if a cycle exists in a directed 
    graph. If a cycle exists, no topological ordering exists and therefore 
    it will be impossible to take all courses.
    
    Topological Sort via DFS - A great video tutorial (21 minutes) on 
    Coursera explaining the basic concepts of Topological Sort.
    Topological sort could also be done via BFS.

 */
