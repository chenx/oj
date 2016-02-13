/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
// Tested. Works. Modified from Solution. O(n).
class Solution2 {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto interval : intervals){
            if(!min_heap.empty() && min_heap.top() <= interval.start) min_heap.pop();
            min_heap.push(interval.end);
        }
        return min_heap.size();
    }
    
    static bool comp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
};

// Works. Tested. O(n). Great Solution.
// From: https://leetcode.com/discuss/64686/concise-c-solution-with-min_heap-sort-greedy
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &i, Interval &j){return i.start < j.start;});
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto interval : intervals){
            if(!min_heap.empty() && min_heap.top() <= interval.start) min_heap.pop();
            min_heap.push(interval.end);
        }
        return min_heap.size();
    }
};

/**
Meeting Rooms II
Difficulty: Medium

Given an array of meeting time intervals consisting of start and end times 
[[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference 
rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
 */
