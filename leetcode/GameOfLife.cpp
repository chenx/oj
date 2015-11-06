/**
 * This works.
 * If consider board as infinite, and wrap around borders, then use these 3 functions instead:
    int getX(int v, int rows) {
        if (v == -1) v = rows - 1;
        else if (v == rows) v = 0;
        return v;
    }
    int getY(int v, int cols) {
        if (v == -1) v = cols - 1;
        else if (v == cols) v = 0;
        return v;
    }
    
    void addToCoords(vector<Coord>& coords, int x, int y, int i, int j) {
        if (x == i && y == j) return; // self grid, don't add.
        for (int k = 0; k < coords.size(); ++ k) {
            // if c already exists in coords, don't add.
            if (x == coords[k].x && y == coords[k].y) return;
        }
        coords.add(new Coord(x, y));
    }
 */
 
struct Coord {
public:
    int x;
    int y;
    Coord(int x, int y) : x(x), y(y) {
        /*this->x = x;
        this->y = y;*/
    }
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> b(rows, vector<int>(cols));
        
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                b[i][j] = getNewLife(board[i][j], countNeighbors(board, rows, cols, i, j));
            }
        }
        
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                board[i][j] = b[i][j];
            }
        }
    }
    
private:    
    int countNeighbors(vector<vector<int>>& board, int rows, int cols, int i, int j) {
        vector<Coord> coords;
        
        addToCoords(coords, getX(i - 1, rows), getY(j - 1, cols), i, j); // Upper Left
        addToCoords(coords, getX(i - 1, rows), j, i, j); // Upper Middle
        addToCoords(coords, getX(i - 1, rows), getY(j + 1, cols), i, j); // Upper Right
        addToCoords(coords, i, getY(j - 1, cols), i, j); // Middle Left
        addToCoords(coords, i, getY(j + 1, cols), i, j); // Middle Right
        addToCoords(coords, getX(i + 1, rows), getY(j - 1, cols), i, j); // Bottom Left
        addToCoords(coords, getX(i + 1, rows), j, i, j); // Bottom Middle
        addToCoords(coords, getX(i + 1, rows), getY(j + 1, cols), i, j); // Bottom Right
        
        int sum = 0;
        for (int k = 0, len = coords.size(); k < len; ++ k) {
            sum += board[coords[k].x][coords[k].y];
        }
        
        return sum;
    }
    
    int getNewLife(int curLife, int neighbors) {
        int newLife = 0;
        
        if (curLife == 1) {
            newLife = (neighbors == 2 || neighbors == 3) ? 1 : 0;
        }
        else {
            newLife = (neighbors == 3) ? 1 : 0;
        }
        
        return newLife;
    }
    
    int getX(int v, int rows) {
        if (v == -1 || v == rows) return -1;
        return v;
    }

    int getY(int v, int cols) {
        if (v == -1 || v == cols) return -1;
        return v;
    }
    
    void addToCoords(vector<Coord>& coords, int x, int y, int i, int j) {
        if (x == -1 || y == -1) return; // outside board, don't add.
        for (int k = 0; k < coords.size(); ++ k) {
            // if c already exists in coords, don't add.
            if (x == coords[k].x && y == coords[k].y) return;
        }
        coords.push_back(Coord(x, y));
    }
};


/**
Game of Life
Difficulty: Medium

According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using 
the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population..
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state.

Follow up:

    Could you solve it in-place? Remember that the board needs to be updated at 
    the same time: You cannot update some cells first and then use their updated 
    values to update other cells.
    
    In this question, we represent the board using a 2D array. In principle, 
    the board is infinite, which would cause problems when the active area 
    encroaches the border of the array. How would you address these problems?

 */
 
