// Works too.
// Difference is in the definition of pointSet.
class Solution2 {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<vector<int>> pointSet;
        for (auto point: points) pointSet.insert(point);

        int ans = INT_MAX;
        for (int i = 0; i < points.size(); ++i)
            for (int j = i+1; j < points.size(); ++j) {
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    if (pointSet.contains({points[i][0], points[j][1]}) &&
                        pointSet.contains({points[j][0], points[i][1]}) 
                    ) {
                        int area = abs(points[j][0] - points[i][0]) *
                                   abs(points[j][1] - points[i][1]);
                        ans = min(ans, area);
                    }
                }
            }

        return ans < INT_MAX ? ans : 0;
    }
};

// From: https://leetcode.com/problems/minimum-area-rectangle/editorial/
// Time Complexity: O(N2), where N is the length of points.
// Space Complexity: O(N).
class Solution {
    int getKey(int x, int y) {
        return 40001 * x + y;
    }
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<int> pointSet;
        for (auto point: points)
            pointSet.insert(getKey(point[0], point[1]));

        int ans = INT_MAX;
        for (int i = 0; i < points.size(); ++i)
            for (int j = i+1; j < points.size(); ++j) {
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    if (pointSet.contains(getKey(points[i][0], points[j][1])) &&
                        pointSet.contains(getKey(points[j][0], points[i][1])) 
                    ) {
                        int area = abs(points[j][0] - points[i][0]) *
                                   abs(points[j][1] - points[i][1]);
                        ans = min(ans, area);
                    }
                }
            }

        return ans < INT_MAX ? ans : 0;
    }
};

/**
939. Minimum Area Rectangle
Medium

You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. 
If there is not any such rectangle, return 0.
 */
