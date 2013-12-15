//
// Partition problem. A classical DP problem.
//
// See: http://leetcode.com/2011/04/the-painters-partition-problem.html
// O(n!) by default.
// Can be improved to O(n^2) with DP (not done yet).
//
// @Author: Xin Chen
// @Created on: 4/10/2013
// @Last modified: 4/10/2013
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // Divide N objects into K partitions.
    // Can reduce to DP O(N^2) by storing DP[N][K] as vector<vector<int> > DP.
    void partition(int N, int K, int P[], int pos, int K0) {
        if (K == 1) {
            P[pos] = N;
            for (int i = 0; i < K0; ++ i) cout << P[i] << " "; cout << endl;
            return;
        }
        //for (int i = 0; i <= N - K + 2; ++ i) { // use this if 0 is allowed.
        for (int i = 1; i <= N - K + 1; ++ i) { // be careful of "+1"
            P[pos] = i;
            partition(N-i, K-1, P, pos+1, K0);
        }
    }
        
    void dumpVec(vector<int> v) {
        for (int i = 0; i < v.size(); ++ i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void test() {
        int N = 4, K = 1;
        int P[N];
        
        //for (int K = 1; K <= N; ++ K) 
        {
            partition(N, K, P, 0, K);
        }
    }
    
    void partition2(int A[], int N, int K, int P[], int pos, int K0) {
        if (K == 1) {
            P[pos] = N;
            int sum = 0;
            for (int i = 0; i < K0; ++ i) {
                cout << P[i] << " "; 
                //sum += A
            }
            cout << endl;
            return;
        }
        for (int i = 0; i <= N - K + 2; ++ i) { // use this if 0 is allowed.
        //for (int i = 1; i <= N - K + 1; ++ i) { // be careful of "+1"
            P[pos] = i;
            partition2(A, N-i, K-1, P, pos+1, K0);
        }
    }    
    // K: number of painters.
    void findMax_r(int A[], int N, int K) {
        int P[K];
        for (int k = 1; k <= K; ++ k) {
            partition2(A, N, K, P, 0, K);
        }
    }
    
    //
    // O(KN^2) time, O(KN) space. DP.
    // M[i][j]: minimum value of max sum of assigning i objects in A[] to j partitions.
    //
    int findMax(int A[], int n, int k) {
      const int MAX_N = 100;
      int M[MAX_N+1][MAX_N+1] = {0};
      int cum[MAX_N+1] = {0};
      for (int i = 1; i <= n; i++)
        cum[i] = cum[i-1] + A[i-1];
     
      for (int i = 1; i <= n; i++)
        M[i][1] = cum[i];
      for (int i = 1; i <= k; i++)
        M[1][i] = A[0];
     
      for (int i = 2; i <= k; i++) {
        for (int j = 2; j <= n; j++) {
          int best = INT_MAX;
          for (int p = 1; p <= j; p++) {
            best = min(best, max(M[p][i-1], cum[j]-cum[p])); // ?
          }
          M[j][i] = best;
        }
      }
      
      for (int i = 0; i <= n; ++ i) {
          for (int j = 0; j <= k; ++ j) {
              cout << M[i][j] << " ";
          }
          cout << endl;
      }
      cout << endl;
      
      return M[n][k];
    }
    
    // for practice. Same as findMax.
    int findMax3(int A[], int N, int K) {
        int M[1+N][1+K]; // M[i][j] - minimal value of max sum of dividing i objects of A[] to j partitions.
        memset(M, 0, sizeof(int) * (1+N) * (1+K));
        int cum[1+N];
        memset(cum, 0, sizeof(int) * (1+N));
        
        for (int i = 1; i <= N; ++ i) cum[i] = cum[i-1] + A[i-1];
        
        for (int i = 1; i <= N; ++ i) M[i][1] = cum[i];
        for (int i = 1; i <= K; ++ i) M[1][i] = A[0];
        
        for (int i = 2; i <= K; ++ i) {
            for (int j = 2; j <= N; ++ j) {
                int best = INT_MAX;
                for (int p = 1; p <= j; ++ p) {
                    best = min(best, max(M[p][i-1], cum[j] - cum[p]));
                }
                M[j][i] = best;
            }
        }
        
        for (int i = 0; i <= N; ++ i) {
            for (int j = 0; j <= K; ++ j) {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        return M[N][K];
    }

};

int main() {
    Solution s;
    s.test();
    
    int A[] = {1,3,5,4,6,7};
    int N = sizeof(A) / sizeof(int);
    s.findMax(A, N, 3);
    s.findMax3(A, N, 3);
        
    cout << "recursive version: ";
    //s.findMax_r(A, N, 3);
    
    return 0;
}

/*
Problem:

See: http://leetcode.com/2011/04/the-painters-partition-problem.html

You have to paint N boards of length {A0, A1, A2 … AN-1}. There are K painters 
available and you are also given how much time a painter takes to paint 1 unit 
of board. You have to get this job done as soon as possible under the 
constraints that any painter will only paint continuous sections of board, say 
board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

 */
