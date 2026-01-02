/** Output of commented out section:
5,0 5,1 5,2 5,3 5,4 5,5 
4,5 4,4 4,3 4,2 4,1 4,0 
3,0 3,1 3,2 3,3 3,4 3,5 
2,5 2,4 2,3 2,2 2,1 2,0 
1,0 1,1 1,2 1,3 1,4 1,5 
0,5 0,4 0,3 0,2 0,1 0,0 
*/
class Solution2 {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return 0;
        int n = board.size(), size = n*n;

        vector<vector<int>> cells(n*n + 1);
        int ct = 1;
        bool left2right = true;
        for (int i = n-1; i >= 0; -- i) {
            if (left2right) {
                for (int j = 0; j < n; ++ j) cells[ct ++] = {i, j};
            } else {
                for (int j = n-1; j >= 0; -- j) cells[ct ++] = {i, j};
            }
            left2right = ! left2right;
        }
        // for (int i = 0; i < n; ++ i) {
        //     for (int j = 0; j < n; ++ j) {
        //         cout << to_string(cells[i*n + j + 1][0]) + "," + to_string(cells[i*n + j + 1][1]) + " ";
        //     }
        //     cout << endl;
        // }

        vector<int> dist(n*n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (! q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = curr + 1; i <= min(curr + 6, n * n); ++ i) {
                int x = cells[i][0], y = cells[i][1];
                int destination = board[x][y] == -1 ? i : board[x][y];
                if (dist[destination] == -1) {
                    dist[destination] = 1 + dist[curr];
                    q.push(destination);
                }
            }
        }

        return dist[n*n];

    }
};


class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0); // 0, 1, 2, .., n-1
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n * n];
    }
};

/**
909. Snakes and Ladders

You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting 
from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

    Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
        This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, 
        regardless of the size of the board.
    If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
    The game ends when you reach the square n2.

A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder 
is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.

Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start 
of another snake or ladder, you do not follow the subsequent snake or ladder.

    For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the 
    ladder to square 3, but do not follow the subsequent ladder to 4.

Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.
 */
