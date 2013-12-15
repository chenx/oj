/*
 * @Author: Xin Chen
 * @Created on: 12/20/2013
 * @Last modified: 4/6/2013
 */
#include <iostream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int * a = new int[n];
        for (int i = 0; i < n; i ++) a[i] = i + 1;
        return fast_perm_iteration2(a, n, k);
//        return fast_perm_iteration(a, n, n, k);
    }
    
    string output(int a[], int len) {
        string s = "";
        for (int i = 0; i < len; i ++) s += a[i] + '0';
        return s;
    }
    
    int fact(int n) {
        if (n <= 1) return 1;
        return n * fact(n - 1);    
    }   
    
    // Version 1. This works, but code is more ugly. Figured out on 12/20/2013.
    string fast_perm_iteration(int a[], int len, int n, int x) {
         //int debug = 0;
         while (1) {
             //if (debug) printf("x = %d, n = %d\n", x, n);
             if (x == 1) { // keep a[len-n] to a[len-1] as is.
                 return output(a, len);
             }
             int m = fact(n);
             if (x == m) { // reverse a[len-n] to a[len-1]
                 rev(a, len-n, len-1); 
                 return output(a, len);
             } 
             if (n == len) {
                n--;
                continue;
             }
             
             int q = x / m;
             int r = x % m; 
             //if (debug) printf("%d = %d! * %d + %d. ", x, n, q, r);
                 
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
    
    void rev(int a[], int left, int right) {
         int tmp;
         for (; left < right; left ++, right --) {
             tmp = a[left];
             a[left] = a[right];       
             a[right] = tmp;
         }
    }
    
    // Version 2, works. Code is better! Figured out on 1/23/2013.
    // O(n^2).
    string fast_perm_iteration2(int a[], int n, int k) {
        int F[n+1];
        F[0] = 1;
        for (int i = 1; i <= n; ++ i) F[i] = i * F[i-1]; // get factorial sequence up to n.
        
        int len = n, pos = 0;
        while (1) {
            if (k == 1) return output(a, len); // first permuation of a[pos..len-1].
            if (k == F[n]) {                   // last permutation of a[pos..len-1].
                rev(a, pos, len-1);
                return output(a, len);
            }
            
            int i = pos + (k-1)/F[n-1];
            // move a[i] to a[pos], shift a[pos..i-1] right.
            int tmp = a[i];
            for (int j = i; j > pos; -- j) a[j] = a[j-1];
            a[pos] = tmp; // or a[pos] = tmp;
            
            // update k for the next digit.
            k = (k-1) % F[n-1] + 1;
            -- n, ++ pos;
        }
    }
    
};


//
// This works too. Modified from second method above.
//
class Solution2 {
public:
    string getPermutation(int n, int k) {
        int F[1+n];
        F[0] = 1;
        for (int i = 1; i <= n; ++ i) { F[i] = i * F[i-1]; }
        
        int a[n];
        for (int i = 0; i < n; ++ i) { a[i] = i+1; }
        
        int pos = 0, m = n; // pos: index in a[]. m: current n.
        while (1) {
            if (k == 1) { break; }
            if (k == F[m]) {
                reverse(a, pos, n-1);
                break;
            }
            
            int i = pos + (k-1) / F[m-1]; // index of current digit.
            
            int tmp = a[i]; // move a[i] to a[pos], shift a[pos,..,i-1] right.
            for (int j = i; j > pos; -- j) a[j] = a[j-1];
            a[pos] = tmp;
            
            k = (k-1) % F[m-1] + 1; // update pos, m, k
            -- m;
            ++ pos;
        }

        string s = "";
        for (int i = 0; i < n; ++ i) s += (a[i] + '0');
        return s;
    }
    
    void reverse(int A[], int L, int R) {
        while (L < R) {
            swap(A[L ++], A[R --]);
        }
    }    
};


// This works too.
class Solution3 {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int F[n+1];
        F[0] = 1;
        for (int i = 1; i <= n; ++ i) F[i] = i * F[i-1];
        
        vector<int> a(n);
        for (int i = 0; i < n; ++ i) a[i] = i+1;
        
        int pos = 0;
        while (1) {
            if (k == 1) { return makeStr(a); }
            if (k == F[n]) { reverse(a.begin() + pos, a.end()); return makeStr(a); }
            
            int i = pos + (k-1) / F[n-1]; // index of first digit
            // move a[i] to a[pos].
            int tmp = a[i];
            for (int j = i-1; j >= pos; -- j) a[j+1] = a[j];
            a[pos] = tmp;
            
            k = (k-1) % F[n-1] + 1;
            ++ pos;
            -- n;
        }
    }
    
    string makeStr(vector<int> &a) {
        string s = "";
        for (int i = 0; i < a.size(); ++ i) {
            s += a[i] + '0';
        }
        return s;
    }
};


int main() {
    Solution s;
    cout << s.getPermutation(3, 2) << endl;
    return 0;
}


/*
Problem:

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

 */
