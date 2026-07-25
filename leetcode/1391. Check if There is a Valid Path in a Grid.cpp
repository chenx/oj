class UnionFind {
public:
  void add(int x) {
    if (parent.contains(x)) return;

    parent[x] = x;
    rank[x] = 0;
  }

  // Standard recursive version.
  int find(int x) {  // Path compression.
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void get_union(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;

    int rx = rank[x], ry = rank[y];
    if (rx > ry) {
      parent[y] = x;
    } else if (ry > rx) {
      parent[x] = y;
    } else {
      parent[y] = x;
      rank[x] += 1;
    }
  }

private:
  unordered_map<int, int> parent;
  unordered_map<int, int> rank;
};

class Solution {
    const set<vector<int>> horizontal_match = {
        {1, 1}, {1, 3}, {1, 5}, {4, 1}, {6, 1}, {4, 3}, {4, 5}, {6, 3}, {6, 5},
    };
    const set<vector<int>> vertical_match = {
        {2, 2}, {3, 2}, {2, 5}, {4, 2}, {2, 6}, {3, 5}, {4, 6}, {3, 6}, {4, 5},
    };
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                uf.add(i * n + j);
            }
        }

        // Do Union find for each pair of adjacent cells.
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int cell = i * n + j;
                if (j < n-1 && horizontal_match.contains({ grid[i][j], grid[i][j+1] })) {
                    uf.get_union(cell, cell + 1);
                }
                if (i < m - 1 && vertical_match.contains({ grid[i][j], grid[i+1][j] })) {
                    uf.get_union(cell, cell + n);
                }
            }
        }

        return uf.find(0) == uf.find(m*n - 1);
    }
};


/**
1391. Check if There is a Valid Path in a Grid
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

    1 which means a street connecting the left cell and the right cell.
    2 which means a street connecting the upper cell and the lower cell.
    3 which means a street connecting the left cell and the lower cell.
    4 which means a street connecting the right cell and the lower cell.
    5 which means a street connecting the left cell and the upper cell.
    6 which means a street connecting the right cell and the upper cell.

You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path 
that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path 
should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.

 

Example 1:

Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).

Example 2:

Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell 
and you will get stuck at cell (0, 0)

Example 3:

Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
 */
