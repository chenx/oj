/**
 See: https://leetcode.com/problems/shortest-bridge/editorial

 Time complexity: O(n2)
     The maximum number of water cells and the maximum number of land cells in island A 
     we need to check are n2, which will take O(n2) time.

 Space complexity: O(n2)
     The maximum number of land cells of island A that we need to check with BFS is n2, 
     thus the space used by bfs_queue is O(n2).
     The maximum number of water cells we need to check using BFS before reaching the 
     second island is n2, thus the space used by second_bfs_queue is also O(n2).
     To sum up, the overall space complexity is O(n2)
 */
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int firstX = -1, firstY = -1;

        // Find any land cell, and we treat it as a cell of island A.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    firstX = i, firstY = j;
                    break;
                }
            }
        }

        // bfsQue for BFS on land cells of island A; secondBfsQue for BFS on
        // water cells.
        queue<pair<int, int>> bfsQue, secondBfsQue;
        bfsQue.push({firstX, firstY});
        secondBfsQue.push({firstX, firstY});
        grid[firstX][firstY] = 2;

        // BFS for all land cells of island A and add them to secondBfsQue.
        while (!bfsQue.empty()) {
            int x = bfsQue.front().first, y = bfsQue.front().second;
            bfsQue.pop();
            for (auto next : vector<pair<int, int>>{
                     {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}) {
                int curX = next.first;
                int curY = next.second;
                if (curX >= 0 && curX < n && curY >= 0 && curY < n &&
                    grid[curX][curY] == 1) {
                    bfsQue.push({curX, curY});
                    secondBfsQue.push(make_pair(curX, curY));
                    grid[curX][curY] = 2;  // mark as visited.
                }
            }
        }

        int distance = 0;
        while (!secondBfsQue.empty()) {
            for (int i = 0, len = secondBfsQue.size(); i < len; ++ i) {
                int x = secondBfsQue.front().first;
                int y = secondBfsQue.front().second;
                secondBfsQue.pop();

                for (auto next : vector<pair<int, int>>{
                         {x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}}) {
                    int curX = next.first;
                    int curY = next.second;
                    if (curX >= 0 && curX < n && curY >= 0 && curY < n) {
                        if (grid[curX][curY] == 1) {
                            return distance;
                        } else if (grid[curX][curY] == 0) {
                            secondBfsQue.push(make_pair(curX, curY));
                            grid[curX][curY] = -1;  // mark as visited.
                        }
                    }
                }
            }

            // Once we finish one round without finding land cells of island B,
            // we will start the next round on all water cells that are 1 cell
            // further away from island A and increment the distance by 1.
            distance++;
        }
        return distance;
    }
};

/**
934. Shortest Bridge

You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. 
There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.
 */
