// Works. Slightly modified from Solution6.
class Solution7 {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> total(m, vector<int> (n, 0));
        int emptyLand = 0, minDist, delta[] = {0, 1, 0, -1, 0};

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] != 1) continue; 
                // otherwise, grid[i][j] == 1, is a building

                queue<vector<int>> q;
                q.push({i, j});

                int steps = 0;
                minDist = INT_MAX;

                while (! q.empty()) {
                    ++ steps;
                    
                    for (int level = q.size(); level > 0; -- level) {
                        auto pos = q.front();
                        q.pop();

                        for (int d = 0; d < 4; ++ d) {
                            int x = pos[0] + delta[d];
                            int y = pos[1] + delta[d+1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == emptyLand) {
                                -- grid[x][y]; // decrease it to be emptyLand of next cycle.

                                q.push({x, y});

                                total[x][y] += steps;
                                minDist = min(minDist, total[x][y]);
                            }
                        }
                    }
                }
                emptyLand --;

                // Once from a building minDist is INT_MAX, next cycles will also be INT_MAX
                // because emptyLand decreases by 1, but no grid[x][y] decreases correspondingly,
                // so "grid[x][y] == emptyLand" always fail, and no grid[x][y] can be visited in later cycle(s).
                if (minDist == INT_MAX) return -1;
            }
        }

        return minDist;
    }
};

// Works. Simplified from Solution5.
// Time Complexity: O(N2⋅M2)
// Space Complexity: O(N⋅M)
class Solution6 {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> total(m, vector<int> (n, 0));
        int emptyLand = 0, minDist, delta[] = {0, 1, 0, -1, 0};

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] != 1) continue; 
                // otherwise, grid[i][j] == 1, is a building

                queue<vector<int>> q;
                q.push({i, j});

                int steps = 0;
                minDist = INT_MAX;

                while (! q.empty()) {
                    ++ steps;
                    
                    for (int level = q.size(); level > 0; -- level) {
                        auto pos = q.front();
                        q.pop();

                        for (int d = 0; d < 4; ++ d) {
                            int x = pos[0] + delta[d];
                            int y = pos[1] + delta[d+1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == emptyLand) {
                                -- grid[x][y]; // decrease it to be emptyLand of next cycle.

                                q.push({x, y});
                                total[x][y] += steps;

                                minDist = min(minDist, total[x][y]);
                            }
                        }
                    }
                }
                emptyLand --;
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};


// Works.
class Solution5 {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto total = grid;
        int walk = 0, minDist, delta[] = {0, 1, 0, -1, 0};

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] == 1) { // building
                    minDist = -1;
                    auto dist = grid;
                    queue<vector<int>> q;
                    q.push({i, j});
                    while (! q.empty()) {
                        auto pos = q.front();
                        q.pop();
                        for (int d = 0; d < 4; ++ d) {
                            int i = pos[0] + delta[d];
                            int j = pos[1] + delta[d+1];
                            if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
                                -- grid[i][j];
                                dist[i][j] = dist[pos[0]][pos[1]] + 1;
                                total[i][j] += dist[i][j] - 1;
                                q.push({i, j});
                                if (minDist < 0 || minDist > total[i][j])
                                    minDist = total[i][j];
                            }
                        }
                    }
                    walk--;
                }
            }
        }
        return minDist;
    }
};

// Should work. Tested locally.
// NOT work for: [[1]]
class Solution4 {
    vector<pair<int, int> > dirs;
public:
    Solution() {
        dirs.push_back(pair<int, int>(-1, 0));
        dirs.push_back(pair<int, int>(1, 0));
        dirs.push_back(pair<int, int>(0, -1));
        dirs.push_back(pair<int, int>(0, 1));
    }

    int shortestDistance(vector<vector<int> >& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();

        vector<vector<int> > dist(m, vector<int>(n, 0));
        int minDist = 0, mark = 0;

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] != 1) continue;

                minDist = INT_MAX;
                queue<vector<int> > q;
                vector<int> v(3); v[0] = i, v[1] = j, v[2] = 0;
                q.push(v);

                while (! q.empty()) {
                    int x = q.front()[0], y = q.front()[1], d = q.front()[2] + 1;
                    q.pop();

                    for (int k = 0; k < dirs.size(); ++ k) {
                        int dx = x + dirs[k].first, dy = y + dirs[k].second;
                        if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == mark) {
                            dist[dx][dy] += d;
                            minDist = min(minDist, dist[dx][dy]);

                            v[0] = dx, v[1] = dy, v[2] = d;
                            q.push(v);
                            grid[dx][dy] = mark - 1;
                        }
                    }
                }

                -- mark;
            }
        }
        return minDist;
    }
};


