// BFS.
class Solution3 {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, set<int>> adjList;
        for (auto p : adjacentPairs) {
            adjList[p[0]].insert(p[1]);
            adjList[p[1]].insert(p[0]);
        }

        vector<int> nums;
        queue<int> q;
        set<int> used;
        for (auto [num, neighbors] : adjList) {
            if (neighbors.size() == 1) {
                q.push(num);
                used.insert(num);
                nums.push_back(num);
                break;
            }
        }

        while (! q.empty()) {
            int nextNum = q.front();
            q.pop();

            for (int neighbor : adjList[nextNum]) {
                if (! used.contains(neighbor)) {
                    q.push(neighbor);
                    used.insert(neighbor);
                    nums.push_back(neighbor);
                }
            }
        }

        return nums;
    }
};

// Time: O(n), Space: O(n)
class Solution2 {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, set<int>> adjList;
        for (auto e : adjacentPairs) {
            adjList[e[0]].insert(e[1]);
            adjList[e[1]].insert(e[0]);
        }

        vector<int> result;
        int nextVal;
        for (auto [val, neighbors] : adjList) {
            if (neighbors.size() == 1) { 
                nextVal = val;
                break; 
            }
        }

        while (true) {
            result.push_back(nextVal);

            if (adjList[nextVal].empty()) break;

            int neighbor = *adjList[nextVal].begin();
            adjList[neighbor].erase(nextVal);
            nextVal = neighbor;
        }
        return result;
    }
};


// DFS. From https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/editorial
// Time: O(n), Space: O(n)
class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for (auto& edge : adjacentPairs) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int root = 0;
        for (auto& pair : graph) {
            if (pair.second.size() == 1) {
                root = pair.first;
                break;
            }
        }
        
        vector<int> ans;
        dfs(root, INT_MAX, ans);
        return ans;
    }
    
    void dfs(int node, int prev, vector<int>& ans) {
        ans.push_back(node);
        for (int neighbor : graph[node]) {
            if (neighbor != prev) {
                dfs(neighbor, node, ans);
            }
        }
    }
};


/**
1743. Restore the Array From Adjacent Pairs
Medium

There is an integer array nums that consists of n unique elements, but you have forgotten it. 
However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] 
indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, 
either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.

 

Example 1:

Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.

Example 2:

Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.

Example 3:

Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]
 */
