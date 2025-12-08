// From: https://algo.monster/liteproblems/444
// n = nums.size(), m = number of edges in sequences.
// Time: O(n + m)
// - Building the graph: Iterating through all sequences and all adjacent pairs takes O(m) time, where m is the total number of edges (sum of lengths of all sequences minus the number of sequences)
// - Initializing the indegree array: O(n) time
// - Finding initial nodes with zero indegree: O(n) time
// - BFS/Topological sort: Each node is processed once (O(n)), and each edge is traversed once when updating indegrees (O(m))
//
// Space: O(n + m)
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n);

        for (const auto& sequence : sequences) {
            for (int i = 1; i < sequence.size(); ++i) {
                // Convert to 0-indexed (assuming sequences contain 1-indexed values)
                int from = sequence[i - 1] - 1;
                int to = sequence[i] - 1;

                graph[from].push_back(to); // Add edge from 'from' to 'to'
                ++inDegree[to]; // Increment in-degree of 'to' node
            }
        }

        // Initialize queue for topological sort with all nodes having in-degree 0
        queue<int> topoQueue;
        for (int node = 0; node < n; ++node) {
            if (inDegree[node] == 0) {
                topoQueue.push(node);
            }
        }

        while (topoQueue.size() == 1) { // Perform topological sort
            int currentNode = topoQueue.front();
            topoQueue.pop();

            for (int neighbor : graph[currentNode]) {
                // Decrement in-degree and add to queue if it becomes 0
                if (--inDegree[neighbor] == 0) {
                    topoQueue.push(neighbor);
                }
            }
        }

        // If queue is empty, all nodes were processed with unique ordering
        // If queue has more than 1 element, multiple valid orderings exist
        return topoQueue.empty();
    }
};


/**
444. Sequence Reconstruction
Medium

You are given an integer array nums of length n where nums is a permutation of the integers in the range [1, n]. 
You are also given a 2D integer array sequences where sequences[i] is a subsequence of nums.

Check if nums is the shortest possible and the only supersequence. The shortest supersequence is a sequence with 
the shortest length and has all sequences[i] as subsequences. There could be multiple valid supersequences for 
the given array sequences.

    For example, for sequences = [[1,2],[1,3]], there are two shortest supersequences, [1,2,3] and [1,3,2].
    While for sequences = [[1,2],[1,3],[1,2,3]], the only shortest supersequence possible is [1,2,3]. [1,2,3,4] 
is a possible supersequence but not the shortest.

Return true if nums is the only shortest supersequence for sequences, or false otherwise.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without 
changing the order of the remaining elements.

 

Example 1:

Input: nums = [1,2,3], sequences = [[1,2],[1,3]]
Output: false
Explanation: There are two possible supersequences: [1,2,3] and [1,3,2].
The sequence [1,2] is a subsequence of both: [1,2,3] and [1,3,2].
The sequence [1,3] is a subsequence of both: [1,2,3] and [1,3,2].
Since nums is not the only shortest supersequence, we return false.

Example 2:

Input: nums = [1,2,3], sequences = [[1,2]]
Output: false
Explanation: The shortest possible supersequence is [1,2].
The sequence [1,2] is a subsequence of it: [1,2].
Since nums is not the shortest supersequence, we return false.

Example 3:

Input: nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
Output: true
Explanation: The shortest possible supersequence is [1,2,3].
The sequence [1,2] is a subsequence of it: [1,2,3].
The sequence [1,3] is a subsequence of it: [1,2,3].
The sequence [2,3] is a subsequence of it: [1,2,3].
Since nums is the only shortest supersequence, we return true.
 */
