//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/9/2013
//

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

// Works. Assume input intervals list is sorted with no overlapping.
// http://www.lintcode.com/en/problem/insert-interval/
class Solution2 {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        bool inserted = false;
        for (int i = 0; i < intervals.size(); ++ i) {
            if (newInterval.start <= intervals[i].start) {
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
                break;
            }
        }
        if (! inserted) intervals.push_back(newInterval);
        
        return merge(intervals);
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) return intervals;

        vector<Interval> ans;
        int n = intervals.size();
        //sort(intervals.begin(), intervals.end(), comp);
        
        for (int i = 1; i < n; ++ i) {
            Interval & a = intervals[i-1], & b = intervals[i];
            if (a.end < b.start) ans.push_back(a);
            else if (a.end <= b.end) b.start = a.start;
            else {
                b.start = a.start;
                b.end = a.end;
            }
        }
        ans.push_back(intervals[n-1]);
        
        return ans;
    }
    
    static bool comp(const Interval & a, const Interval & b) {
        return a.start < b.start;
    }
};


bool comp(const Interval a, const Interval b) {
    return a.start < b.start;
}

// Method: make use of MergeIntervals solution:
// Insert new interval into intervals, sort by start value, then merge.
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> vs;
        sort(intervals.begin(), intervals.end(), comp);
        
        while (intervals.size() > 0) {
            if (intervals.size() == 1) {
                vs.push_back(intervals[0]);
            }
            else {
                Interval tmp = intervals[0];
                Interval tmp2 = intervals[1];

                if (tmp.end < tmp2.start) {
                    vs.push_back(tmp);
                }
                else if (tmp.end >= tmp2.start && tmp.end <= tmp2.end) {
                    intervals[1].start = intervals[0].start;
                }    
                else { // tmp.end > tmp2.end.
                    intervals[1].start = intervals[0].start;
                    intervals[1].end = intervals[0].end;
                }
            }
            intervals.erase(intervals.begin());
        }
        
        return vs;
    }
};

/*
Problem:
        
Given a set of non-overlapping intervals, insert a new interval 
into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according 
to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] 
in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
 */
