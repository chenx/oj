//
// Implement the Starving Snake game.
// Use deque and set/unordered_set
// By: X. Chen
// Created on: 4/9/2016
// Last modified: 4/9/2016
//

#include <iostream>
#include <deque>
#include <set>
#include <vector>
using namespace std;


enum ERR {ERR_INTO_WALL, ERR_EAT_SELF};
enum DIR {UP, DOWN, LEFT, RIGHT};


class Snake {
    vector<vector<int> > board;
    int M, N;
    deque<pair<int, int> > snake;
    set<pair<int, int> > body;
public:
    Snake(vector<vector<int> > gameBoard, int x, int y) {
        board = gameBoard;
        if (board.size() == 0 || board[0].size() == 0) err("invalid board");
        M = board.size(), N = board[0].size();

        snake.clear();
        body.clear();

        pair<int, int> p(x, y);
        snake.push_front(p);
        body.insert(p);

        drawBoard();
    }

    bool intoWall(pair<int, int> & p) {
        int x = p.first, y = p.second;
        return x < 0 || x >= M || y < 0 || y >= N;
    }

    string getDirName(DIR dir) {
        if (dir == UP) return "UP";
        if (dir == DOWN) return "DOWN";
        if (dir == LEFT) return "LEFT";
        if (dir == RIGHT) return "RIGHT";
        return "UNKNOWN_DIR";
    }

    void move(DIR dir) {
        cout << "move: " + getDirName(dir) << endl;

        pair<int, int> cur = pair<int, int>(snake.front().first, snake.front().second);
        pair<int, int> nxt = next(cur, dir);

        if (intoWall(nxt)) {
            exit(ERR_INTO_WALL);
            return;
        }
        else if (body.find(nxt) != body.end()) {
            exit(ERR_EAT_SELF);
            return;
        }

        snake.push_front(nxt);
        body.insert(nxt);
        if (board[nxt.first][nxt.second] == 1) { // food
            board[nxt.first][nxt.second] = 0;
        }
        else {
            body.erase(snake.back());
            snake.pop_back();
        }

        drawBoard();
    }

    void exit(ERR errNum) {
        string msg;
        switch(errNum) {
            case ERR_INTO_WALL: msg = "bump into wall"; break;
            case ERR_EAT_SELF: msg = "eating self"; break;
            default: msg = "unspecified error"; break;
        }
        cout << endl << "!!! " << msg << ". game over !!!" << endl << endl;
            }

    pair<int, int> next(pair<int, int> &cur, DIR dir) {
        int x = cur.first, y = cur.second;
        if (dir == UP) x -= 1;
        else if (dir == DOWN) x += 1;
        else if (dir == LEFT) y -= 1;
        else if (dir == RIGHT) y += 1;
        else err("unknown dir");

        return pair<int, int>(x, y);
    }

    void err(string msg) {
        cout << msg << endl;
        throw exception();
    }

    void drawBoard() {
        for (int i = 0; i < M; ++ i) {
            for (int j = 0; j < N; ++ j) {
                pair<int, int> cur(i, j);
                if (body.find(cur) != body.end())
                    cout << "X";
                else if (board[i][j] == 1)
                    cout << "F";
                else
                    cout << ".";
            }
            cout << endl;
        }
        cout << endl;
    }
};


void test1() {
    vector<vector<int> > board(5, vector<int>(5, 0));
    board[1][1] = 1; // food.
    board[1][2] = 1;

    vector<DIR> path;
    path.push_back(RIGHT);
    path.push_back(DOWN);
    path.push_back(DOWN);
    path.push_back(RIGHT);
    path.push_back(UP);
    path.push_back(LEFT);
    path.push_back(LEFT);
    path.push_back(LEFT);

    Snake s(board, 0, 0);
    for (int i = 0; i < path.size(); ++ i) {
        s.move(path[i]);
    }
}

int main() {
    test1();
    return 0;
}

/**
 Output:
 
 X....
.FF..
.....
.....
.....

move: RIGHT
.X...
.FF..
.....
.....
.....

move: DOWN
.X...
.XF..
.....
.....
.....

move: DOWN
.....
.XF..
.X...
.....
.....

move: RIGHT
.....
..F..
.XX..
.....
.....

move: UP
.....
..X..
.XX..
.....
.....

move: LEFT
.....
.XX..
..X..
.....
.....

move: LEFT
.....
XXX..
.....
.....
.....

move: LEFT

!!! bump into wall. game over !!!

 */
