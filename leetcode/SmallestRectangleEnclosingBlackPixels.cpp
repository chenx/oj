// Works. Tested. By: XC
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
