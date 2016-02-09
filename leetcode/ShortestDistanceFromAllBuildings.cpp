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
