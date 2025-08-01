/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// Works.
class Solution3 {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end());
        // sort(intervals.begin(), intervals.end(), comp);

        for (int i = 0; i < intervals.size() - 1; i ++) {
            if (intervals[i][1] > intervals[i+1][0]) return false;
        }
        return true;
    }

    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};

// Works too.
class Solution2 {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        for (int i = 0, len = intervals.size() - 1; i < len; ++ i) {
            if (intervals[i].end > intervals[i+1].start) return false;
        }

        return true;
    }

    static bool comp(const Interval & a, const Interval & b) {
        return a.start < b.start;
    }
};


// Works. Tested. False if any 2 meetings overlap.
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        for (int i = 1; i < intervals.size(); ++ i) {
            if (intervals[i-1].end > intervals[i].start) return false;
        }
        return true;
    }
    
    static bool comp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
};

/**
Meeting Rooms My Submissions Question
Difficulty: Easy

Given an array of meeting time intervals consisting of start and end times 
[[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
 */
