//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 1/8/2012
// @Last modified: 1/9/2012
//

// This works too. more clean.
class Solution3 {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        
        int i, j;
        for (i = n-2; i >= 0 && num[i] >= num[i+1]; -- i) {} // find first num[i] < num[i+1].
        
        if (i == -1) {
            reverse(num.begin(), num.end());
            return;
        }
        
        for (j = n-1; num[i] >= num[j]; -- j) {} // find first elem from right larger than num[i].
        swap(num[i], num[j]);
        
        reverse(num.begin() + i + 1, num.end());
    }
};

// Optimized from Solution2.
// reference: http://blog.csdn.net/sunjilong/article/details/8258254
class Solution {
public:
    // O(n) by using reverse (instead of sort)
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        if (n <= 1) return;
        
        int i, j;
        for (i = n - 2; i >= 0 && num[i] >= num[i + 1]; -- i) ; 
        
        if (i < 0) { // last permutation already. Go to the first permutation.
            reverse(num.begin(), num.end()); // or sort(num.begin(), num.end());
        } 
        else {
            // get the minimal number x > num[pos] from rhs of x.
            // since the rhs of x is sorted DESC, the first x > num[pos] will do.
            // Note: '<=' is needed when duplicated elements exist, '<' not enough.
            for (j = n - 1; num[j] <= num[i]; -- j) ; 
            swap(num[i], num[j]);
            
            // sort rhs of pos in INC order.
            reverse(num.begin() + i + 1, num.end());     // or sort.
        }
    }
};

//
// 1) Find the largest position i such that a_{i} < a_{i+1}
// 2) Replace a_i with the smallest value a_{i+1}...a_{n} that is bigger than the value of a_{i}
// 3) Reassign the values from the remaining elements a_{i+1}...a_{n} (including the original a_{i}) 
// in lexicographically increasing order.
// references: 
// [1] http://www.de-brauwer.be/wiki/wikka.php?wakka=Permutations
// [2] http://marknelson.us/2002/03/01/next-permutation/
// 
class Solution2 {
public:
    // O(n log(n)) for sorting used.
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        if (n <= 1) return;
        
        int i;
        for (i = n - 2; i >= 0; -- i) {
            if (num[i] < num[i + 1]) break;
        }
        
        if (i < 0) { // last permutation already. Go to the first permutation.
            sort(num.begin(), num.end());
            return; 
        } 
        
        int pos = i;
        
        // get the minimal number x > num[pos] from rhs of x.
        int p = pos + 1;
        for (i = n - 1; i > pos; -- i) {
            if (num[i] > num[pos] && num[i] < num[p]) p = i;
        }
        
        // swap num[p] and num[pos];
        int tmp = num[pos];
        num[pos] = num[p];
        num[p] = tmp;
        
        // sort rhs of pos in INC order.
        sort(num.begin() + pos + 1, num.end());
    }
};

/*
Problem:

 Implement next permutation, which rearranges numbers into the 
 lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as 
the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and 
its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1        
 */

