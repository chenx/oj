//
// Skyline Problem.
// @Author: Xin Chen
// @Created on: 12/12/2013
// @Last modified: 12/12/2013
//

#include <iostream>
#include <queue>
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
    int height;
    Interval(int s, int e, int h) : start(s), end(e), height(h) {}
};

void dump(vector<Interval> &v) {
     for (int i = 0; i < v.size(); ++ i) {
         printf("[%d, %d, h=%d] ", v[i].start, v[i].end, v[i].height);
     }
     puts("");
}

bool comp(const Interval a, const Interval b) {
    return a.start < b.start; // Note: be care of the format!
}

// This solution seems to work, given used test cases.
// 
// Note, sort operation can be changed by using a bst or min-heap, 
// then insert in order is log(n) instead of n*log(n).
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        while (1) {
            if (intervals.size() == 1) {
                ans.push_back(intervals[0]);
                return ans;
            }
            
            Interval &a = intervals[0];
            Interval &b = intervals[1];
            
            if (a.end < b.start) {
                ans.push_back(a);
            }
            else if (a.end <= b.end) {
                if (a.height == b.height) {
                    b.start = a.start; // merge a into b.
                }
                else if (a.height < b.height) { // split.
                    a.end = b.start;
                    ans.push_back(a);
                }
                else { // a.height > b.height
                    b.start = a.end;
                    ans.push_back(a);
                    sort(intervals.begin(), intervals.end(), comp);
                }
            }
            else {
                if (a.height >= b.height) {
                    b.start = a.start; // merge b into a.
                    b.end = a.end;
                }
                else { // split.
                    Interval c(b.end, a.end, a.height);
                    a.end = b.start;
                    ans.push_back(a);
                    
                    intervals.push_back(c);
                    sort(intervals.begin(), intervals.end(), comp);
                }
            }
            intervals.erase(intervals.begin());
        }
    }
};

void dump(const Interval &a) {
    cout << "[" << a.start << ", " << a.end << ", " << a.height << "]" << endl;
}

class comp2 {
public:
    bool operator() (const Interval &a, const Interval &b) {
        return a.start > b.start; // min heap!
    }
};

// This works! Is n*log(n). Use min-heap.
class Solution2 {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        
        priority_queue<Interval, vector<Interval>, comp2> q;
        
        for (int i = 0; i < intervals.size(); ++ i) {
            q.push(intervals[i]);
        }
        
        while (1) {
            //cout << "while. q.size = " << q.size() << endl;
            if (q.size() == 1) {
                ans.push_back(q.top());
                return ans;
            }
            
            Interval a = q.top(); q.pop();
            Interval b = q.top(); q.pop();
            //dump(a); dump(b);
            
            if (a.end < b.start) {
                ans.push_back(a);
            }
            else if (a.end <= b.end) {
                if (a.height == b.height) {
                    b.start = a.start; // merge a into b.
                }
                else if (a.height < b.height) { // split.
                    a.end = b.start;
                    ans.push_back(a);
                }
                else { // a.height > b.height
                    b.start = a.end;
                    ans.push_back(a);
                }
            }
            else {
                if (a.height >= b.height) {
                    b.start = a.start; // merge b into a.
                    b.end = a.end;
                }
                else { // split.
                    Interval c(b.end, a.end, a.height);
                    a.end = b.start;
                    ans.push_back(a);
                    
                    q.push(c);
                }
            }
            q.push(b);
        }
    }
};


int test1() {
    Solution s;
    vector<Interval> v;
    
    Interval i1(0, 2, 3);
    Interval i2(2, 4, 3);
    
    v.push_back(i1);
    v.push_back(i2);
    
    printf("before: "); dump(v);
    vector<Interval> w = s.merge(v);
    printf("after:  "); dump(w);
}

int test2() {
    Solution s;
    vector<Interval> v;
    vector<Interval> v2;
    
    v.push_back(Interval(2,5,10));
    v.push_back(Interval(6,10,2));
    v.push_back(Interval(11,13,6));
    v.push_back(Interval(1,6,1));
    v.push_back(Interval(8,12,8));
    v.push_back(Interval(13,15,3));
    
    v2 = v;
    
    cout << "\nvector solution: " << endl;
    printf("before: "); dump(v);
    vector<Interval> w = s.merge(v);
    printf("after:  "); dump(w);
    
    cout << "\nheap solution: " << endl;
    Solution2 s2;
    printf("before: "); dump(v2);
    vector<Interval> w2 = s2.merge(v2);
    printf("after:  "); dump(w2);
    
}

int main() {
    test1();
    //test2();
    return 0;
}

/*
Problem:
see: http://www.mitbbs.com/article_t/JobHunting/32579865.html
 or: http://www.mitbbs.com/article_t/JobHunting/32569901.html
 
Given a collection of intervals/speaker volumns, 
merge all overlapping intervals with skyline (max volumn in each segment).

For example,
S1: {[2,5], vol=10}, {[6,10], vol=2}, ...
S2: {[1,6], vol=1}, {[8,12], vol=8}, ...

Output is:
[1,2],vol=1, [2,5], vol=10, [5,6], vol = 1, [6,8], vol = 2, [8,12], vol = 8.
 */
