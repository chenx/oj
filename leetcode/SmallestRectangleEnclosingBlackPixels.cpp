// Works. 
// O(mlog(n) + nlog(m)) time.
// From: https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/editorial/
// queue: front(), push(), pop();
// deque: front(), push_back(), pop_front(), push_front(), pop_back()
class Solution3 {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.size() == 0 || image[0].size() == 0) return 0;
        int m = image.size(), n = image[0].size();
        int minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;
        vector<int> dirs = {-1, 0, 1, 0, -1};

        deque<vector<int>> q;
        q.push_back({x, y});

        while (! q.empty()) {
            vector<int> p = q.front();
            q.pop_front();
            image[p[0]][p[1]] = '.';

            minx = min(minx, p[0]);
            maxx = max(maxx, p[0]);
            miny = min(miny, p[1]);
            maxy = max(maxy, p[1]);

            for (int k = 0; k < 4; ++ k) {
                int x = p[0] + dirs[k], y = p[1] + dirs[k+1];
                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == '1') {
                    q.push_back({x, y});
                }
            }
        }
        return (maxx - minx + 1) * (maxy - miny + 1);
    }
};

// Works. But time out for large input.
class Solution2 {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.size() == 0 || image[0].size() == 0) return 0;
        int m = image.size(), n = image[0].size();
        int minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;
        vector<int> dirs = {-1, 0, 1, 0, -1};

        queue<vector<int>> q;
        q.push({x, y});

        while (! q.empty()) {
            vector<int> p = q.front();
            q.pop();
            image[p[0]][p[1]] = '.';

            minx = min(minx, p[0]);
            maxx = max(maxx, p[0]);
            miny = min(miny, p[1]);
            maxy = max(maxy, p[1]);

            for (int k = 0; k < 4; ++ k) {
                int x = p[0] + dirs[k], y = p[1] + dirs[k+1];
                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == '1') {
                    q.push({x, y});
                }
            }
        }
        return (maxx - minx + 1) * (maxy - miny + 1);
    }
};

// Works. Tested. By: XC
// O(mn) in time.
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.size() == 0 || image[0].size() == 0) return 0;
        int m = image.size(), n = image[0].size();
        int minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;
        
        vector<pair<int, int>> d = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
        
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        image[x][y] = -1;
        
        while (! q.empty()) {
            int a = q.front().first, b = q.front().second;
            q.pop();
            
            if (a < minx) minx = a;
            if (a > maxx) maxx = a;
            if (b < miny) miny = b;
            if (b > maxy) maxy = b;
            
            for (int i = 0; i < d.size(); ++ i) {
                int dx = a + d[i].first, dy = b + d[i].second;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && image[dx][dy] == '1') {
                    q.push(make_pair(dx, dy));
                    image[dx][dy] = -1;
                }
            }
        }

        return (maxx - minx + 1) * (maxy - miny + 1);
    }
    
};


/**
Smallest Rectangle Enclosing Black Pixels
Difficulty: Hard

An image is represented by a binary matrix with 0 as a white pixel 
and 1 as a black pixel. The black pixels are connected, i.e., there 
is only one black region. Pixels are connected horizontally and 
vertically. Given the location (x, y) of one of the black pixels, 
return the area of the smallest (axis-aligned) rectangle that 
encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.
 */
