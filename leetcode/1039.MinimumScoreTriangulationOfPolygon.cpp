// From: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/editorial/
// Dynamic Programming
// Time complexity: O(n3). There are O(n2) DP states, and computing each state takes O(n).
// Space complexity: O(n2), corresponding to the number of DP states.
//
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        unordered_map<int, int> memo;
        int n = values.size();
        function<int(int, int)> dp = [&](int i, int j) -> int {
            if (i + 2 > j) {
                return 0;
            }
            if (i + 2 == j) {
                return values[i] * values[i + 1] * values[j];
            }
            int key = i * n + j;
            if (!memo.count(key)) {
                int minScore = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    minScore = min(minScore, values[i] * values[k] * values[j] +
                                                 dp(i, k) + dp(k, j));
                }
                memo[key] = minScore;
            }
            return memo[key];
        };
        return dp(0, n - 1);
    }
};


/**
1039. Minimum Score Triangulation of Polygon
Medium

You have a convex n-sided polygon where each vertex has an integer value. You are given an 
integer array values where values[i] is the value of the ith vertex in clockwise order.

Polygon triangulation is a process where you divide a polygon into a set of triangles and 
the vertices of each triangle must also be vertices of the original polygon. Note that no 
other shapes other than triangles are allowed in the division. This process will result 
in n - 2 triangles.

You will triangulate the polygon. For each triangle, the weight of that triangle is the 
product of the values at its vertices. The total score of the triangulation is the sum of 
these weights over all n - 2 triangles.

Return the minimum possible score that you can achieve with some triangulation of the polygon.
 */
