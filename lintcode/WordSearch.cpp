class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return false;
        m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (board[i][j] == word[0])
                    if (find(board, i, j, word, 0)) return true;
                    
        return false;
    }
    
    bool find(vector<vector<char> > &board, int i, int j, string word, int pos) {
        if (++ pos == word.length()) return true;
        
        char c = board[i][j];
        board[i][j] = '.';
        
        for (int k = 0; k < dirs.size(); ++ k) {
            int x = i + dirs[k][0], y = j + dirs[k][1];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == word[pos]) {
                if (find(board, x, y, word, pos)) return true;
            }
        }
        
        board[i][j] = c;
        return false;
    }
};

/**
Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example

Given board =

[
  "ABCE",
  "SFCS",
  "ADEE"
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
 */
