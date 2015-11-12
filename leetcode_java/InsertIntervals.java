/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        intervals.add(newInterval);
        return merge(intervals);
    }

    public List<Interval> merge(List<Interval> intervals) {
        int len = intervals.size();
        if (len <= 1) return intervals;

        List<Interval> ans = new ArrayList<Interval>();
        Collections.sort(intervals, new Comp());
        
        for (int i = 0; i < len - 1; ++ i) {
            Interval a = intervals.get(i);
            Interval b = intervals.get(i+1);
            if (a.end < b.start) {
                ans.add(a);
            }
            else if (a.end <= b.end) {
                b.start = a.start;
            }
            else {
                b.start = a.start;
                b.end = a.end;
            }
        }
        ans.add(intervals.get(len - 1));
        
        return ans;
    }
    
    class Comp implements Comparator<Interval> {
        @Override
        public int compare(Interval a, Interval b) {
            if (a.start == b.start) {
                if (a.end == b.end) return 0; // this is neede!
                return a.end < b.end ? -1 : 1;
            }
            return a.start < b.start ? -1 : 1;
        }
    }    
}

/**
Insert Interval
Difficulty: Hard

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
 */
