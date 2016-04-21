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
