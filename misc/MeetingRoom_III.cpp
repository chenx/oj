// find the max number of guests in meeting, and the start time of that period of time.
// See: 
// http://www.geeksforgeeks.org/find-the-point-where-maximum-intervals-overlap/
// http://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// O(nlog(n)).
class Solution {
public:
    int findMaxGuests(vector<Interval>& intervals, int & maxTime) {
        int n = intervals.size();
        if (n == 0) return 0;

        vector<int> in(n), out(n);
        for (int i = 0; i < intervals.size(); ++ i) 
            in[i] = intervals[i].start, out[i] = intervals[i].end;
        
        sort(in.begin(), in.end());
        sort(out.begin(), out.end());
        
        maxTime = in[0];
        int maxGuests = 1, guests = 1;
        
        int i = 1, j = 0;
        while (i < n) {
            if (in[i] < out[j]) {
                ++ guests;
                if (guests > maxGuests) maxGuests = guests, maxTime = in[i];
                ++ i;
            }
            else {
                -- guests;
                ++ j;
            }
        }

        return maxGuests;
    }
};


// O(nlog(n)). Like merge sort.
// See: http://www.geeksforgeeks.org/find-the-point-where-maximum-intervals-overlap/
class Solution0 {
public:
    int findMaxGuests(vector<Interval>& intervals, int & maxTime) {
        if (intervals.size() == 0) return 0;
        int n = intervals.size();

        vector<int> in, out;
        for (int i = 0; i < n; ++ i) {
            in.push_back(intervals[i].start);
            out.push_back(intervals[i].end);
        }
        sort(in.begin(), in.end());
        sort(out.begin(), out.end());

        maxTime = in[0];
        int maxGuests = 1, guests = 1;
        int i = 1, j = 0;

        while (i < n) { // && j < n) {
            if (in[i] < out[j]) { // cannot be "<=", if <=, then a guest leaves at this point.
                guests ++;
                if (guests > maxGuests) {
                    maxGuests = guests, maxTime = in[i];
                }
                ++ i;
            }
            else {
                -- guests;
                ++ j;
            }
        }

        return maxGuests;
    }
}; 

void dump(vector<Interval> & v) {
    for (int i = 0; i < v.size(); ++ i) {
        cout << "[" << v[i].start << ", " << v[i].end << "] ";
    }
    cout << endl;
}


void test(vector<Interval> & v) {
    cout << "input: "; dump(v);
    vector<Interval> v0 = v;

    Solution so;
    Solution0 s0;
    int maxTime0 = 0, maxTime = 0;

    int expect = s0.findMaxGuests(v0, maxTime0);
    int answer = so.findMaxGuests(v, maxTime);

    cout << "expect: maxGuests = " << expect << ", maxTime = " << maxTime0
         << "\nanswer: maxGuests = " << answer << " maxTime = " << maxTime << ". "
         << (expect == answer ? "pass" : "fail <-----") << endl << endl;
}

void test1() {
    vector<Interval> v;
    v.push_back(Interval(0, 30));
    v.push_back(Interval(5, 10));
    v.push_back(Interval(15, 20));
    test(v);
}

void test2() {
    vector<Interval> v;
    v.push_back(Interval(0, 3));
    v.push_back(Interval(5, 10));
    v.push_back(Interval(15, 20));
    test(v);
}

void test3() {
    vector<Interval> v;
    v.push_back(Interval(0, 30));
    v.push_back(Interval(5, 10));
    v.push_back(Interval(15, 20));
    v.push_back(Interval(30, 40));
    test(v);
}

void test4() {
    vector<Interval> v;
    v.push_back(Interval(1, 2));
    v.push_back(Interval(2, 3));
    v.push_back(Interval(3, 4));
    test(v);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}
