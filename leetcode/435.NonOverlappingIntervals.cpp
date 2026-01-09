class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort in order of increasing end points.
        auto comp = [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        };
        sort(intervals.begin(), intervals.end(), comp);

        int prev_end = INT_MIN, result = 0;
        for (int i = 0; i < intervals.size(); ++ i) {
            int x = intervals[i][0], y = intervals[i][1];

            if (x < prev_end) ++ result;
            else prev_end = y;
        }
        return result;
    }
};


/**
435. Non-overlapping Intervals
Medium

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals 
you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
 */
