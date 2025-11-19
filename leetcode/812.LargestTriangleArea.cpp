// From: https://leetcode.com/problems/largest-triangle-area/editorial/
// Time Complexity: O(N3), where N is the length of points. 
//   We use three for-loops of length O(N), and our work calculating the area of a single triangle is O(1).
// Space Complexity: O(1).

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int N = points.size();
        double ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                for (int k = j+1; k < N; ++k)
                    ans = max(ans, area(points[i], points[j], points[k]));
        return ans;
    }

    double area(int[] P, int[] Q, int[] R) {
        return 0.5 * abs(P[0]*Q[1] + Q[0]*R[1] + R[0]*P[1]
                         -P[1]*Q[0] - Q[1]*R[0] - R[1]*P[0]);
    }
};


/**
812. Largest Triangle Area
Easy

Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle 
that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.
 */
