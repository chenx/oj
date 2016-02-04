// The 2 solutions below are from: http://www.cnblogs.com/jcliBlogger/p/4704781.html
// Also see: https://leetcode.com/discuss/questions/oj/flatten-2d-vector

// This works too. Simpler.
 1 class Vector2D {
 2 public:
 3     Vector2D(vector<vector<int>>& vec2d) {
 4         int row = vec2d.size();
 5         for (int r = 0; r < row; r++) {
 6             int col = vec2d[r].size();
 7             for (int c = 0; c < col; c++)
 8                 data.push_back(vec2d[r][c]);
 9         }
10         idx = 0;
11     }
12 
13     int next() {
14         return data[idx++];
15     }
16 
17     bool hasNext() {
18         return idx < data.size();
19     }
20 private:
21     vector<int> data;
22     int idx;
23 };
24 
25 /**
26  * Your Vector2D object will be instantiated and called as such:
27  * Vector2D i(vec2d);
28  * while (i.hasNext()) cout << i.next();
29  */

// Works. 
 1 class Vector2D {
 2 public:
 3     Vector2D(vector<vector<int>>& vec2d) {
 4         data = vec2d;
 5         r = c = 0;
 6         row = vec2d.size();
 7         col = (row == 0 ? -1 : data[r].size());
 8         skipEmptyVector();
 9     }
10 
11     int next() {
12         int elem = data[r][c];
13         if (c == col - 1) {
14             r++;
15             c = 0;
16             col = data[r].size();
17         }
18         else c++;
19         skipEmptyVector();
20         return elem;
21     }
22 
23     bool hasNext() {
24         return col != -1 && (r < row && c < col);
25     }
26 private:
27     vector<vector<int>> data;
28     int row, col, r, c;
29     void skipEmptyVector(void) {
30         while (!col) {
31             r++;
32             col = data[r].size();
33         }
34     }
35 };
36 
37 /**
38  * Your Vector2D object will be instantiated and called as such:
39  * Vector2D i(vec2d);
40  * while (i.hasNext()) cout << i.next();
41  */

/**
Flatten 2D Vector
Difficulty: Medium

Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]

By calling next repeatedly until hasNext returns false, the order 
of elements returned by next should be: [1, 2, 3, 4, 5, 6].
 */
