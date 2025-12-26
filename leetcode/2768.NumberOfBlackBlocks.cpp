// From: https://algo.monster/liteproblems/2768
// Time: O(k), k = coordinates.size().
// Space: O(k)
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        map<long long, int> blockBlackCount; // <pos, black_count>

        // Position of upper/left cell of each 2x2 block containing a black cell.
        vector<vector<int>> directions = {{-1,-1}, {-1,0}, {0,-1}, {0,0}};
        for (auto coord : coordinates) {
             for (auto direction: directions) {
                int x = coord[0] + direction[0];
                int y = coord[1] + direction[1];
                if (x >= 0 && x < m-1 && y >= 0 && y < n-1) {
                    long long pos = 1ll * x * n + y;
                    ++ blockBlackCount[pos];
                }
             }
        }

        vector<long long> result(5, 0);
        for (auto [pos, count] : blockBlackCount) {
            result[count] ++;
        }
        result[0] = 1ll * (m-1) * (n-1) - (result[1] + result[2] + result[3] + result[4]);
        return result;
    }
};


// Time: O(mn)
// Space: O(k), k = coordinates.size().
class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> result(5, 0);
        set<vector<int>> blackCells(coordinates.begin(), coordinates.end());

        for (int x = 0; x < m-1; ++ x) {
            for (int y = 0; y < n-1; ++ y) {
                int sum = 0;
                if (blackCells.contains({x, y})) ++ sum;
                if (blackCells.contains({x+1, y})) ++ sum;
                if (blackCells.contains({x, y+1})) ++ sum;
                if (blackCells.contains({x+1, y+1})) ++ sum;
                cout << "cell: " << x << ", " << y << ". sum = " << sum << endl;
                result[sum] ++;
            }
        }
        return result;
    }
};


/**
2768. Number of Black Blocks
Medium

You are given two integers m and n representing the dimensions of a 0-indexed m x n grid.

You are also given a 0-indexed 2D integer matrix coordinates, where coordinates[i] = [x, y] indicates that the cell with coordinates [x, y] is colored black. All cells in the grid that do not appear in coordinates are white.

A block is defined as a 2 x 2 submatrix of the grid. More formally, a block with cell [x, y] as its top-left corner where 0 <= x < m - 1 and 0 <= y < n - 1 contains the coordinates [x, y], [x + 1, y], [x, y + 1], and [x + 1, y + 1].

Return a 0-indexed integer array arr of size 5 such that arr[i] is the number of blocks that contains exactly i black cells.

 

Example 1:

Input: m = 3, n = 3, coordinates = [[0,0]]
Output: [3,1,0,0,0]
Explanation: The grid looks like this:

There is only 1 block with one black cell, and it is the block starting with cell [0,0].
The other 3 blocks start with cells [0,1], [1,0] and [1,1]. They all have zero black cells. 
Thus, we return [3,1,0,0,0]. 
 */
