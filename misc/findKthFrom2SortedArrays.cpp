#include <iostream>
using namespace std;

// O(lg(m+n))
// Assume: K in [1, ..., m+n].
int findKth(int A[], int m, int B[], int n, int k) {
    //printf("m=%d, n=%d, k=%d\n", m, n, k);
    if (m > n) return findKth(B, n, A, m, k);
    if (m == 0) return B[k-1];
    if (k == 1) return min(A[0], B[0]);
    
    int pa = min(k/2, m);
    int pb = k - pa;
    
    if (A[pa - 1] < B[pb - 1]) {
        return findKth(A + pa, m - pa, B, n, k - pa);
    } else {
        return findKth(A, m, B + pb, n - pb, k - pb);
    }
}


// This is from http://leetcode.com/2011/01/find-k-th-smallest-element-in-union-of.html
// This claims to be O(lg m + lg n). Is this true or should be O(lg(m+n))?
// This works, but more complicated than findKth. 
// This also requires A and B have no duplicate elements.
// So the findKth() method is better.
int findKthSmallest(int A[], int m, int B[], int n, int k) {
  assert(m >= 0); assert(n >= 0); assert(k > 0); assert(k <= m+n);
 
  int i = (int)((double)m / (m+n) * (k-1));
  int j = (k-1) - i;
 
  assert(i >= 0); assert(j >= 0); assert(i <= m); assert(j <= n);
  // invariant: i + j = k-1
  // Note: A[-1] = -INF and A[m] = +INF to maintain invariant
  int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);
  int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);
  int Ai   = ((i == m) ? INT_MAX : A[i]);
  int Bj   = ((j == n) ? INT_MAX : B[j]);
 
  if (Bj_1 < Ai && Ai < Bj)
    return Ai;
  else if (Ai_1 < Bj && Bj < Ai)
    return Bj;
 
  assert((Ai > Bj && Ai_1 > Bj) ||
         (Ai < Bj && Ai < Bj_1));
 
  // if none of the cases above, then it is either:
  if (Ai < Bj)
    // exclude Ai and below portion
    // exclude Bj and above portion
    return findKthSmallest(A+i+1, m-i-1, B, j, k-i-1);
  else /* Bj < Ai */
    // exclude Ai and above portion
    // exclude Bj and below portion
    return findKthSmallest(A, i, B+j+1, n-j-1, k-j-1);
}


int main() {
    int A[] = {0};
    int m = sizeof(A)/sizeof(int);
    int B[] = {0,1};
    int n = sizeof(B)/sizeof(int);

    for (int k = 1; k <= m+n; ++ k) {
      cout << "k = " << k << ", findKth = " << findKth(A, m, B, n, k) << endl;
      //cout << "k = " << k << ", findKthSmallest = " << findKthSmallest(A, m, B, n, k) << endl;
    }
    
    return 0;
}
