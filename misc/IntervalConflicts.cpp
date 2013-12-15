//
// Set intervals to conflict if they overlap with other intervals.
//
// @Author: Xin Chen
// @Created on: 4/8/2013
// @Last modified: 4/8/2013
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
using namespace std;

class Interval {
public:
    int start;
    int end;
    bool conflict;
    Interval(int s, int e) {
        start = s;
        end = e;
        conflict = false;
    }
};

// use this for vector. Note: must include const.
bool comp(const Interval &a, const Interval &b) {
    return a.start < b.start;
}

// use this for definition of map, set, priority_queue.
class cmp {
public:
    bool operator()(const Interval &a, const Interval &b) const {
        return a.start < b.start;
    }
};

class Solution {
public:
    void getConflict(vector<Interval> & v) {
        int n = v.size();
        if (n <= 1) return;
        
        //sort(v.begin(), v.end());
        sort(v.begin(), v.end(), comp);
        
        // maintain current end. If v[i] >= end, v[i] and v[i_end] are in conflict.        
        int end = v[0].end;
        int i_end = 0;
        
        for (int i = 1; i < v.size(); ++ i) {
            if (end >= v[i].start) {
                v[i].conflict = true;
                v[i_end].conflict = true;
            }
            if (end < v[i].end) {
                end = v[i].end;
                i_end = i;
            }
        }
    }
    
    void dumpVec(vector<Interval> & v) {
        for (int i = 0; i < v.size(); ++ i) {
            Interval & I = v[i];
            cout << "[" << v[i].start << ", " << v[i].end << ": " 
            << (v[i].conflict ? "true" : "false") << "]" << endl;
        }
        cout << endl;
    }
};

void test() {
    vector<Interval> v;
    int A[] = {
        1,1,
        0,3,
        5,6,
        6,8,
        9,15,
        10,11,
        12,13,
        16,17
    };
    int n = sizeof(A) / sizeof(int);
    
    for (int i = 0; i < n; i += 2) {
        Interval I(A[i], A[i+1]);
        v.push_back(I);
    }
    
    Solution s;
    
    s.dumpVec(v);
    s.getConflict(v);
    s.dumpVec(v);
}

//
// 1) For vector<Interval> v, can assign Interval &I = v[i].
//    But for map, set, priority_queue, cannot use reference.
// 2) For map, set, priority_queue, can use cmp class as comparator.
//    But cannot do this for queue or stack.
// 3) For map/set iterator, can include cmp or not, both ok.
// 4) For vector, use a bare function as comparator.
//    For map/set/priority_queue, use a class as comparator in declaration.
// 5) vector - an array; map/set - BST; priority_queue - array-based heap.
//
void test2() {
    map<Interval, int, cmp> m;
    set<Interval, cmp> s;
    //queue<Interval, cmp> q;
    //stack<Interval, cmp> t;
    priority_queue<Interval, vector<Interval>, cmp> p;
    
    int A[] = {
        1,1,
        2,3,
        5,6,
        6,8,
        9,15,
        10,11,
        12,13,
        16,17
    };
    int n = sizeof(A) / sizeof(int);
    
    for (int i = 0; i < n; i += 2) {
        Interval I(A[i], A[i+1]);
        m[I] = A[i];
        s.insert(I);
        p.push(I);
    }
    
    for (map<Interval, int, cmp>::iterator it = m.begin(); it != m.end(); ++ it) {
        Interval I = (*it).first;
        cout << "[" << I.start << ", " << I.end << "]" << endl;
    }
    cout << endl;
    //map<Interval, int> m2;
    //map<Interval, int>::iterator it = m2.begin();
    
    for (set<Interval, cmp>::iterator it = s.begin(); it != s.end(); ++ it) {
        Interval I = (*it);
        cout << "[" << I.start << ", " << I.end << "]" << endl;        
    }
    cout << endl;

    while (! p.empty()) {
        Interval I = p.top();
        cout << "[" << I.start << ", " << I.end << "]" << endl;
        p.pop();
    }
    cout << endl;
}

int main() {
    test();
    //test2();
    return 0;
}
