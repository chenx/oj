#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;     
}

void output(int a[], int len) {
    printf("a: ");
    for (int i = 0; i < len; i ++) {
        printf("%d ", a[i]);    
    }     
    puts("");
}

void qsort(int a[], int left, int right) {
    if (left >= right) return;
    int L = left, R = right;
    int p = (L + R) / 2;
    
    while (L <= R) {
        while (a[L] < a[p]) L ++;
        while (a[R] > a[p]) R --;
        if (L < R) swap(a[L ++], a[R --]);
        else L ++;      
    }     
    
    qsort(a, left, R);
    qsort(a, R+1, right);
}

void qs2(int a[], int left, int right, int k) {
    int p, L = left, R = right;
    
    p = (R + L) / 2; // pivot.
    
    while (L <= R) {
        while (a[L] < a[p]) L ++;
        while (a[R] > a[p]) R --;
        if (L < R) swap(a[L ++], a[R --]);
        else L ++;
    }
     output(a, 10);
    
    if (R == k) return;
    else if (R < k) qs2(a, R, right, k - R);
    else qs2(a, left, R, k);
}

/*
// backup.
void qs(int data[], int left, int right, int k) {
  int L = left + 1, R = right;
  int pivot;

  swap ( data[left],  data[(left + right)/2]);
  pivot = data[left];

  // partition 
  while (L <= R) {
    while (data[L] < pivot && L < right) L ++;
    while (pivot < data[R]) R --;
    if (L < R) swap( data[L ++],  data[R --]);
    else L ++;
  }
  swap( data[R],  data[left]);

  // 3 segments: [first, ... upper - 1; upper; upper + 1, ... last]. 
  if (left < R - 1 && k < R) {
    qs(data, left, R - 1, k);
  } else if (R + 1 < right && k > R) {
    qs(data, R + 1, right, k);
  }
}
*/

void qs(int data[], int left, int right, int k) {
  int L = left + 1, R = right;
  int pivot;

  swap(data[left],  data[(left + right)/2]); // or a random entry.
  pivot = data[left];

  while (L <= R) {
    while (data[L] < pivot) L ++; 
    while (pivot < data[R]) R --;
    if (L < R) swap( data[L ++], data[R --]);
    else L ++;
  }
  swap(data[R], data[left]);

  // 3 segments: [left, ... R - 1; R; R + 1, ... right]. 
  if (k < R) { qs(data, left, R - 1, k); }
  else if (k > R) { qs(data, R + 1, right, k); }
}

// http://blog.teamleadnet.com/2012/07/quick-select-algorithm-find-kth-element.html
int selectKth(int arr[], int len, int k) {
    if (len <= k) return -1;
 
    int from = 0, to = len - 1;
     
     // if from == to we reached the kth element
    while (from < to) {
      int r = from, w = to;
      int mid = arr[(r + w) / 2];
     
      // stop if the reader and writer meets
      while (r < w) { 
       if (arr[r] >= mid) { // put the large values at the end
        swap(arr[w], arr[r]);
        w--;
       } else { // the value is smaller than the pivot, skip
        r++;
       }
      }
     
      // if we stepped up (r++) we need to step one down
      if (arr[r] > mid) r--;
     
      // the r pointer is on the end of the first k elements
      if (k <= r) to = r;
      else from = r + 1;
    }
 
    return arr[k];
}

void test_qs() {
    int k;
    int len = 10;
    for (k = 0; k < len; k ++) {
        int a[] = {8,6,10,4,5,6,7,8,9,3};
        //int len = sizeof(a) / sizeof(int);
        qs(a, 0, len - 1, k);
        //selectKth(a, len, k);
        printf("%d-th element: %d\n", k, a[k]);
        output(a, len); 
    }
}

int main() {
    test_qs();
    //int a[] = {8,6,10,4,5,16,7,18,9,3};
    //qsort(a, 0, 9); output(a, 10);
    return 0;   
}
