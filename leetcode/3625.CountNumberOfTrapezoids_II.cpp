// From: https://leetcode.com/problems/count-number-of-trapezoids-ii/editorial/
// Time: O(n^2)
// Space: O(n^2)
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int inf = 1e9 + 7;
        unordered_map<float, vector<float>> slopeToIntercept;
        unordered_map<int, vector<float>> midToSlope;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x1 - x2, dy = y1 - y2;
                float k, b;
                if (x2 == x1) {
                    k = inf;
                    b = x1;
                } else {
                    k = (float)(y2 - y1) / (x2 - x1);
                    b = (float)(y1 * dx - x1 * dy) / dx;
                }
                int mid = (x1 + x2) * 10000 + (y1 + y2);
                slopeToIntercept[k].push_back(b);
                midToSlope[mid].push_back(k);
            }
        }
        for (auto& [_, sti] : slopeToIntercept) {
            if (sti.size() == 1) {
                continue;
            }
            map<float, int> cnt;
            for (float b : sti) {
                cnt[b]++;
            }
            int sum = 0;
            for (auto& [_, count] : cnt) {
                ans += sum * count;
                sum += count;
            }
        }
        for (auto& [_, mts] : midToSlope) {
            if (mts.size() == 1) {
                continue;
            }
            map<float, int> cnt;
            for (float k : mts) {
                cnt[k]++;
            }
            int sum = 0;
            for (auto& [_, count] : cnt) {
                ans -= sum * count;
                sum += count;
            }
        }
        return ans;
    }
};


/**
3625. Count Number of Trapezoids II
Hard
Topics
conpanies iconCompanies
Hint

You are given a 2D integer array points where points[i] = [xi, yi] represents the coordinates of the 
ith point on the Cartesian plane.

Return the number of unique trapezoids that can be formed by choosing any four distinct points from points.

A trapezoid is a convex quadrilateral with at least one pair of parallel sides. Two lines are parallel 
if and only if they have the same slope.

 

Example 1:

Input: points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]

Output: 2
 */
