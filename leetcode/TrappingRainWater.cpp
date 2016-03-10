//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/1/2013
// @Last modified: 1/1/2013
//
#include <iostream>
#include <stack>
using namespace std;


//
// if bar height decreases (or if first bar), push to stack.
// else if bar height same as previous bar, do nothing
// else (bar height increases) {
//     stack.top is the bottom of new container,
//     pop each bar on stack that's smaller than current bar, add area
//     for the last popped bar (whose height >= current bar), add area
//     finally, put current bar to stack.
// }
//
class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) return 0;
        
        stack<int> H; // store height of bars.
        stack<int> P; // store position of bars.
        int i, bot, width, Area = 0;
        for (i = 0; i < n; i ++) {
            if (H.size() == 0 || A[i] <= H.top()) {
                H.push(A[i]);
                P.push(i);
            }
            else if (A[i] == H.top()) {
                // do nothing.
            }
            else { // H.size() > 0 && A[i] > H.top().
                bot = H.top();
                H.pop();
                P.pop();
                width = 0;
                while (H.size() > 0 && H.top() < A[i]) {
                    width = i - P.top() - 1;
                    Area += width * (H.top() - bot);
                    bot = H.top();
                    H.pop();
                    P.pop();
                }
                if (H.size() > 0) { // last bar.
                    width = i - P.top() - 1;
                    Area += width * (A[i] - bot);
                }
                H.push(A[i]);
                P.push(i);
            }
        } // end of for
        
        return Area;
    }
};

// Optimized from Solution, by using P only. H can be obtained from P.
// Harder to understand though.
class Solution2 {
public:
    int trap(int A[], int n) {
        if (n <= 2) return 0;
        
        stack<int> P; // store position of bars.
        int i, bot, width, Area = 0;
        for (i = 0; i < n; i ++) {
            if (P.size() == 0 || A[i] <= A[P.top()]) {
                P.push(i);
            }
            else if (A[i] == A[P.top()]) { // note this branch is not needed, as it's included in the above branch.
                // do nothing.
            }
            else { // H.size() > 0 && A[i] > H.top().
                bot = A[P.top()];
                P.pop();
                // width = 0; // not necessary.
                while (P.size() > 0 && A[P.top()] < A[i]) {  // <= A[i] also works.
                    width = i - P.top() - 1;
                    Area += width * (A[P.top()] - bot);
                    bot = A[P.top()];
                    P.pop();
                }
                if (P.size() > 0) { // last bar.
                    width = i - P.top() - 1;
                    Area += width * (A[i] - bot);
                }
                P.push(i);
            }
        } // end of for
        
        return Area;
    }
};

// This works too. Is more clean that Solution2. 11/17/2014.
class Solution3 {
public:
    int trap(int A[], int n) {
        int n = A.size(), water = 0;
        stack<int> h;

        for (int i = 0; i < n; ++ i) {
            if (h.empty() || A[i] <= A[h.top()]) {
                h.push(i);
            }
            else {
                int bottom = A[h.top()];
                h.pop();
                while (! h.empty() && A[h.top()] <= A[i]) {
                    water += (A[h.top()] - bottom) * (i - 1 - h.top());
                    bottom = A[h.top()];
                    h.pop();
                }
                if (! h.empty()) {
                    water += (A[i] - bottom) * (i - 1 - h.top());
                }
                h.push(i);
            }
        }
        
        return water;
    }
};


// Works too. Improved from Solution3. Most clean.
class Solution4 {
public:
    int trap(vector<int>& A) {
        int n = A.size(), water = 0;
        stack<int> h;

        for (int i = 0; i < n; ++ i) {
            if (! h.empty() && A[i] > A[h.top()]) {
                int bottom = A[h.top()];
                h.pop();
                while (! h.empty() && A[h.top()] <= A[i]) {
                    water += (A[h.top()] - bottom) * (i - 1 - h.top());
                    bottom = A[h.top()];
                    h.pop();
                }
                if (! h.empty()) {
                    water += (A[i] - bottom) * (i - 1 - h.top());
                }
            }
            h.push(i);
        }
        
        return water;
    }
};


int main() {
    Solution s;
    int A[] = {5,3,5, 4, 5}; 
    //int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int len = sizeof(A) / sizeof(int);
    printf("Rain trapped = %d\n", s.trap(A, len));
    return 0;
}

/*
Problem:
        
Given n non-negative integers representing an elevation map 
where the width of each bar is 1, compute how much water it 
is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
 */
