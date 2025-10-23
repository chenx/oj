class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }

    void dfs(int[][] image, int sr, int sc, int color, int val) {
        image[sr][sc] = color;

        for (int k = 0; k < 4; ++ k) {
            int x = sr + directions[k], y = sc + directions[k+1];
            if (x >= 0 && x < image.length && y >= 0 && y < image[0].length) {
                if (image[x][y] == val && val != color) {
                    dfs(image, x, y, color, val);
                }
            }
        }
    }

    int[] directions = {-1, 0, 1, 0, -1};
}
