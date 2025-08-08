//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/9/2013
// @Last modified: 1/9/2013
//

// Works. 2025 version.
class Solution5 {
public:
   vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int n = intervals.size();
       if (n <= 1) return intervals;

       sort(intervals.begin(), intervals.end(), comp);

       vector<vector<int>> ans;
       for (int i = 1; i < n; i ++) {
           auto& a = intervals[i-1], &b = intervals[i];
           if (a[1] < b[0]) {
               ans.push_back(a);
           } else if (a[1] <= b[1]) {
               b[0] = a[0];
           } else {
               b[0] = a[0], b[1] = a[1];
           }
       }
       ans.push_back(intervals[n-1]);
       return ans;
   }

   static bool comp(const vector<int>& a, const vector<int>& b) {
       return a[0] < b[0];
   }
};


// Works. Best so far.
class Solution4 {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;
        
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), comp);
        
        for (int i = 1; i < n; ++ i) {
            Interval & a = intervals[i-1],
                     & b = intervals[i];
            if (a.end < b.start) {
                ans.push_back(a);
            }
            else if (a.end <= b.end) {
                b.start = a.start;
            }
            else {
                b.start = a.start;
                b.end = a.end;
            }
        }
        ans.push_back(intervals[n-1]);
        
        return ans;
    }
    
private:
    static bool comp(const Interval & a, const Interval & b) {
        return a.start < b.start;
    }
};

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

void dump(vector<Interval> &v) {
     for (int i = 0; i < v.size(); ++ i) {
         printf("[%d, %d] ", v[i].start, v[i].end);
     }
     puts("");
}
 
bool comp(const Interval &a, const Interval &b) {
    return a.start < b.start; // Note: be care of the format!
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> vs;
        sort(intervals.begin(), intervals.end(), comp);
        //printf("dump: "); dump(intervals);
        
        while (! intervals.empty()) {
            if (intervals.size() == 1) {
                vs.push_back(intervals[0]);
            }
            else {
                Interval tmp = intervals[0];
                Interval tmp2 = intervals[1];
                //printf("tmp = [%d, %d], tmp2 = [%d, %d]\n", tmp.start, tmp.end, tmp2.start, tmp2.end);
                if (tmp.end < tmp2.start) {
                    //printf("vs.push_back([%d, %d])\n", tmp.start, tmp.end);
                    vs.push_back(tmp);
                }
                else if (tmp.end >= tmp2.start && tmp.end <= tmp2.end) {
                    //printf("merge 1\n");
                    intervals[1].start = intervals[0].start;
                }    
                else { // tmp.end > tmp2.end.
                    //printf("merge 2\n");
                    intervals[1].start = intervals[0].start;
                    intervals[1].end = intervals[0].end;
                }
            }
            intervals.erase(intervals.begin());
        }
        
        return vs;
    }
};


//
// This works too.
//
class Solution2 {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), comp);
        
        while (! intervals.empty()) {
            if (intervals.size() == 1) {
                ans.push_back(intervals[0]);
            }
            else {
                Interval &a = intervals[0];
                Interval &b = intervals[1];
                
                if (a.end < b.start) {
                    ans.push_back(a);
                }
                else if (a.end > b.end) {
                    b.start = a.start, b.end = a.end;
                }
                else {
                    b.start = a.start;
                }
            }
            
            intervals.erase(intervals.begin());
        }        
        return ans;
    }
};

// This works too, and is more efficient since no erase is used!
// 1/4/2013
class Solution3 {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> ans;
        
        int n = intervals.size();
        for (int i = 0; i < n-1; ++ i) {
            Interval &a = intervals[i];
            Interval &b = intervals[i+1];
            if (a.end < b.start) { ans.push_back(a); }
            else if (a.end <= b.end) { b.start = a.start; }
            else { b.start = a.start; b.end = a.end; }
        }
        ans.push_back(intervals[n-1]);
        
        return ans;
    }
};


int main() {
    Solution s;
    vector<Interval> v;
    Interval i1(1, 4);
    Interval i2(4, 5);
    v.push_back(i1);
    v.push_back(i2);
    
    printf("before: "); dump(v);
    vector<Interval> w = s.merge(v);
    printf("after:  "); dump(w);
        
    return 0;
}

/*
Problem:

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18]. 
 */
