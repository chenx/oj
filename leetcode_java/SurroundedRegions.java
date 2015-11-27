public class Solution {
    public void solve(char[][] board) {
        if (board.length == 0 || board[0].length == 0) return;
        
        int rows = board.length, cols = board[0].length;

        for (int j = 0; j < cols; ++ j) {
            if (board[0][j] == 'O') label(board, 0, j);
            if (board[rows - 1][j] == 'O') label(board, rows - 1, j);
        }
        for (int i = 1; i < rows - 1; ++ i) {
            if (board[i][0] == 'O') label(board, i, 0);
            if (board[i][cols - 1] == 'O') label(board, i, cols - 1);
        }
        
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'K') board[i][j] = 'O';
            }
        }
    }
    
    // This works.
    void label(char[][] board, int i, int j) {
        int X = board.length - 1;
        int Y = board[0].length - 1;

        Stack<Integer> cells = new Stack<Integer>();
        cells.push(j); cells.push(i);
        
        while (! cells.empty() ) {
            i = cells.peek(); cells.pop();
            j = cells.peek(); cells.pop();
            board[i][j] = 'K';
            
            if (i > 0 && board[i-1][j] == 'O') { cells.push(j); cells.push(i-1); }
            if (i < X && board[i+1][j] == 'O') { cells.push(j); cells.push(i+1); }
            if (j > 0 && board[i][j-1] == 'O') { cells.push(j-1); cells.push(i); }
            if (j < Y && board[i][j+1] == 'O') { cells.push(j+1); cells.push(i); }
        }
    }
    
    // This should work, but has TimeOutError.
    void label2(char[][] board, int i, int j) {
        Queue<Integer> q = new LinkedList<Integer>();
        int X = board.length - 1, Y = board[0].length - 1;
        
        q.add(i); q.add(j);
        
        while (! q.isEmpty()) {
            i = q.peek(); q.remove();
            j = q.peek(); q.remove();
            board[i][j] = 'K';
            
            if (i > 0 && board[i-1][j] == 'O') { q.add(i-1); q.add(j); }
            if (i < X && board[i+1][j] == 'O') { q.add(i+1); q.add(j); }
            if (j > 0 && board[i][j-1] == 'O') { q.add(i); q.add(j-1); }
            if (j < Y && board[i][j+1] == 'O') { q.add(i); q.add(j+1); }
        }
    }
    
    // This should work, but has StackOverflow exception.
    void label3(char[][] board, int i, int j) {
        board[i][j] = 'K';
        int X = board.length - 1, Y = board[0].length - 1;
        
        if (i > 0 && board[i-1][j] == 'O') label(board, i-1, j);
        if (i < X - 1 && board[i+1][j] == 'O') label(board, i+1, j);
        if (j > 0 && board[i][j-1] == 'O') label(board, i, j-1);
        if (j < Y - 1 && board[i][j+1] == 'O') label(board, i, j+1);
    }    
    
}

/**
Surrounded Regions
Difficulty: Medium

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
 */
