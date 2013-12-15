//
// Generate a maze. Can use 1) DFS, 2) Dijkstra, or 3) union find.
// DFS is used here.
//
// Note:
// 1) check neighbor visited 
// 2) reset visited node to unvisited (set back to 0)
// 3) use of shuffling to choose a random path.
//
// @Author: Xin Chen
// @Created on: 4/10/2013
// @Last modified: 4/10/2013
//
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Solution {
public:
    void maze(vector<vector<int> > & M, pair<int, int> start, pair<int, int> end) {
        int R = M.size(), C = M[0].size();        
        
        //dumpMaze(M);
        cout << "start: " << start.first << ", " << start.second << endl;
        cout << "end:   " << end.first << ", " << end.second << endl;

        bool found = false;
        while (! found) {
            found = DFS(M, R, C, 0, 0, end);
            //cout << "continue to find" << endl;
            //dumpMaze(M); break;
        }
    }
    
    bool DFS(vector<vector<int> > & M, int R, int C, int x, int y, pair<int, int> end) {
        //cout << "x = " << x << ", y = " << y << endl;
        if (x == end.first && y == end.second) {
            M[x][y] = 1;
            return true; // found end.
        }
        
        M[x][y] = 1;
        
        vector<pair<int, int> > dir; // directions to go.
        if (x > 0 && ! neighbor_visited(M, R, C, x-1, y, x, y)) { dir.push_back(pair<int, int>(x-1, y)); }
        if (x < R-1 && ! neighbor_visited(M, R, C, x+1, y, x, y)) { dir.push_back(pair<int, int>(x+1, y)); }
        if (y > 0 && ! neighbor_visited(M, R, C, x, y-1, x, y)) { dir.push_back(pair<int, int>(x, y-1)); }
        if (y < C-1 && ! neighbor_visited(M, R, C, x, y+1, x, y)) { dir.push_back(pair<int, int>(x, y+1)); }
        
        // now choose random direction to go.
        int k = dir.size();
        if (k == 0) {
            M[x][y] = 0; // if remove this, the maze may become largely empty.
            return false;
        }
        else {
            shuffle(dir);
            for (int i = 0; i < k; ++ i) {
                if (DFS(M, R, C, dir[i].first, dir[i].second, end)) {
                    return true;
                }
            }
            //M[x][y] = 0; // remove this, the maze can become very interesting.
                           // if not remove, the maze will have only one path and not interesting,
                           // also can take much longer to generate the maze.
                           // So should remove this.
            return false;
        }
    }
    
    //
    // return true if 1) (x, y) has been visited, or 2) any of (x, y)'s neighbor 
    // (except (x0, y0) where (x, y) was from) is visited (value is 1).
    // 2) is to avoid too many connected empty spaces in the maze.
    //
    bool neighbor_visited(vector<vector<int> > & M, int R, int C, int x, int y, int x0, int y0) {
        if (M[x][y] == 1) return true;
        
        if (!(x-1 == x0 && y == y0) && x > 0 && M[x-1][y] == 1) return true;
        if (!(x+1 == x0 && y == y0) && x < R-1 && M[x+1][y] == 1) return true;
        if (!(x == x0 && y-1 == y0) && y > 0 && M[x][y-1] == 1) return true;
        if (!(x == x0 && y+1 == y0) && y < C-1 && M[x][y+1] == 1) return true;
        
        return false;
    }
    
    void shuffle(vector<pair<int, int> > & v) {
        int k = v.size();
        for (int i = k; i > 1; -- i) {
            int x = rand() % i; // x in [0, i-1]
            swap(v[x], v[i-1]);
        }
    }
    
    void dumpMaze(vector<vector<int> > & M) {
        int R = M.size(), C = M[0].size();
        
        for (int j = 0; j < C; ++ j) cout << "-";
        cout << "--" << endl;
        
        for (int i = 0; i < R; ++ i) {
            cout << "|";
            for (int j = 0; j < C; ++ j) {
                if (M[i][j] == 1) { cout << " "; }
                else cout << M[i][j] << "";
            }
            cout << "|" << endl;
        }
        for (int j = 0; j < C; ++ j) cout << "-";
        cout << "--" << endl;

        cout << endl;
    }
    
    void shuffle(vector<int> & v) {
        int k = v.size();
        for (int i = k; i > 1; -- i) {
            int x = rand() % i; //cout << "x=" << x << endl;
            swap(v[x], v[i-1]);
        }
    }
    void dumpVec(vector<int> & v) {
        for (int i = 0; i < v.size(); ++ i) cout << v[i] << " ";
        cout << endl;
    }
};

void test_shuffle() {
    int A[] = {1,2,3,4,5};
    int n = sizeof(A) / sizeof(int);
    vector<int> v(n);
    
    for (int i = 0; i < n; ++ i) v[i] = A[i];
    
    Solution s;
    s.shuffle(v);
    s.dumpVec(v);
}


int main() {
    srand(time(NULL));
    const int ROWS = 20, COLS = 20;
    vector<vector<int> > M(ROWS);
    for (int i = 0; i < ROWS; ++ i) {
        M[i] = vector<int>(COLS);
        for (int j = 0; j < COLS; ++ j) {
            M[i][j] = 0;
        }
    }
    
    Solution s;
    
    pair<int, int> start(0, 0);
    pair<int, int> end(ROWS-1, COLS-1);

    s.dumpMaze(M);
    s.maze(M, start, end);
    s.dumpMaze(M);
    
    //test_shuffle();
    
    return 0;
}
