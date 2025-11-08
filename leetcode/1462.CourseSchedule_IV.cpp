// https://leetcode.com/problems/course-schedule-iv/editorial/
// Approach 4: Floyd Warshall Algorithm
// Time complexity: O(N3+Q)
// Space complexity: O(N2)

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPreReq(numCourses, vector<bool>(numCourses, false));

        for (auto prereq : prerequisites) {
            isPreReq[prereq[0]][prereq[1]] = true;
        }

        for (int k = 0; k < numCourses; ++ k) {
            for (int i = 0; i < numCourses; ++ i) {
                for (int j = 0; j < numCourses; ++ j) {
                    if (isPreReq[i][k] && isPreReq[k][j]) {
                        isPreReq[i][j] = true;
                    }
                }
            }
        }
        
        vector<bool> ans;
        for (auto query: queries) {
            ans.push_back(isPreReq[query[0]][query[1]]);
        }
        return ans;
    }
};


/**
1462. Course Schedule IV
Medium

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where 
prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

    For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.

Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course 
a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite 
of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.
 */
