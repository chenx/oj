#include <iostream>

using namespace std;

//
// Goal: A
// series of objects (vi, wi): value is v, weight is w.
// Total weight W is fixed, maximize value V. (GBPB page 267).
// i.e., W >= sum(wi * xi), maximize V = sum(vi * xi).
// 
// 1) general search: backtracking.
//
// 2) if allow fraction, then order objects by v/w, and use greedy method. 
//    O(nlogn).
// 
// 3) Fraction not allowed. 0-1 knapsack.
//    DP. Construct table V[1..n, 0..W], 1 row for each obj, 1 col for each W.
//    V[i, j] = max(V[i-1, j], V[i-1, j - wi] + vi), when i > 0 and w >= wi;
//              v[i-1, j], when w < wi.
//    Here: V[i, j] means include objects 1 to i, total weight is j.
//          V[i-1, j] means include objects 1 to i - 1, totoal weight j.
//          V[i-1, j - wi] + vi means cost of V[i-1, j] changed by replacing one object in 1..j-1 with object i.
//    Time: Theta(nW) for constructing V. O(n+m) for finding the composition.
//    Note here first item is padding.
//    Reference: [1] http://www.eecs.wsu.edu/~cook/aa/lectures/l9/node12.html
//               [2] GBPB page 267.
//
// @By: Xin Chen
// @Created on: 12/10/2013
// @Last modified: 4/2/2013
//
void knapsack01 (int v[], int w[], int n, int W) {
    int i, j;
    int ** B = new int*[n];
    for (i = 0; i < n; i ++) { B[i] = new int[W]; }
    for (i = 0; i < W; i ++) { B[0][i] = 0; }
    
    for (i = 1; i < n; i ++) {
        B[i][0] = 0;
        for (j = 1; j <= W; j ++) {
            if (w[i] <= j) {
                if (B[i-1][j] < B[i-1][j-w[i]] + v[i]) {
                    B[i][j] = B[i-1][j-w[i]] + v[i];
                }
                else {
                    B[i][j] = B[i-1][j];
                }
            }  
            else {
                B[i][j] = B[i-1][j]; // wi > w.
            }
        }
    }
    
    // output result table. O(nW).
    for (j = 0; j <= W; j ++) {
        printf("%2d ", j);    
    }
    puts("");
    for (i = 0; i < n; i ++) {
      for (j = 0; j <= W; j ++) {
          printf("%2d ", B[i][j]);    
      }
      puts("");
    }
    puts("");
}


//
// Optimized from above.
//
int knapsack01_v2 (int v[], int w[], int n, int W) {
    int i, j;
    int B[n][W+1];
    memset(B, 0, sizeof(int) * n * (W+1));
    
    for (i = 1; i < n; i ++) {
        B[i][0] = 0;
        for (j = 1; j <= W; j ++) {
            if (j >= w[i]) {
                B[i][j] = max(B[i-1][j], B[i-1][j-w[i]] + v[i]);
            }  
            else {
                B[i][j] = B[i-1][j]; // wi > w.
            }
        }
    }
    
    return B[n-1][W];
}

//
// Optimized from above.
//
int knapsack01_v3 (int v[], int w[], int n, int W) {
    int i, j;
    int B[n+1][W+1];
    memset(B, 0, sizeof(int) * (n+1) * (W+1));
    
    for (i = 0; i < n; i ++) {
        for (j = 1; j <= W; j ++) {
            if (j >= w[i]) {
                B[i+1][j] = max(B[i][j], B[i][j-w[i]] + v[i]);
            }  
            else {
                B[i+1][j] = B[i][j]; // wi > w.
            }
        }
    }
    
    // output result table. O(nW).
    for (j = 1; j <= W; j ++) {
        printf("%2d ", j);    
    }
    puts("");
    for (i = 0; i <= n; i ++) {
      for (j = 1; j <= W; j ++) {
          printf("%2d ", B[i][j]);    
      }
      puts("");
    }
    puts("");
    
    return B[n][W];
}


void testKnapsack01() {
     // note first item is padding.
     int w[] = {0, 1,2,5,6,7}; //{10, 20, 30, 40, 50};
     int v[] = {0, 1,6,18,22,28}; //{20, 30, 66, 40, 60};
     int len = sizeof(v) / sizeof(int);
     int W_max = 11;
     knapsack01(v, w, len, W_max);
     cout << knapsack01_v2(v, w, len, W_max) << endl;
     
     
     int w3[] = {1,2,5,6,7}; //{10, 20, 30, 40, 50};
     int v3[] = {1,6,18,22,28}; //{20, 30, 66, 40, 60};
     cout << "v3" << endl << knapsack01_v3(v3, w3, len-1, W_max) << endl;
     puts("done");
}

int main() {
    testKnapsack01();
    return 0;    
}
