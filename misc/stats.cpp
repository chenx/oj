// #include <iostream>
#include <string>

using namespace std;

void output(int a[], int len) {
     static int count = 0;
     printf("%d: ", ++ (count));
     for (int j = 0; j < len; j ++) printf("%d ", a[j]); 
     puts("");     
}

// exponential set of elements in in[].
void DoCombine(int in[], int out[], int len, int level, int start) {
     int i;
     for (i = start; i < len; i ++) {
         out[level] = in[i];
         output(out, level + 1);
         
         if (i < len - 1) {
            DoCombine(in, out, len, level + 1, i + 1);      
         }
     }     
}

void testComb() {
    int a[] = {1,2,3,4,5};
    int len = sizeof(a) / sizeof(int);
    int b[len];
    DoCombine(a, b, len, 0, 0);     // len can be 1 to 5.
}


// output combination: C(n, m).
// call by: c_nm(a, a.len, m, 0); a = {0}.
void c_nm(int a[], int n, int m, int start) {
    if (m <= 0 || m > n || n < 0) return;

    for (int i = start; i < n; i ++) {
        a[i] = 1;
        m --;
        if (m > 0) { c_nm(a, n, m, i+1); }
        else { //output(a, n);     
          for (int j = 0; j < n; j ++) { if (a[j] == 1) printf("%d ", j+1); }
          puts("");
        }
        a[i] = 0;
        m ++;
    }
}

void print_array(char out[], int len) {
    for (int i = 0; i < len; ++ i) {
        printf("%c ", out[i]);
    }
    puts("");
}

void comb(char in[], char out[], int min, int max, int pos, int len) {
    if (pos == len) {
      print_array(out, len);
      return; // exist recursion.
    }

    for (int i = min; i < max; i ++) {
        out[pos] = in[i];
        comb(in, out, i + 1, max + 1, pos + 1, len);
    }
}

void testComb2() {
    char in[] = "1234";     
    char out[4];
    int N = 3, M = 2;
    comb(in, out, 0, N - M + 1, 0, M);
}

void testC_NM() {
    //int n=5, m;
    int n, m;
    printf("enter n m: ");
    scanf("%d %d", &n, &m);
    int a[5] = {0};
    //int * a = (int *) malloc(n * sizeof(int));
    //if (! a) exit(0);
    c_nm(a, n, m, 0);
    /*
    int a[5] = {0};
    int len = sizeof(a)/sizeof(int);
    c_nm(a, len, 3, 0);
    */
}

/*
 * To use this function, create an int array s
 * of length n, initialize all entries to 0,
 * then call with permutation(s, 0, m), where m = n.
 * 
 * Actually one can specify m to be any value
 * in the range [1, n], then only the first m
 * entries are used for the permuation.
 *
 * To permute a random array t[], one can
 * first generate int array permutation s[],
 * then output t[s[i]] for i = 0 to n.
 */
void permutation(int s[], int pos, int len) {
  int i, q;

  for (i = 0; i < len; i ++) {
    if(s[i] == 0) {
      q = s[i] = pos + 1; 

      if (q == len) { output(s, len); }
      else { permutation(s, q, len); }

      s[i] = 0;
    }
  }
}


void perm(int in[], int out[], int used[], int len, int level) {
     if (level == len) {
        output(out, len);
        //output(used, len); // all 1s.
        return;
     }
     
     for (int i = 0; i < len; i ++) {
         if (used[i]) continue;
         out[level] = in[i];
         used[i] = 1;
         perm(in, out, used, len, level + 1);
         used[i] = 0;
     }
}

void testPerm() {
    int a[] = {1,2,3,4,5};
    int len = sizeof(a) / sizeof(int);
    int b[len];
    int used[len];
    for (int i = 0; i < len; i ++) used[i] = 0;
    
    puts("method 1");
    perm(a, b, used, 5, 0);     
    
    puts("method 2");
    permutation(used, 0, 5);
//used[0] = 1; used[1] = 1; b[0] = 1; b[1] = 2;
//DoPerm(a, b, used, 5, 2);
}

int fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);    
}

// inverse a[left] to a[right].
void rev(int a[], int left, int right) {
     int tmp;
     for (; left < right; left ++, right --) {
         tmp = a[left];
         a[left] = a[right];       
         a[right] = tmp;
     }
}

// Given x in [1, len!], get the permutation for this sequence number.
// initial call: f(a, a.len, a.len, x);
// @a[]: the input array.
// @len: a.size(). 
// @n: starts as len, ends at 1.
// @x: the number to get permutation for.
// Note: 1) this is tail recursion, can convert to iteration.
//       2) space O(1), time O(n^2) dominated by the shift part.
//          basically to find the permutation, this uses n^2 instead of n!.
void fast_perm(int a[], int len, int n, int x) {
     int debug = 0;
     if (debug) printf("x = %d, n = %d\n", x, n);
     if (x == 1) {
         output(a, len);
         return; // keep a[len-n] to a[len-1] as is.
     }
     int m = fact(n);
     if (x == m) { 
         rev(a, len-n, len-1); 
         output(a, len);
         return;
     } // reverse a[len-n] to a[len-1]
     if (n == len) {
        fast_perm(a, len, n-1, x);
        return;      
     }
     
     int q = x / m;
     int r = x % m;
     if (debug) printf("%d = %d! * %d + %d. ", x, n, q, r);
         
     if (r == 0) { q -= 1, r = m; }
         
     // move a[len-n-1+q] to a[len-n-1], 
     // shift number in middle to right, like insertion sort.
     int left = len - n - 1;
     int y = a[left+q];
     int i;
     for (i = left+q; i > left; i --) a[i] = a[i-1];
     a[i] = y;
     
     fast_perm(a, len, n-1, r);
}

void fast_perm_iteration(int a[], int len, int n, int x) {
     int debug = 0;
     while (1) {
         if (debug) printf("x = %d, n = %d\n", x, n);
         if (x == 1) { // keep a[len-n] to a[len-1] as is.
             output(a, len);
             return; 
         }
         int m = fact(n);
         if (x == m) { // reverse a[len-n] to a[len-1]
             rev(a, len-n, len-1); 
             output(a, len);
             return;
         } 
         if (n == len) {
            n--;
            continue;
         }
         
         int q = x / m;
         int r = x % m; 
         if (debug) printf("%d = %d! * %d + %d. ", x, n, q, r);
             
         if (r == 0) { q -= 1, r = m; }
             
         // move a[len-n-1+q] to a[len-n-1], 
         // shift numbers in between to right, like insertion sort.
         int left = len - n - 1;
         int y = a[left+q];
         int i;
         for (i = left+q; i > left; i --) a[i] = a[i-1];
         a[i] = y;
         
         n --;
         x = r;
     }
}

void testFast_perm() {
    for (int i = 1; i <= 120; i ++) 
    {
      int a[] = {1,2,3,4,5};
      int len = sizeof(a) / sizeof(int);
      //fast_perm(a, len, len, i);
      fast_perm_iteration(a, len, len, i);
    }
}


int main() {
//    testComb();
//    testPerm();
//    testFast_perm();
    puts("testC_NM:");
    testC_NM();
    
    puts("testComb2:");
    testComb2();
    
    //getchar();
    return 0;   
}
