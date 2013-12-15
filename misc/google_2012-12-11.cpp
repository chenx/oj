Please use this Google doc to code during your interview. To make hands free coding a little easier, we recommend that you use a headset or a phone with speaker option.

Best,sdf
Google Staffing

Can you edit this document ?
What phone number should I call ?
(808) 226-3584
Yes. Thanks. I got your cll

100,99,50,7,8,10,5,1,8,3
O(n)

Time complexity: O(...)

100 1 2 3 4 5 6 7 .
int local_min(int a[], int left, int right) {
   if (left > right) return -1;
   if (left == right) return left;

   int mid, L = left, R = right;
   while (L <= R) {
       mid = (L + R) / 2; // (right - left)/2 + left
       // when mid is at the edge
       if (mid == left) {
            if (a[mid] < a[mid+1]) return mid;
       } else if (mid == right) {
            if (a[mid] < a[mid-1]) return mid;
       } else
           if (a[mid] > a[mid-1] && a[mid] < a[mid+1]) return mid;
       }

       if (a[mid] < a[mid+1]) R = mid + 1;
       else L = mid;
       }
   }
}






1,100,5,4,7,10


start from small cases,

1

2 num:

3 num:
1, 100, 5,
100,1,5

A[n] = A[1] + A[2..n]. O(n)
A[n] = A[n-1] + A[1..n-1]

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


