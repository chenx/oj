// From: https://leetcode.com/problems/set-intersection-size-at-least-two/editorial/
// Greedy method.
// 
// Time Complexity: O(N2), where N is the length of intervals.
// Space Complexity: O(N).
//
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return b[1] < a[1];
            return a[0] < b[0];
        });

        int n = intervals.size();
        vector<int> todo(n, 2);

        int ans = 0;
        for (int t = n - 1; t >= 0; -- t) {
            int s = intervals[t][0];
            int e = intervals[t][1];
            int m = todo[t];
            for (int p = s; p < s+m; ++p) {
                for (int i = 0; i <= t; ++i) {
                    if (todo[i] > 0 && p <= intervals[i][1]) todo[i]--;
                }
                ans++;
            }
        }
        return ans;
    }
};


/**
757. Set Intersection Size At Least Two
Hard

You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers 
from starti to endi inclusively.

A containing set is an array nums where each interval from intervals has at least two integers in nums.

    For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.

Return the minimum possible size of a containing set.
 */
