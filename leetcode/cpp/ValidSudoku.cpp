//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/3/2013
// @Last modified: 10/26/2014
//

#include <iostream>
#include <vector>
using namespace std;

// This works too, and is clear. 10-26-2014.
class Solution3 {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (! validS(board, i, j)) return false;
            }
        }
        for (int i = 0; i < 9; ++ i) {
            if (! validRow(board, i)) return false;
        }
        for (int j = 0; j < 9; ++ j) {
            if (! validCol(board, j)) return false;
        }
        return true;
    }
    
    bool validS(vector<vector<char> > &board, int i, int j) {
        vector<int> v(9);
        for (int a = 0; a < 3; ++ a) {
            for (int b = 0; b < 3; ++ b) {
                char c = board[i+a][j+b];
                if (c >= '1' && c <= '9') {
                    int x = c - '1';
                    if (v[x] == 1) return false;
                    v[x] = 1;
                }
            }
        }
        return true;
    }
    
    bool validRow(vector<vector<char> > &board, int i) {
        vector<int> v(9);
        for (int a = 0; a < 9; ++ a) {
            char c = board[i][a];
            if (c >= '1' && c <= '9') {
                int x = c - '1';
                if (v[x] == 1) return false;
                v[x] = 1;
            }
        }
        return true;
    }
    
    bool validCol(vector<vector<char> > &board, int j) {
        vector<int> v(9);
        for (int a = 0; a < 9; ++ a) {
            char c = board[a][j];
            if (c >= '1' && c <= '9') {
                int x = c - '1';
                if (v[x] == 1) return false;
                v[x] = 1;
            }
        }
        return true;
    }    
};

// for each row, col, square, validate no duplicates.
// Note leetcode assume this to be enough, i.e., don't go ahead to check
// if the partially filled sudoku has a solution.
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int a, val; // use lower 9 bits as indicator of the existence of digits 1 - 9.
        
        // rows.
        for (int i = 0; i < 9; i ++) {
            a = 0;
            for (int j = 0; j < 9; j ++) {
                if ( ! validateCell(board, i, j, a) ) return false;
            }
        }

        // cols
        for (int j = 0; j < 9; j ++) {
            a = 0;
            for (int i = 0; i < 9; i ++) {
                if ( ! validateCell(board, i, j, a) ) return false;
            }
        }

        // squares
        for (int row_base = 0; row_base <= 6; row_base += 3) {
            for (int col_base = 0; col_base <= 6; col_base += 3) {
                a = 0;
                for (int i = 0; i < 3; i ++) {
                    for (int j = 0; j < 3; j ++) {
                        if ( ! validateCell(board, row_base + i, 
                                            col_base + j, a) ) return false;
                    }
                }
                
            }
        }
        
        return true;
    }
    
    bool validateCell(vector<vector<char> > &board, int i, int j, int &a) {
        if (board[i][j] != '.') {
            int val = board[i][j] - '1';
            if ( (a >> val) & 1 ) return false; 
            //if ( (1 << val) & a ) return false; // can use this too!
            else a |= (1 << val);
        }
        return true;
    }
};


void showBoard(vector<vector<char> > board) {
     for (int i = 0; i < 9; i ++) {
         for (int j = 0; j < 9; ++ j) {
             printf("%c ", board[i][j]);
         }
         puts("");
     }
     puts("");
}

// For each row, col, square, validate no duplicates.
// If no duplicates is true and there exists ".", 
// do doSolve() to see if this is a valid partially 
// filled sudoku (and show one solution if so).
class Solution2 {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool has_dot = false;
        if (! validate(board, has_dot)) return false;
        if (! has_dot) return true;
        return doSolve(board, 0, 0);
    }
    
    bool validateCell(vector<vector<char> > &board, bool &has_dot, int i, int j, int &a) {
        if (board[i][j] == '.') {
            has_dot = true;
        } else {
            int val = board[i][j] - '1';
            //printf("board[%d][%d] = %c, val = %d\n", i, j, board[i][j], val);
            if ( (a >> val) & 1 ) {
                 //printf("(%d, %d): %c. a = %x\n", i, j, board[i][j], a);
                 return false;
            }
            else a |= (1 << val);
        }
        return true;
    }
    
    bool validate(vector<vector<char> > &board, bool &has_dot) {
        int a, val; // use lower 9 bits as indicator of the existence of digits 1 - 9.

        // rows.
        for (int i = 0; i < 9; i ++) {
            a = 0;
            for (int j = 0; j < 9; j ++) {
                if ( ! validateCell(board, has_dot, i, j, a) ) {
                     //printf("false at (%d, %d)\n", i, j);
                     return false;
                }
            }
        }

        // cols
        for (int j = 0; j < 9; j ++) {
            a = 0;
            for (int i = 0; i < 9; i ++) {
                if ( ! validateCell(board, has_dot, i, j, a) ) return false;
            }
        }

        // squares
        for (int row_base = 0; row_base <= 6; row_base += 3) {
            for (int col_base = 0; col_base <= 6; col_base += 3) {
                a = 0;
                for (int i = 0; i < 3; i ++) {
                    for (int j = 0; j < 3; j ++) {
                        if ( ! validateCell(board, has_dot, row_base + i, 
                                            col_base + j, a) ) return false;
                    }
                }
                
            }
        }

        return true;
    } // end of validate().
    
    
    bool doSolve(vector<vector<char> > &board, int row, int col) {
        int next_row, next_col;
                
        if ( 0 == getNextEmptyCell(board, row, col, next_row, next_col) ) {
            showBoard(board);
            return true;
        }
        
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


int main() {
    Solution s;
    vector<vector<char> > board;
    
    string b[9] = {"....1..5.",".1.......","...7.6.2.","..259....",".7..8....","...1.....","..1......","......2..",".6..4...."};
    for (int i = 0; i < 9; i ++) {
        vector<char> v;
        for (int j = 0; j < 9; j ++) {
            //printf("(%d,%d): insert %c\n", i, j, b[i][j]);
            v.push_back(b[i][j]);
        }
        board.push_back(v);
    }    
    showBoard(board);
    if (s.isValidSudoku(board)) { puts("true"); }
    else puts("false");
    return 0;
}

/*
"....1..5.",
".1.......",
"...7.6.2.",
"..259....",
".7..8....",
"...1.....",
"..1......",
"......2..",
".6..4...."

Problem:
        
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 */
 
 
