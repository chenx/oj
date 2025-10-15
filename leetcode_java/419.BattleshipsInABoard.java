// Same as question "Number of Islands".
class Solution {
    public int countBattleships(char[][] board) {
       int m = board.length, n = board[0].length, count = 0;;
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (board[i][j] == 'X') {
                    ++ count;
                    bfs(board, i, j);
                }
            }
        }
        return count;
    }
    
    void bfs(char[][] board, int i, int j) {
        int m = board.length, n = board[0].length;
        board[i][j] = '2';
        
        for (int k = 0; k < dirs.length - 1; ++ k) {
            int x = i + dirs[k], y = j + dirs[k+1];
            if (x >= 0 && x < board.length && y >= 0 && y < board[0].length) {
                if (board[x][y] == 'X') bfs(board, x, y);
            }
        }
    }
    
    private int[] dirs = {-1, 0, 1, 0, -1};
}

/**
419. Battleships in a Board

Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 
1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical 
cell separates between two battleships (i.e., there are no adjacent battleships).
 */
