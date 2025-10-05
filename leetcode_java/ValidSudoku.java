class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; ++ i) {
            if (!validateRow(board, i)) return false;
        }
        for (int i = 0; i < 9; ++ i) {
            if (!validateCol(board, i)) return false;
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!validateSquare(board, i, j)) return false;
            }
        }
        return true;
    }
    
    boolean validateRow(char[][] board, int row) {
        int[] count = new int[10];
        for (int j = 0; j < 9; ++ j) {
            if (board[row][j] == '.') continue;
            if (++ count[board[row][j] - '0'] > 1) return false;
        }
        return true;
    }
  
    boolean validateCol(char[][] board, int col) {
        int[] count = new int[10];
        for (int j = 0; j < 9; ++ j) {
            if (board[j][col] == '.') continue;
            if (++ count[board[j][col] - '0'] > 1) return false;
        }
        return true;
    }
    
    boolean validateSquare(char[][] board, int row, int col) {
        int[] count = new int[10];
        for (int i = 0; i < 3; ++ i) {
            for (int j = 0; j < 3; ++ j) {
                if (board[row+i][col+j] == '.') continue;
                if (++ count[board[row+i][col+j] - '0'] > 1) return false;
            }
        }
        return true;
    }
}

/**
Validate Sudoku.
 */
