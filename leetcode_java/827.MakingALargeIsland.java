// From: https://leetcode.com/problems/making-a-large-island/editorial/
class Solution {
    public int largestIsland(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return 0;
    
        Map<Integer, Integer> islandSizes = new HashMap(); // <islandId, size>
        int islandId = 2, m = grid.length, n = grid[0].length;

        // Step 1: Mark all islands and calculate their sizes
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) {
                    islandSizes.put(islandId, exploreIsland(grid, islandId, i, j));
                    ++islandId;
                }
            }
        }

        if (islandSizes.isEmpty()) return 1; // If there are no islands, return 1

        // If the entire grid is one island, return its size, otherwise return size + 1
        if (islandSizes.size() == 1) {
            int size = islandSizes.get(islandId - 1);
            return (size == m * n) ? size : size + 1;
        }

        int maxIslandSize = 1;

        // Step 2: Try converting every 0 to 1 and calculate the resulting island size.
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 0) {
                    int currentIslandSize = 1;
                    Set<Integer> neighboringIslands = new HashSet<>();

                    // Check down
                    if (i + 1 < n && grid[i + 1][j] > 1) {
                        neighboringIslands.add(grid[i + 1][j]);
                    }
                    // Check up
                    if (i - 1 >= 0 && grid[i - 1][j] > 1) {
                        neighboringIslands.add(grid[i - 1][j]);
                    }
                    // Check right
                    if (j + 1 < n && grid[i][j + 1] > 1) {
                        neighboringIslands.add(grid[i][j + 1]);
                    }
                    // Check left
                    if (j - 1 >= 0 && grid[i][j - 1] > 1) {
                        neighboringIslands.add(grid[i][j - 1]);
                    }

                    // Sum the sizes of all unique neighboring islands
                    for (int id : neighboringIslands) {
                        currentIslandSize += islandSizes.get(id);
                    }

                    maxIslandSize = Math.max(maxIslandSize, currentIslandSize);
                }
            }
        }

        return maxIslandSize;
    }

    private int exploreIsland(int[][] grid, int islandId, int row, int col) {
        if (row < 0 || row >= grid.length || col < 0 || col >= grid[0].length ||
            grid[row][col] != 1) return 0;

        grid[row][col] = islandId;
        return (
            1 +
            exploreIsland(grid, islandId, row + 1, col) +
            exploreIsland(grid, islandId, row - 1, col) +
            exploreIsland(grid, islandId, row, col + 1) +
            exploreIsland(grid, islandId, row, col - 1)
        );
    }
}


/**
827. Making A Large Island
Hard

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.
 */
