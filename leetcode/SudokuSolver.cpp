//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/3/2013
// @Last modified: 1/3/2013
//

// This works too.
class Solution2 {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>>& board, int row, int col) {
        if (! getNextCell(board, row, col)) return true;

        vector<char> v = getOptions(board, row, col);
        for (int i = 0; i < v.size(); ++ i) {
            board[row][col] = v[i];
            if (solve(board, row, col + 1)) return true;
        }
        
        board[row][col] = '.';
        return false;
    }
    
    vector<char> getOptions(vector<vector<char>>& board, int row, int col) {
        vector<bool> v(9, true);
        for (int i = 0; i < 9; ++ i) {
            if (i == row) continue;
            char c = board[i][col];
            if (isDigit(c)) v[c - '1'] = false;
        }

        for (int j = 0; j < 9; ++ j) {
            if (j == col) continue;
            char c = board[row][j];
            if (isDigit(c)) v[c - '1'] = false;
        }
        
        for (int i = 0; i < 3; ++ i) {
            for (int j = 0; j < 3; ++ j) {
                if ((i == row && j == col)) continue;
                char c = board[(row/3) * 3 + i][(col/3)*3 + j];
                if (isDigit(c)) v[c - '1'] = false;
            }
        }
        
        vector<char> ans;
        for (int i = 0; i < 9; ++ i) {
            if (v[i]) ans.push_back('1' + i);
        }
        return ans;
    }
    
    bool isDigit(char c) { return c >= '1' && c <= '9'; }
    
    bool getNextCell(vector<vector<char>>& board, int &row, int &col) {
        for (int j = col; j < 9; ++ j) {
            if (board[row][j] == '.') {
                col = j;
                return true;
            }
        }
        for (int i = row+1; i < 9; ++ i) {
            for (int j = 0; j < 9; ++ j) {
                if (board[i][j] == '.') {
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        
        return false;
    }
};

// For each ".", find out all possible values, and do DFS search.
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        doSolve(board, 0, 0);
    }
    
    bool doSolve(vector<vector<char> > &board, int row, int col) {
        int next_row, next_col;
                
        if ( 0 == getNextEmptyCell(board, row, col, next_row, next_col) ) return true;
        
        vector<char> vals = getPossibleValues(board, next_row, next_col);
        for (int i = 0; i < vals.size(); i ++) {
            board[next_row][next_col] = vals[i];
            if ( doSolve(board, next_row, next_col + 1) ) return true;
        }
        
        board[next_row][next_col] = '.'; // This is NECESSARY!
        return false;
    }
    
    // get possible values at board[row][col].
    vector<char> getPossibleValues(vector<vector<char> > &board, int row, int col) {
        vector<char> v;
        char a[] = {'1','2','3','4','5','6','7','8','9'};
        
        char c;
        // check row and col.
        for (int i = 0; i < 9; i ++) {
            c = board[row][i];
            if (c != '.') a[ c - '1' ] = '-';
            c = board[i][col];
            if (c != '.') a[ c - '1' ] = '-';
        }
        
        // check square
        int row_base = (row / 3) * 3;
        int col_base = (col / 3) * 3;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                c = board[row_base + i][col_base + j];
                if (c != '.') a[ c - '1' ] = '-';
            }
        }
        
        for (int i = 0; i < 9; i ++) {
            if (a[i] != '-') v.push_back(a[i]);
        }
        
        return v;
    }
    
    // Note: need to handle the two cases separately: cur_row == row, cur_row > row.
    bool getNextEmptyCell(vector<vector<char> > &board, int row, int col, int &next_row, int &next_col) {
        for (int j = col; j < 9; j ++) { 
            if (board[row][j] == '.') {
                next_row = row;
                next_col = j;
                return true; // found.
            }
        }
        for (int i = row + 1; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') {
                    next_row = i;
                    next_col = j;
                    return true; // found.
                }
            }
        }
        return false; // none is found.
    }
};

/*
Problem:
        
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution. 
 */

/*
// http://algos.tnsatish.com/2008/07/sudoku-solver.html
// http://stackoverflow.com/questions/5484629/check-if-sudoku-solution-is-valid
// http://www.geeksforgeeks.org/backtracking-set-7-suduku/
   Like all other Backtracking problems, we can solve Sudoku by one by one 
   assigning numbers to empty cells. Before assigning a number, we check 
   whether it is safe to assign. We basically check that the same number 
   is not present in current row, current column and current 3X3 subgrid. 
   After checking for safety, we assign the number, and recursively check 
   whether this assignment leads to a solution or not. If the assignment 
   does¡t lead to a solution, then we try next number for current empty cell. 
   And if none of number (1 to 9) lead to solution, we return false.
 */

