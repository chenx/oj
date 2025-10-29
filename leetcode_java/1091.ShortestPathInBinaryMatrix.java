class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return -1;      
        int m = grid.length, n = grid[0].length;
        if (grid[0][0] == 1) return -1;
        if (m == 1 && n == 1) return 1;  // start is the end.

        Queue<int[]> queue = new LinkedList<int[]>(); // [x, y, dist]
        queue.add(new int[]{0, 0, 1});

        // HashSet<int[]> visited = new HashSet();a
        // visited.add(new int[]{0, 0}); // This does not work properly.
        HashSet<String> visited = new HashSet();
        visited.add("0,0");

        int[][] directions = {{-1,-1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

        while (! queue.isEmpty()) {
            int i = queue.peek()[0];
            int j = queue.peek()[1];
            int dist = queue.peek()[2];
            queue.remove();

            // if (i == m-1 && j == n-1) { // This works too.
            //     return dist;
            // }

            for (int k = 0; k < 8; ++ k) {
                int x = i + directions[k][0];
                int y = j + directions[k][1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    String key = "" + x + "," + y;
                    if (grid[x][y] == 0 && ! visited.contains(key)) {
                        if (x == m-1 && y == n-1) {
                            return 1 + dist;
                        }
                        queue.add(new int[]{x, y, 1 + dist});
                        visited.add(key);
                    }
                }
            }
        }
        return -1;
    }
}

/**
1091. Shortest Path in Binary Matrix
Medium

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.
 */
