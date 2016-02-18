// Works too. Tested. By: XC
// Can push all gates, before update distance.
class Solution2 {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0) return;
        int m = rooms.size(), n = rooms[0].size(), INF = 2147483647;;
        vector<pair<int, int>> d = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
        
        queue<vector<int>> q;
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (rooms[i][j] == 0) {
                    q.push(make_v3(i, j, 0));
                }
            }
        }
        
        while (! q.empty()) {
            vector<int> & t = q.front();
            int x = t[0], y = t[1], dist = t[2] + 1;
            q.pop();
            
            for (int i = 0; i < d.size(); ++ i) {
                int dx = x + d[i].first, dy = y + d[i].second;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && 
                    (rooms[dx][dy] == INF || (rooms[dx][dy] > dist))) {
                    rooms[dx][dy] = dist;
                    q.push(make_v3(dx, dy, dist));
                }
            }
        }
    }
    
    // update when: new cell is INF, or current dist is greater than new dist. 
    
private:
    vector<int> make_v3(int a, int b, int c) {
        vector<int> v(3);
        v[0] = a; v[1] = b; v[2] = c;
        return v;
    }
};

// Works. Tested. By: XC
class Solution {
public:
    Solution() {
        d = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0) return;
        m = rooms.size(), n = rooms[0].size();
        
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (rooms[i][j] == 0) {
                    updateDist(rooms, i, j);
                }
            }
        }
    }
    
    // update when: new cell is INF, or current dist is greater than new dist. 
    void updateDist(vector<vector<int>>& rooms, int a, int b) {
        queue<vector<int>> q;
        q.push(make_v3(a, b, 0));
        
        while (! q.empty()) {
            vector<int> & t = q.front();
            int x = t[0], y = t[1], dist = t[2] + 1;
            q.pop();
            
            for (int i = 0; i < d.size(); ++ i) {
                int dx = x + d[i].first, dy = y + d[i].second;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && 
                    (rooms[dx][dy] == INF || (rooms[dx][dy] > dist))) {
                    rooms[dx][dy] = dist;
                    q.push(make_v3(dx, dy, dist));
                }
            }
        }
    }
    
private:
    vector<int> make_v3(int a, int b, int c) {
        vector<int> v(3);
        v[0] = a; v[1] = b; v[2] = c;
        return v;
    }
    
    vector<pair<int, int>> d;
    int m, n;
    const int INF = 2147483647;
};


/**
Walls and Gates 
Difficulty: Medium

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 
to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is 
impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
  
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
 */
