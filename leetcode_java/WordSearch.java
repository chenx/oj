public class Solution {
    public boolean exist(char[][] board, String word) {
        if (board.length == 0 || board[0].length == 0) return false;
        if (word.length() == 0) return true;
        int rows = board.length, cols = board[0].length;
        
        boolean[][] used = initUsedMatrix(rows, cols); // it works here.
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                if (board[i][j] == word.charAt(0)) {
                    //boolean[][] used = initUsedMatrix(rows, cols); // no need here.
                    if (search(board, i, j, used, word, 0)) return true;
                }
            }
        }
        
        return false;
    }
    
    boolean[][] initUsedMatrix(int rows, int cols) {
        boolean[][] used = new boolean[rows][cols];
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                used[i][j] = false;
            }
        }
        
        return used;
    }
    
    // Be careful of boundary.
    boolean search(char[][] board, int i, int j, boolean[][] used, String word, int pos) {
        if (pos == word.length() - 1) return true;

        int rows = board.length, cols = board[0].length;
        used[i][j] = true;
        
        ++ pos;
        char c = word.charAt(pos);
        if (i > 0 && ! used[i-1][j] && c == board[i-1][j]) {
            if (search(board, i-1, j, used, word, pos)) return true;
        }
        if (i < rows - 1 && ! used[i+1][j] && c == board[i+1][j]) {
            if (search(board, i+1, j, used, word, pos)) return true;
        }
        if (j > 0 && ! used[i][j-1] && c == board[i][j-1]) {
            if (search(board, i, j-1, used, word, pos)) return true;
        }
        if (j < cols - 1 && ! used[i][j+1] && c == board[i][j+1]) {
            if (search(board, i, j+1, used, word, pos)) return true;
        }
        
        used[i][j] = false;
        return false;        
    }
}

/**
Word Search
Difficulty: Medium

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
 */
