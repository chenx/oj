// 
// This actually is minimax strategy.
//
// See here for solution:
// http://leetcode.com/2011/02/coins-in-line.html
//
// @Author: Xin Chen
// @Created on: 12/11/2012
// @Last modified: 3/23/2013
//

#include <windows.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // This is optimized from pick(). Use memorization to decrease time complexity 
    // from O(2^n) to O(n^2). Space is O(n^2).
    int pick2(int A[], int left, int right, int * sum2, 
              int n, int **p, int **sum) {
      if (left == right) {
           //puts("END 2");
           * sum2 = 0;
           return A[left];
       }
      
       int p21, p22, sum11, sum12;
       
       if (p[left+1][right] == -1) {   
           p21 = pick2(A, left+1, right, & sum11, n, p, sum);
           p[left+1][right] = p21;
           sum[left+1][right] = sum11;
       } else {
           p21 = p[left+1][right];       
           sum11 = sum[left+1][right];
       }
       
       if (p[left][right-1] == -1) {   
           p22 = pick2(A, left, right-1, & sum12, n, p, sum);
           p[left][right-1] = p22;
           sum[left][right-1] = sum12;
       } else {
           p22 = p[left][right-1];       
           sum12 = sum[left][right-1];
       }
       
       int p11 = A[left] + sum11;
       int p12 = sum12 + A[right];
    
       if (p11 > p12) {
           *sum2 = p21;
           return p11;
       } else {
           *sum2 = p22;
           return p12;
      }
    }
    
    
    int pick(int A[], int left, int right, int * sum2) {
      if (left == right) {
           //puts("END 1");
           * sum2 = 0;
           return A[left];
       }
      
       int sum11, sum12;
       int p21 = pick(A, left+1, right, & sum11);
       int p22 = pick(A, left, right-1, & sum12);
    
       int p11 = A[left] + sum11;
       int p12 = sum12 + A[right];
    
       if (p11 > p12) {
           *sum2 = p21;
           return p11;
       } else {
           *sum2 = p22;
           return p12;
      }
    }
    
    int pick_debug(int A[], int left, int right, int * sum2, 
             int step, string s1, string s2) {
       int debug = 0; // 1 + 2
       char n_left[10], n_right[10];
       sprintf(n_left, " %d", A[left]);
       sprintf(n_right, " %d", A[right]);
    
      if (left == right) {
           if (debug & 2) printf("step %d: my score = %d, your score = %d. I pick %d\n", step, A[left], 0, A[left]);
           s1 = n_left + s1;
           if (debug & 1) printf("END: s1 =%s, s2 =%s\n", s1.c_str(), s2.c_str()); // Reached 2^(n-1) times.
           * sum2 = 0;
           return A[left];
       }
      
       int sum11, sum12;
       int p21 = pick_debug(A, left+1, right,   & sum11, step+1, s2, n_left + s1);
       int p22 = pick_debug(A, left, right - 1, & sum12, step+1, s2, n_right + s1);
    
       int p11 = A[left] + sum11;
       int p12 = sum12 + A[right];
    
       if (p11 > p12) {
           if (debug & 2) printf("step %d: my score = %d, your score = %d. I pick %d\n", step, p11, p21, A[left]);
           *sum2 = p21;
           return p11;
       } else {
           if (debug & 2) printf("step %d: my score = %d, your score = %d. I pick %d\n", step, p12, p22, A[right]);
           *sum2 = p22;
           return p12;
      }
    }
    
    
    void dump(vector<int> v) {
        for (int i = 0; i < v.size(); ++ i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    
    void test1(int A[], int n) {
        int sum1, sum2 = 0;
        
        string s1, s2;
        sum1 = pick(A, 0, n-1, &sum2);
        //sum1 = pick_debug(A, 0, n-1, &sum2, 0, s1, s2);
        
        printf("-pick-  sum1 = %d, sum2 = %d\n", sum1, sum2);
    }
    
    void test2(int A[], int n) {
        int sum1, sum2 = 0;
        
        int **p, **sum;
        p = new int*[n]; // (int**) malloc(sizeof(int *) * n);
        sum = new int*[n]; //(int**) malloc(sizeof(int *) * n);
        for (int i = 0; i < n; ++ i) {
            p[i] = new int[n];
            sum[i] = new int[n];
            for (int j = 0; j < n; ++ j) {
                p[i][j] = sum[i][j] = -1;
            }
        }
        sum1 = pick2(A, 0, n-1, &sum2, n, p, sum);
        
        printf("-pick2- sum1 = %d, sum2 = %d\n", sum1, sum2);     
        
        // release dynamically allocated memory.
        for (int i = 0; i < n; ++ i) {
            delete[] p[i];
            delete[] sum[i];
        }
        delete[] p;
        delete[] sum;
    }
};


/*
From: http://leetcode.com/2011/02/coins-in-line.html
This is easier to output the path.

There is another solution which does not rely on computing and storing results of 
Sum{Ai … Aj}, therefore is more efficient in terms of time and space. Let us 
rewind back to the case where you take Ai, and the remaining coins become { Ai+1 … Aj }.
You took Ai from the coins { Ai … Aj }. The opponent will choose either 
Ai+1 or Aj. Which one would he choose?

Let us look one extra step ahead this time by considering the two coins the 
opponent will possibly take, Ai+1 and Aj. If the opponent takes Ai+1, the 
remaining coins are { Ai+2 … Aj }, which our maximum is denoted by P(i+2, j). 
On the other hand, if the opponent takes Aj, our maximum is P(i+1, j-1). 
Since the opponent is as smart as you, he would have chosen the choice that 
yields the minimum amount to you.

Therefore, the maximum amount you can get when you choose Ai is:

P1 = Ai + min { P(i+2, j), P(i+1, j-1) }

Similarly, the maximum amount you can get when you choose Aj is:

P2 = Aj + min { P(i+1, j-1), P(i, j-2) }

Therefore,

P(i, j) = max { P1, P2 }
        = max { Ai + min { P(i+2, j),   P(i+1, j-1) },
                Aj + min { P(i+1, j-1), P(i,   j-2) } }

Although the above recurrence relation could be implemented in few lines of 
code, its complexity is exponential. The reason is that each recursive call 
branches into a total of four separate recursive calls, and it could be n 
levels deep from the very first call). Memoization provides an efficient way 
by avoiding re-computations using intermediate results stored in a table. 
Below is the code which runs in O(n2) time and takes O(n2) space.
 */
const int MAX_N = 100;

class Solution2 {
public:    
    void printMoves(int P[][MAX_N], int A[], int N) {
      int sum1 = 0, sum2 = 0;
      int m = 0, n = N-1;
      bool myTurn = true;
      while (m <= n) {
        int P1 = P[m+1][n]; // If take A[m], opponent can get...
        int P2 = P[m][n-1]; // If take A[n]
        cout << (myTurn ? "I" : "You") << " take coin no. ";
        if (P1 <= P2) {
          cout << m+1 << " (" << A[m] << ")";
          m++;
        } else {
          cout << n+1 << " (" << A[n] << ")";
          n--;
        }
        cout << (myTurn ? ", " : ".\n");
        myTurn = !myTurn;
      }
      cout << "\nThe total amount of money (maximum) I get is " << P[0][N-1] << ".\n";
    }
     
    int maxMoney(int A[], int N) {
      int P[MAX_N][MAX_N] = {0};
      int a, b, c;
      for (int i = 0; i < N; i++) {
        for (int m = 0, n = i; n < N; m++, n++) {
          assert(m < N); assert(n < N);
          a = ((m+2 <= N-1)             ? P[m+2][n] : 0);
          b = ((m+1 <= N-1 && n-1 >= 0) ? P[m+1][n-1] : 0);
          c = ((n-2 >= 0)               ? P[m][n-2] : 0);
          P[m][n] = max(A[m] + min(a,b),
                        A[n] + min(b,c));
        }
      }
      printMoves(P, A, N);
      return P[0][N-1];
    }
};


int main() {
    int A[] = {1,100,5,4,7,10,9,8,23,4,22,1,2,44,22,3,4,22,33,444,22,2,55,7,7};
    //int A[] = {1,100,5,4,7,10};
    //int A[] = {1,100,5,4,7};
    int n = sizeof(A) / sizeof(int);

    Solution s;
    DWORD t0 = GetTickCount();
    s.test1(A, n);
    DWORD t1 = GetTickCount();
    s.test2(A, n);
    DWORD t2 = GetTickCount();
    
    printf("pick() used time = %d, pick2() used time = %d\n", t1 - t0, t2 - t1);
    
    Solution2 s2;
    printf("solution2: %d\n", s2.maxMoney(A, n));
    
    return 0;
}
/*
1,100,5,4,7,10


start from small cases,

1

2 num:

3 num:
1, 100, 5,
100,1,5

A[n] = a[1] + A[2..n]. O(n)
A[n] = a[n-1] + A[1..n-1]

T(n) = f(n) + 2*T(n-1) = O(2^n)

// returns the sum of all the numbers a player gets.
int pick1(int a[], int left, int right, int * sum2) {

  if (left == right) {
     * sum2 = 0;
     return a[left];
   }

   int sum11, int sum12;
   pick1(A, left+1, right, & sum11);
   pick1(A, left, right - 1, & sum12));
   int p1 = a[left] + sum11;
   int p2 = sum12 + a[right];
   if (p1 > p2) {
       *sum2 = sum11;
       return p1;
   } else {
       *sum2 = sum12;
       return p2;
  }
}


*/
