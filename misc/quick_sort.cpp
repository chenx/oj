void quicksort(int A[], int left, int right) {
   if (left >= right) return;

   swap(A[left], A[left + (right - left) / 2]);
   int pivot = A[left];
   
   int L = left + 1, R = right;
   while (L <= R) {
       while (L <= R && A[L] < pivot) ++ L;
       while (L <= R && A[R] > pivot) -- R;
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
