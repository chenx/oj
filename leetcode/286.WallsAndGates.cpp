// Time: O(mn)
// Space: O(mn)
class Solution5 {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0) return;
        int m = rooms.size(), n = rooms[0].size();

        queue<vector<int>> q; // <i, j, dist>

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (rooms[i][j] == 0) q.push({i, j, 0});
            }
        }

        static vector<int> directions = {-1, 0, 1, 0, -1};
        static int EMPTY = 2147483647;

        while (! q.empty()) {
            int i = q.front()[0], j = q.front()[1], dist = q.front()[2];
            q.pop();

            for (int k = 0; k < 4; ++ k) {
                int x = i + directions[k], y = j + directions[k + 1];

                if (x >= 0 && x < m && y >= 0 && y < n) {
                    if (rooms[x][y] == EMPTY) { // or rooms[x][y] > 1 + dist) { // works with or w/o the 2nd condition.
                        rooms[x][y] = 1 + dist;
                        q.push({x, y, 1 + dist});
                    }
                }
            }
        }
    }
};


// Should work. Tested locally.
class Solution4 {
public:
    void wallsAndGates(vector<vector<int> >& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0) return;
        int m = rooms.size(), n = rooms[0].size();
        vector<vector<int> > dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int> > q;

        for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
                if (rooms[i][j] == 0) q.push(pair<int, int>(i, j));

        while (! q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (int i = 0; i < dirs.size(); ++ i) {
                int dx = x + dirs[i][0], dy = y + dirs[i][1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n
                    && (rooms[dx][dy] == INF || rooms[dx][dy] > 1 + rooms[x][y])) {
                    rooms[dx][dy] = 1 + rooms[x][y];
                    q.push(pair<int, int>(dx, dy));
                }
            }
        }
    }
};


// Should work. Not tested.
class Solution3 {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0) return;
        int m = rooms.size(), n = rooms[0].size(), INF = 2147483647;
        
        queue<vector<int>> q;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (rooms[i][j] == 0) q.push({i, j, 0});
            }
        }
        
        vector<pair<int, int>> dir =
            {pair<int, int>(-1, 0), pair<int, int>(1, 0), 
             pair<int, int>(0, -1), pair<int, int>(0, 1)};
        
        // update distances.
        while (! q.empty()) {
            int x = q.front()[0], y = q.front()[1], dist = q.front()[2];
            q.pop();
            
            for (int i = 0; i < dir.size(); ++ i) {
                int dx = x + dir[i].first, dy = y + dir[i].second, d = dist + 1;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && rooms[dx][dy] != -1) {
                    rooms[dx][dy] = min(rooms[dx][dy], d);
                    q.push({dx, dy, d});
                }
            }
        }
    }
    
};

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
                    q.push(make_v3(i, j, 0)); // this works too: q.push({i, j, 0});
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
