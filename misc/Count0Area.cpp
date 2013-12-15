//
// Given 2D 0/1 matrix, Count closed areas filled with 0.
//
// @Author: Xin Chen
// @Created on: 4/9/2013
// @Last modified: 4/9/2013
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//
// For each cell, 
//   if not 0, ignore; 
//   else, do BFS/DFS, label visited cells to -1. at the end, return 1.
//   Note: if areas touching edges are not counted, then return 0.
//
class Solution {
public:
    int count0area(vector<vector<int> > &M) {
        int R = M.size();
        if (R == 0) return 0;
        int C = M[0].size();
        if (C == 0) return 0;
       
        vector<vector<int> > M1 = M;
        int ct = 0;
        for (int i = 0; i < R; ++ i) {
            for (int j = 0; j < C; ++ j) {
                if (M1[i][j] == 0) {
                    //cout << "x=" << i << ", y=" << j << endl;
                    ct += DFS(M1, R, C, i, j);
                }
            }
        }
        cout << "DFS: " << ct << endl; 
        
        vector<vector<int> > M2 = M;
        int ct2 = 0;
        for (int i = 0; i < R; ++ i) {
            for (int j = 0; j < C; ++ j) {
                if (M2[i][j] == 0) {
                    ct2 += BFS(M2, R, C, i, j);
                }
            }
        }
        cout << "BFS: " << ct2 << endl;
                
        return ct2;
    }
    
    int DFS(vector<vector<int> > &M, int R, int C, int x, int y) {
        //if (M[x][y] != 0) return 0;
        
        M[x][y] = -1; // label as visited.
        if (x > 0 && M[x-1][y] == 0)   { DFS(M, R, C, x-1, y); }
        if (x < R-1 && M[x+1][y] == 0) { DFS(M, R, C, x+1, y); }
        if (y > 0 && M[x][y-1] == 0)   { DFS(M, R, C, x, y-1); }
        if (y < C-1 && M[x][y+1] == 0) { DFS(M, R, C, x, y+1); }
        
        return 1;
    }
    
    int BFS(vector<vector<int> > &M, int R, int C, int x, int y) {
        //if (M[x][y] != 0) return 0;
        
        queue<pair<int, int> > q;
        q.push(pair<int, int>(x, y));

        while (! q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            M[x][y] = -1;
            
            if (x > 0 && M[x-1][y] == 0) { q.push(pair<int, int>(x-1, y)); }
            if (x < R-1 && M[x+1][y] == 0) { q.push(pair<int, int>(x+1, y)); }
            if (y > 0 && M[x][y-1] == 0) { q.push(pair<int, int>(x, y-1)); }
            if (y < C-1 && M[x][y+1] == 0) { q.push(pair<int, int>(x, y+1)); }
        }
        
        return 1;
    }
};

//
// don't count areas touching edge.
//
class Solution2 {
public:
    int count0area(vector<vector<int> > &M) {
        int R = M.size();
        if (R == 0) return 0;
        int C = M[0].size();
        if (C == 0) return 0;
       
        vector<vector<int> > M1 = M;
        int ct = 0;
        for (int i = 0; i < R; ++ i) {
            for (int j = 0; j < C; ++ j) {
                if (M1[i][j] == 0) {
                    //cout << "x=" << i << ", y=" << j << endl;
                    ct += DFS(M1, R, C, i, j);
                }
            }
        }
        cout << "DFS: " << ct << endl; 
        
        vector<vector<int> > M2 = M;
        int ct2 = 0;
        for (int i = 0; i < R; ++ i) {
            for (int j = 0; j < C; ++ j) {
                if (M2[i][j] == 0) {
                    ct2 += BFS(M2, R, C, i, j);
                }
            }
        }
        cout << "BFS: " << ct2 << endl;
                
        return ct2;
    }
    
    int DFS(vector<vector<int> > &M, int R, int C, int x, int y) {
        //if (M[x][y] != 0) return 0;
        int v1 = 1, v2 = 1, v3 = 1, v4 = 1;
        
        M[x][y] = -1; // label as visited.
        if (x > 0 && M[x-1][y] == 0)   { v1 = DFS(M, R, C, x-1, y); }
        if (x < R-1 && M[x+1][y] == 0) { v2 = DFS(M, R, C, x+1, y); }
        if (y > 0 && M[x][y-1] == 0)   { v3 = DFS(M, R, C, x, y-1); }
        if (y < C-1 && M[x][y+1] == 0) { v4 = DFS(M, R, C, x, y+1); }
        
        if (x == 0 || x == R-1 || y == 0 || y == C-1) return 0;
        else return v1 && v2 && v3 && v4;
    }
    
    int BFS(vector<vector<int> > &M, int R, int C, int x, int y) {
        //if (M[x][y] != 0) return 0;
        
        bool touchEdge = false;
        queue<pair<int, int> > q;
        q.push(pair<int, int>(x, y));

        while (! q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            M[x][y] = -1;
            
            if (x == 0 || x == R-1 || y == 0 || y == C-1) touchEdge = true;
            
            if (x > 0 && M[x-1][y] == 0) { q.push(pair<int, int>(x-1, y)); }
            if (x < R-1 && M[x+1][y] == 0) { q.push(pair<int, int>(x+1, y)); }
            if (y > 0 && M[x][y-1] == 0) { q.push(pair<int, int>(x, y-1)); }
            if (y < C-1 && M[x][y+1] == 0) { q.push(pair<int, int>(x, y+1)); }
        }
        
        return touchEdge ? 0 : 1;
    }
};

int main() {
    const int COLS = 4;
    int A[][COLS] = {
        {0,1,1,0},
        {0,1,0,1},
        {1,0,0,1},
        {0,1,1,0}
    };
    
    int ROWS = sizeof(A) / sizeof(A[0]);
    vector<vector<int> > M(ROWS);
    for (int i = 0; i < ROWS; ++ i) {
        M[i] = vector<int>(COLS);
        for (int j = 0; j < COLS; ++ j) {
            M[i][j] = A[i][j];
        }
    }
    
    Solution s;
    s.count0area(M);
    
    Solution2 s2;
    s2.count0area(M);
    
    return 0;
}
