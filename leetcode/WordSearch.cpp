//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/27/2012
// @Last modified: 10/26/2014
//

// Works.
class Solution5 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return false;
        if (word == "") return true;
        m = board.size(), n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++ i) 
            for (int j = 0; j < n; ++ j) 
                if (match(board, i, j, word, 0, used)) return true;

        return false;
    }
    
    bool match(vector<vector<char>>& board, int i, int j, string & word, int pos, vector<vector<bool>> & used) {
        if (i < 0 || i >= m || j < 0 || j >= n || used[i][j] || board[i][j] != word[pos]) return false;
        if (pos == word.length() - 1) return true;

        used[i][j] = true;
        
        if (match(board, i-1, j, word, pos+1, used)) return true;
        if (match(board, i+1, j, word, pos+1, used)) return true;
        if (match(board, i, j-1, word, pos+1, used)) return true;
        if (match(board, i, j+1, word, pos+1, used)) return true;
        
        used[i][j] = false;
        return false; // don't forget this!
    }
};

// Works too.
class Solution4 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return word == "";
        m = board.size(), n = board[0].size();
        
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (word[0] == board[i][j]) {
                    if (match(board, used, word, 0, i, j)) return true;
                }
            }
        }
        
        return false;
    }
    
    bool match(vector<vector<char>>& board, vector<vector<bool>> &used, 
               string &word, int pos, int i, int j) {
        ++ pos; // NOTE: increment pos here !!! Otherwise needs word.length()-1 below.
        if (pos == word.length()) {
            return true;
        }
        
        used[i][j] = true;
        
        for (int k = 0; k < dir.size(); ++ k) {
            int x = i + dir[k].first, y = j + dir[k].second;
            if (x >= 0 && x < m && y >= 0 && y < n && 
                board[x][y] == word[pos] && ! used[x][y]) {
                if (match(board, used, word, pos, x, y))
                    return true;
            }
        }
        
        used[i][j] = false;
        return false;
    }
private:
    int m, n;
    vector<pair<int, int>> dir = {
        pair<int, int>(-1, 0),
        pair<int, int>(1, 0),
        pair<int, int>(0, -1),
        pair<int, int>(0, 1)
    };
};

// Works too. Improved from Solution2.
class Solution3 {
    vector<pair<int, int>> dirs = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};
    int M, N;
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) { return word.size() == 0; }
        if (word.size() == 0) return true;
        
        M = board.size(), N = board[0].size();
        vector<vector<int> > used(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++ i) {
            for (int j = 0; j < N; ++ j) {
                if (board[i][j] == word[0]) {
                    if (match(board, used, i, j, word.c_str())) return true;
                }
            }
        }
        return false;
    }
    
    bool match(vector<vector<char> > &b, vector<vector<int> > &used, int i, int j, const char * w) {
        ++ w;
        if (*w == '\0') return true;

        used[i][j] = 1;
        
        for (auto dir : dirs) {
            int x = i + dir.first, y = j + dir.second;
            if (x >= 0 && x < M && y >= 0 && y < N && 
                !used[x][y] && *w == b[x][y] && match(b, used, x, y, w))
                return true;
        }
        
        used[i][j] = 0; // MUST use this to clear search path!
        return false;
    }
};


// This works too, and is clearer. 10-26-2014
class Solution2 {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0 || board[0].size() == 0) { return word.size() == 0; }
        if (word.size() == 0) return true;
        
        int M = board.size(), N = board[0].size();
        vector<vector<int> > used(M, vector<int>(N, 0));
        for (int i = 0; i < M; ++ i) {
            for (int j = 0; j < N; ++ j) {
                if (board[i][j] == word[0]) {
                    if (match(board, used, i, j, word.c_str())) return true;
                }
            }
        }
        return false;
    }
    
    bool match(vector<vector<char> > &b, vector<vector<int> > &used, int i, int j, const char * w) {
        ++ w;
        if (*w == '\0') return true;

        used[i][j] = 1;
        
        if (i > 0 && ! used[i-1][j]) {
            if (*w == b[i-1][j] && match(b, used, i-1, j, w)) return true;
        }
        if (i < b.size()-1 && ! used[i+1][j]) {
            if (*w == b[i+1][j] && match(b, used, i+1, j, w)) return true;
        }
        if (j > 0 && ! used[i][j-1]) {
            if (*w == b[i][j-1] && match(b, used, i, j-1, w)) return true;
        }
        if (j < b[0].size()-1 && ! used[i][j+1]) {
            if (*w == b[i][j+1] && match(b, used, i, j+1, w)) return true;
        }
        
        used[i][j] = 0; // MUST use this to clear search path!
        return false;
    }
};

// This works.
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
    
    void set_used(vector<int> &used, int cols, int i, int j, int v) {
        used[i * cols + j] = v;
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
        
        set_used(used, cols, i, j, 1);
        
        // left
        if (j > 0) { // not on left edge
            if (word[pos] == board[i][j-1] &&
                ! get_used(used, cols, i, j-1) )
                if (search(word, pos + 1, used, board, i, j-1)) return true;
        }
        
        // right
        if (j < cols - 1) { // not on right edge
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
        
        set_used(used, cols, i, j, 0);
        return false;
    }
};

/*
Problem:

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

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
