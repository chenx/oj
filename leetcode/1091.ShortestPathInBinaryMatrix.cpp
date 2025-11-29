// BFS.
// Time: O(m*n)
// Space: O(m*n)
class Solution {
    vector<vector<int>> directions = 
        {{-1,-1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return -1;      
        int m = grid.size(), n = grid[0].size();
        
        if (grid[0][0] == 1) return -1;
        if (m == 1 && n == 1) return 1;

        queue<vector<int>> q;
        q.push({0, 0, 1}); // <x, y, dist>

        set<vector<int>> visited;
        visited.insert({0, 0});

        while (! q.empty()) {
            int i = q.front()[0], j = q.front()[1], dist = q.front()[2];
            q.pop();

            for (int k = 0; k < 8; ++ k) {
                int x = i + directions[k][0], y = j + directions[k][1];

                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 0 && ! visited.contains({x, y})) {
                        if (x == m-1 && y == n-1) return dist + 1;

                        visited.insert({x, y});
                        q.push({x, y, dist + 1});
                    }
                }
            }
        }
        return -1;
    }
};


/**
1091. Shortest Path in Binary Matrix
Medium

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. 
If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right 
cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different 
        and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 */