// Should work. Tested locally. XC.
// NOT work for: [[1]]
// See discussion after Solution3.
class Solution3 {
public:
    int shortestDistance(vector<vector<int> >& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;

        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dist(m, vector<int>(n, 0));
        int mark = 0, ans = 0;

        vector<pair<int, int> > dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (grid[i][j] != 1) continue;

                queue<pair<int, int> > q;
                q.push(pair<int, int>(i, j));
                int d = 1;    
                ans = INT_MAX;
                while(! q.empty()) {
                    for(int ct = q.size(); ct > 0; -- ct) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        for (int k = 0; k < dirs.size(); ++ k) {
                            int dx = x + dirs[k].first, dy = y + dirs[k].second;
                            if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == mark) {
                                grid[dx][dy] = mark - 1;
                                dist[dx][dy] += d;
                                q.push(pair<int, int>(dx, dy));
                                ans = min(ans, dist[dx][dy]);
                            }
                        }
                    }
                    ++ d;
                }
                -- mark;
            }
        }

        return ans;
    }
};

/*
 Note: the value of grid and dist in each cycle is below.
 after all buildings are processed, the dist at each point
 is the sum of distances to all buildings. So 7 is the
 point with minimal distance sum to all buildings.

 The mark = 0, -1, -2, -3 .. is to lable a point as visited
 in the current cycle.

-- cycle 1:
grid:
1 -1 2 -1 1
-1 -1 -1 -1 -1
-1 -1 1 -1 -1
dist:
0 1 0 5 0
1 2 3 4 5
2 3 0 5 6

-- cycle 2:
grid:
1 -2 2 -2 1
-2 -2 -2 -2 -2
-2 -2 1 -2 -2
dist:
0 6 0 6 0
6 6 6 6 6
8 8 0 8 8

-- cycle 3:
grid:
1 -3 2 -3 1
-3 -3 -3 -3 -3
-3 -3 1 -3 -3
dist:
0 9 0 9 0
9 8 7 8 9
10 9 0 9 10

Note that current solutions all start from each building.
It makes sense since there are much more empty spaces than buildings.
If there are much more buildings than empty spaces, then it'll be
better to start from each empty space, use BFS to get sum of distances
to all buildings.
*/



// Solution2. Works. Best answer so far.
// From: https://leetcode.com/discuss/74453/36-ms-c-solution
int shortestDistance(vector<vector<int>> grid) {
    int m = grid.size(), n = grid[0].size();
    auto total = grid;
    int walk = 0, mindist, delta[] = {0, 1, 0, -1, 0};
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (grid[i][j] == 1) {
                mindist = -1;
                auto dist = grid;
                queue<pair<int, int>> q;
                q.emplace(i, j);  // Same as: q.push(pair<int,int>(i, j));
                while (q.size()) {
                    auto ij = q.front();
                    q.pop();
                    for (int d=0; d<4; ++d) {
                        int i = ij.first + delta[d];
                        int j = ij.second + delta[d+1];
                        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
                            grid[i][j]--;
                            dist[i][j] = dist[ij.first][ij.second] + 1;
                            total[i][j] += dist[i][j] - 1;
                            q.emplace(i, j);
                            if (mindist < 0 || mindist > total[i][j])
                                mindist = total[i][j];
                        }
                    }
                }
                walk--;
            }
        }
    }
    return mindist;
}

// Works. Tested.
// From: https://leetcode.com/discuss/75038/16ms-c-fastest-improvement-of-stefanporsches-code
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), mark=0, ans;

        vector<vector<int>> dist(m, vector<int>(n, 0));

        int dx[4] = {0, 1, 0, -1}; // up, right, down, left
        int dy[4] = {1, 0, -1, 0};

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[j][i]==1) {
                    // make_pair(j, i): same as: pair<int, int>(j, i).
                    vector<pair<int, int>> bfs(1, make_pair(j, i)), bfs2; 
                    int level=1;
                    ans=INT_MAX;
                    while (!bfs.empty()) {
                        for (auto p : bfs) {
                            int y=p.first, x=p.second;
                            for (int d=0; d<4; d++) {
                                int nx=x+dx[d], ny=y+dy[d];
                                if (0<=nx && nx<n && 0<=ny && ny<m && grid[ny][nx]==mark) {
                                    grid[ny][nx] = mark-1;
                                    dist[ny][nx] += level;
                                    ans = min(ans, dist[ny][nx]);
                                    bfs2.push_back(make_pair(ny, nx));
                                }
                            }
                        }
                        level++;
                        std::swap(bfs, bfs2);
                        bfs2.clear();
                    }
                    mark -= 1;
                }
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};

/**
Shortest Distance from All Buildings My Submissions Question
Difficulty: Hard

You want to build a house on an empty land which reaches all buildings 
in the shortest amount of distance. You can only move up, down, left 
and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total 
travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build 
such house according to the above rules, return -1.

Show Company Tags
Show Tags
Show Similar Problems

 */
