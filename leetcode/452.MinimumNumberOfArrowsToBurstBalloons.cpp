// From: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/editorial/
// Time: O(nlogn)
// Space: O(1)
class Solution2 {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return n;

        sort(points.begin(), points.end(), [&](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1, end = points[0][1];
        for (int i = 1; i < n; ++ i) {
            if (points[i][0] > end) {
                ++ arrows;
                end = points[i][1];
            }
        }
        return arrows;
    }
};

// Works. O(n*log(n)) time b/c sorting, O(1) space.
// Idea: if 
//   |----|
//      |------|
// Then only need to keep this range:
//      |-|
// Actually here just keep this because it's sorted, and the segment in the front does not matter.
//   |----|
// Time: O(nlogn)
// Space: O(n)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return n;

        sort(points.begin(), points.end(), comp);

        vector<vector<int>> ans;
        for (int i = 1; i < n; ++ i) {
            vector<int> &a = points[i - 1], &b = points[i];
            if (a[1] < b[0]) {  // if no overlap, a needs 1 arrow.
                ans.push_back(a); 
            } else if (a[1] <= b[1]) {  // has overlap, a and b share 1 arrow in range {b[0], a[1]}
                b[1] = a[1];
            } else {
                // do nothing
            }
        }
        return ans.size() + 1;  // add 1 for the last range
    }

    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
};

/**
There are some spherical balloons taped onto a flat wall that represents the XY-plane. 
The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes 
a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact 
y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along 
the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. 
There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, 
bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
 */
