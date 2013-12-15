#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swap2(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// use swap pivot.
void quicksort(int A[], int left, int right) {
   if (left >= right) return;

   swap(A[left], A[left + (right - left) / 2]);
   int pivot = A[left];
   
   int L = left + 1, R = right;
   while (L <= R) {
       while (A[L] < pivot) ++ L;
       while (A[R] > pivot) -- R;
       if (L < R) {
           swap(A[L ++], A[R --]);
           //swap2(&A[L ++], &A[R --]); // This works too.
       } else {
           ++ L;
       }
   } // end of while
   
   swap(A[left], A[R]); // Note: swap with A[R]!
   
   quicksort(A, left, R - 1);
   quicksort(A, R + 1, right);
}


// This seems to work correctly too, but not as good.
void quicksort2(int A[], int left, int right) {
   if (left >= right) return;
   int pivot = A[left + (right - left) / 2];

   int L = left, R = right;
   while (L <= R) {
       while (A[L] < pivot) ++ L;
       while (A[R] > pivot) -- R;
       if (L < R) {
           swap (A[L ++], A[R --]);
       } else {
           ++ L;
       }
   } // end of while

   quicksort(A, left, R);
   quicksort(A, R + 1, right);
}

void dump(int A[], int n) {
    for (int i = 0; i < n; ++ i) {
        printf("%d ", A[i]);
    }
    puts("");
}

// Assumption: for the first call, left = 0, right = A.len - 1, k is valid.
void quickselect(int A[], int left, int right, int k) {
    if (left >= right) return;
    
    swap(A[left + (right - left) / 2], A[left]);
    int pivot = A[left];
    
    int L = left + 1, R = right;
    while (L <= R) {
        while (A[L] < pivot) ++ L;
        while (A[R] > pivot) -- R;
        if (L < R) swap(A[L ++], A[R --]);
        else ++ L;
    }
    swap(A[left], A[R]); // NOTE: swap with A[R], not A[p].
    
    if (k > R) quickselect(A, R + 1, right, k);
    else if (k < R) quickselect(A, left, R - 1, k);
}

/*
// This does not work. Don't know why.
// Seems for quick select, must move pivot aside.
void quickselect2(int A[], int left, int right, int k) {
    if (left >= right) return;
    
//    int p = left + (right - left) / 2;
    int pivot = A[left + (right - left) / 2];
//swap( A[(left+right)/2], A[left] );    
    
    int L = left, R = right;
    while (L <= R) {
        while (A[L] < pivot) ++ L;
        while (A[R] > pivot) -- R;
        if (L < R) swap(A[L ++], A[R --]);
        else ++ L;
    }
//swap(A[left], A[R]);

    dump(A, 7);
    
    if (R < k) quickselect2(A, R + 1, right, k);
    else if (R > k) quickselect2(A, left, R, k);
}
*/

void test_quickselect(int A[], int n) {
    int k = 0;
    quickselect(A, 0, n - 1, k); cout << A[k] << endl;
    dump(A, n);
    //quickselect2(A, 0, n-1, k); cout << A[k] << endl;
}


void print_array(char * A, int min, int max) {
  int i;
  printf(":: ");
  for (i = min; i < max; i ++) {
    printf("%c ", A[i]);
  }
  puts("");
}

// Combination. Call with: comb(in, out, 0, N-M+1, 0, M);
void comb(char in[], char out[], int min, int max, int pos, int len) {
    if (pos == len) {
      print_array(out, 0, len);
      return; // exist recursion.
    }

    for (int i = min; i < max; i ++) {
        out[pos] = in[i];
        comb(in, out, i + 1, max + 1, pos + 1, len);
    }
}

void mergesort(int A[], int left, int right, int B[]) {
     if (left >= right) return;
     
     int mid = left  + (right - left)/2;
     mergesort(A, left, mid, B);
     mergesort(B, mid + 1, right, B);
     
     int i, j, k;
     i = k = left;
     j = mid + 1;
     
     while (i <= mid && j <= right) {
         if (A[i] < A[j]) B[k ++] = A[i ++];
         else B[k ++] = A[j ++];
     }
     while (i <= mid) B[k ++] = A[i ++];
     while (j <= right) B[k ++] = A[j ++];
     
     for (int i = left; i <= right; ++ i) A[i] = B[i];
}

void permutation(int s[], int pos, int len) {
  if (pos == len) {
    dump(s, len);
    return;
  }

  for (int i = 0; i < len; i ++) {
    if(s[i] == 0) {
      s[i] = pos + 1; 
      permutation(s, pos + 1, len); 
      s[i] = 0;
    }
  }
}

int main() {
    int A[] = {3,2,1,7,5,4,6};//,8,9};
    int n = sizeof(A) / sizeof(int);
    int B[n];
    
    //test_quickselect(A, n); return 0;
    
    dump(A, n);
    mergesort(A, 0, n-1, B);
    //quicksort(A, 0, n-1);
    //quicksort2(A, 0, n-1);
    dump(A, n);
    
    const int N = 5, M = 3;
    char in[N] = {'1', '2', '3', '4', '5'};
    char out[N];
    comb(in, out, 0, N-M+1, 0, M);
    
    int C[N] = {0};
    permutation(C, 0, N);
    
    return 0;
}
