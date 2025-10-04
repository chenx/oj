/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution2 {
    public int[][] merge(int[][] intervals) {
        List<int[]> ans = new ArrayList<>();
        
        Arrays.sort(intervals, (a, b) -> { return a[0] - b[0]; });  // lamda function.
        
        for (int i = 0; i < intervals.length - 1; ++ i) {
            int[] a = intervals[i], b = intervals[i+1];
            
            if (a[1] < b[0]) {
                ans.add(a);
            } else if (a[1] <= b[1]) {
                b[0] = a[0];
            } else {  // a[1] > b[1]
                b[0] = a[0];
                b[1] = a[1];
            }
        }
        ans.add(intervals[intervals.length - 1]);  // add last item.
        
        int[][] ret = new int[ans.size()][2];
        for (int i = 0; i < ans.size(); ++ i) {
            ret[i] = ans.get(i);
        }
        return ret;
    }
}

public class Solution {
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
Merge Intervals
Difficulty: Hard

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18]. 
 */
