//
// Painter's partition problem. 
// See: http://leetcode.com/2011/04/the-painters-partition-problem.html
// The difficulty is in partitioning. Which is O(n!) by default.
// Can be improved to O(n^2) with DP (not done yet).
// Then sum up paritions for each painter and get the total time are easy.
//
// @Author: Xin Chen
// @Created on: 4/5/2013
// @Last modified: 4/5/2013
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    //
    // Boards[i]: number of units of the i-th board. i in [1..N]
    // Painters[i]: time the i-th painter paints a unit of board. i in [1..k]
    //
    void painterPartition(vector<int> boards, vector<int> painters) {
        int N = boards.size();
        int K = painters.size();
        cout << "N = " << N << ", K = " << K << endl;
        
        vector<vector<int> > ans = getBoardDiv(boards, K);
        
        int sum, min_sum = INT_MAX, i_min = 0;
        vector<vector<int> > units(ans.size());
        for (int i = 0; i < ans.size(); ++ i) {        
            //
            // get units count sum for each painter.
            //
            vector<int> units_i(K);
            int bj = 0; // start index for each painter's partition.
            for (int j = 0; j < K; ++ j) {
                units_i[j] = 0;
                for (int k = 0; k < ans[i][j]; ++ k) {
                    units_i[j] += boards[bj + k];
                }
                //cout << "units[" << j << "] = " << units_i[j] << endl;
                bj += ans[i][j];
            }
            units[i] = units_i;
            
            sum = 0;
            for (int j = 0; j < K; ++ j) {
                sum += units[i][j] * painters[j];
            }
            
            //min_sum = min(sum, min_sum);
            if (min_sum > sum) {
                min_sum = sum;
                i_min = i;
            }
        }
        
        cout << "min sum [partition index=" << i_min << "]: " << min_sum << endl;
        
        cout << "sum_{paritition_units * time} = ";
        for (int i = 0; i < K; ++ i) {
            cout << units[i_min][i] << "*" << painters[i] << " ";
        }
        cout << endl;
        
    }
    
    //
    // Divide B into K divisions.
    //
    vector<vector<int> > getBoardDiv(vector<int> boards, int K) {
        vector<vector<int> > ans;
        int N = boards.size();
        
        int P[K]; 
        getDiv(N, K, P, 0, K, ans);
        
        for (int i = 0; i < ans.size(); ++ i) {
            //cout << i + 1 << ": ";
            //dumpVec(ans[i]);
        }
              
        return ans;
    }
    
    // N objects, divide into K partitions, store in P.
    void getDiv(int N, int K, int P[], int pos, int K0, vector<vector<int> > &ans) {
        static int ct = 0;
        //printf("%d: N=%d, K=%d\n", ++ct, N, K);
        if (K == 1) {
            P[pos] = N;
            //for (int i = 0; i < K0; ++ i) cout << P[i] << " "; cout << endl;
            ans.push_back(intToVec(P, K0));
            return;
        }
        for (int i = 1; i <= N - K + 1; ++ i) {
            P[pos] = i;
            getDiv(N-i, K-1, P, pos+1, K0, ans);
        }
    }
    
    vector<int> intToVec(int A[], int n) {
        vector<int> v;
        for (int i = 0; i < n; ++ i) {
            v.push_back(A[i]);
        }
        return v;
    }
    
    void dumpVec(vector<int> v) {
        for (int i = 0; i < v.size(); ++ i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void test() {
        int A[] = {100,200,300,400,500,5,1,1,1,1,1};
        int P[] = {1,2,3,4,0,4,4};

        painterPartition(
            intToVec(A, sizeof(A)/sizeof(int)), 
            intToVec(P, sizeof(P)/sizeof(int))
        );
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
};

int main() {
    Solution s;
    s.test();
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

The key function is:
    
    //
    // N objects, divide into K partitions. Each partition contains at least 1 object.
    // P stores how many objects are in each partition.
    // Author: Xin Chen
    //
    void getPartition(int N, int K, int P[], int pos, int K0) {
        if (K == 1) {
            P[pos] = N;
            for (int i = 0; i < K0; ++ i) cout << P[i] << " "; cout << endl;
            return;
        }
        //for (int i = 0; i <= N - K + 2; ++ i) { // use this if 0 is allowed.
        for (int i = 1; i <= N - K + 1; ++ i) { // be careful of "+1"
            P[pos] = i;
            getPartition(N-i, K-1, P, pos+1, K0);
        }
    }
    
 */
