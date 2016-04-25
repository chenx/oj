class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++ i) {
            if (! isValidRow(board, i)) return false;
            if (! isValidCol(board, i)) return false;
        }
        
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3)
                if (! isValidBlock(board, i, j)) return false;
                
        return true;
    }
    
    bool isValidRow(const vector<vector<char>>& board, int i) {
        unordered_set<char> s;
        for (int j = 0; j < 9; ++ j) {
            if (board[i][j] == '.') continue;
            if (s.count(board[i][j])) return false;
            s.insert(board[i][j]);
        }
        return true;
    }
    bool isValidCol(const vector<vector<char>>& board, int i) {
        unordered_set<char> s;
        for (int j = 0; j < 9; ++ j) {
            if (board[j][i] == '.') continue;
            if (s.count(board[j][i])) return false;
            s.insert(board[j][i]);
        }
        return true;
    }
    bool isValidBlock(const vector<vector<char>>& board, int i, int j) {
        unordered_set<char> s;
        for (int x = i; x < i + 3; ++ x)
            for (int y = j; y < j + 3; ++ y) {
                if (board[x][y] == '.') continue;
                if (s.count(board[x][y])) return false;
                s.insert(board[x][y]);
            }
        return true;
    }
};
