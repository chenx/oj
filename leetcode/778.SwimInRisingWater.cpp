// See: https://leetcode.com/problems/swim-in-rising-water/editorial/
// Use Heap.
// Time Complexity: O(N2logN). We may expand O(N2) nodes, and each one requires O(logN) time to perform the heap operations.
// Space Complexity: O(N2), the maximum size of the heap.
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        int m = grid.size(), n = grid[0].size();

        Comp comp(grid);
        priority_queue<vector<int>, vector<vector<int>>, Comp> minHeap(comp);

        int directions[5] = {1, 0, -1, 0, 1};
        set<vector<int>> visited;

        int minTime = 0;
        minHeap.push({0, 0});
        visited.insert({0, 0});

        while (! minHeap.empty()) {
            int i = minHeap.top()[0];
            int j = minHeap.top()[1];
            minHeap.pop();

            minTime = max(minTime, grid[i][j]);
            if (i == m - 1 && j == n - 1) return minTime;

            for (int k = 0; k < 4; ++ k) {
                int x = i + directions[k], y = j + directions[k+1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (! visited.contains({x, y})) {
                        visited.insert({x, y});
                        minHeap.push({x, y});
                    }
                }
            }
        }

        return 0;
    }

    struct Comp {
        vector<vector<int>> grid;

        Comp(vector<vector<int>>& grid) : grid(grid) {}

        bool operator()(vector<int>& a, vector<int>& b) {
            return grid[a[0]][a[1]] > grid[b[0]][b[1]];
        }
    };
};


/**
778. Swim in Rising Water
Hard

You are given an n x n integer matrix grid where each value grid[i][j] represents the 
elevation at that point (i, j).

It starts raining, and water gradually rises over time. At time t, the water level is t, 
meaning any cell with elevation less than equal to t is submerged or reachable.

You can swim from a square to another 4-directionally adjacent square if and only if the 
elevation of both squares individually are at most t. You can swim infinite distances in 
zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you 
start at the top left square (0, 0).
 */
