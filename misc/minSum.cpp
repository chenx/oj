//
// Given a set of integer, you could apply sign operation to the integer, find
// the minimum sum that is close to but  no less than 0;
// eg.
// input 3 5 7 11 13
// output 1
// From: http://www.mitbbs.com/article_t/JobHunting/32377005.html
//
// Idea: 1) so far use brute force, get all combinations. O(2^n).
// 2) DP, Let F(n) be the set of all values so far, F(n+1) apply A[N+1} +/- each element in F(n).
//    In concept this is still F(N+1) = 2*F(n) so O(2^n), however there might be duplicated valudes
//    in F(n), so actual complexity is lower. The more duplication, the less the complexity.
//
// @Author: Xin Chen
// @Created on: 4/6/2013
// @Last modified: 4/6/2013 
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:       
    // brute force: get all combinations, get min.
    int minSum(int A[], int n) {
        vector<vector<int> > p;
        
        if (n == 0) {
            return 0;
        }
        
        vector<int> a01(1); a01[0] =  A[0]; p.push_back(a01);
        vector<int> a02(1); a02[0] = -A[0]; p.push_back(a02);
        
        for (int i = 1; i < n; ++ i) {
            // add A[i].
            int len = p.size();
            for (int j = 0; j < len; ++ j) {
                vector<int> copy = p[j];
                p[j].push_back(A[i]);
                copy.push_back(-A[i]);
                p.push_back(copy);
            }
        }
        
        // now calculate.
        int minsum = INT_MAX, sum, i_min = -1;
        for (int i = 0; i < p.size(); ++ i) {
            //dumpVec(p[i]);
            sum = sumVec(p[i]);
            if (sum >= 0 && sum < minsum) {
                minsum = sum;
                i_min = i;
            }
        }
        
        cout << "minsum = " << minsum << endl;
        dumpVec(p[i_min]);
        
        return 0;        
    }
    
    int sumVec(const vector<int> &v) {
        int sum = 0;
        for (int i = 0; i < v.size(); ++ i) {
            sum += v[i];
        }
        return sum;
    }
    
    void dumpVec(const vector<int> &v) {
        for (int i = 0; i < v.size(); ++ i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    // don't store entire vector, just the sum.
    int minSum2(int A[], int n) {
        vector<int> p;
        
        if (n == 0) {
            return 0;
        }
        
        p.push_back(A[0]);
        p.push_back(-A[0]);
        
        for (int i = 1; i < n; ++ i) {
            // add A[i].
            int len = p.size();
            for (int j = 0; j < len; ++ j) {
                int copy = p[j];
                p[j] += (A[i]);
                copy += -A[i];
                p.push_back(copy);
            }
        }
        
        // now calculate.
        int minsum = INT_MAX, sum, i_min = -1;
        for (int i = 0; i < p.size(); ++ i) {
            sum = p[i];
            if (sum >= 0 && sum < minsum) {
                minsum = sum;
                i_min = i;
            }
        }
        
        cout << "minsum = " << minsum << endl;
        //dumpVec(p[i_min]);
        
        return 0;        
    }
    
};

int main() {
    //int A[] = {1,2,3,4};
    int A[] = {3,5,7,11,13};
    int n = sizeof(A) / sizeof(int);
    
    Solution s;
    s.minSum(A, n);
    s.minSum2(A, n);
    
    return 0;
}
