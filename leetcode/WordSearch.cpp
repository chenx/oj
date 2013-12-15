//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/27/2012
// @Last modified: 12/27/2012
//

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // use DFS plus backtracking.
        int rows = board.size();
        int cols = board[0].size();
            
        int i, j;
        for (i = 0; i < rows; i ++) {
            for (j = 0; j < cols; j ++) {
                if (board[i][j] == word[0]) {
                    vector<int> used(rows * cols);
                    if (search(word, 1, used, board, i, j)) return true;
                }
            }
        }
        
        return false;
    }
    
    void set_used(vector<int> &used, int cols, int i, int j) {
        used[i * cols + j] = 1;
    }
    bool get_used(vector<int> &used, int cols, int i, int j) {
        return used[i * cols + j] == 1;
    }
        
    // pos: next position of word to search for.
    // (i, j): current position.
    bool search(string &word, int pos, vector<int> &used, 
              vector<vector<char> > &board, int i, int j) {
        if (pos == word.length()) return true;
        
        int rows = board.size();
        int cols = board[0].size();
        
        set_used(used, cols, i, j);
        
        // left
        if (j % cols != 0) { // not on left edge
            if (word[pos] == board[i][j-1] &&
                ! get_used(used, cols, i, j-1) )
                if (search(word, pos + 1, used, board, i, j-1)) return true;
        }
        
        // right
        if (j % cols != cols - 1) { // not on right edge
            if (word[pos] == board[i][j+1] &&
                ! get_used(used, cols, i, j+1) )
                if (search(word, pos + 1, used, board, i, j+1)) return true;
        }
        
        // up
        if (i > 0) { // not top row.
            if (word[pos] == board[i-1][j] &&
                ! get_used(used, cols, i-1, j) )
                if (search(word, pos + 1, used, board, i-1, j)) return true;
        }
        
        // down
        if (i < rows - 1) {
            if (word[pos] == board[i+1][j] &&
                ! get_used(used, cols, i+1, j) )
                if (search(word, pos + 1, used, board, i+1, j)) return true;            
        }
        
        return false;
    }
};

/*
Problem:

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

NOTE: this is similar to the boggle game problem!
 */