//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 1/21/2013
//

// Number of BST given n nodes:
// Catalan number: C(2n, n) / (n+1) = (2n)!/(n! * (n+1)!).
// http://en.wikipedia.org/wiki/Catalan_number
// This is also the number of full BT (each node has 0 or 2 nodes),
// and is also the number of BT configurations.

// The related question: given n nodes, number of BTs:
// Since there are catalan number of BT configurations, but for BT,
// values can permute, so it's catalan number * n!, i.e.,
// n! * C(2n, n) / (n+1) = (2n)!/(n+1)!.

class Solution {
public:
    // this is DP. Works in O(n) space and O(n^2) time.
    int numTrees(int n) {
        vector<int> v(n+1);
        v[0] = v[1] = 1;
        
        for (int i = 2; i <= n; i ++) {
            v[i] = 0;
            for (int j = 0; j < i; j ++) {
                v[i] += v[j] * v[i - j - 1];
            }
        }
        
        return v[n];
    }
    
    // This works too, but is exponential in performance.
    int numTrees2(int n) {
        if (n <= 1) return 1;
        int sum = 0;
        
        for (int i = 0; i < n; i ++) {
            sum += numTrees(i) * numTrees(n - i - 1);
        }
        
        return sum;
    }
};

/*
Problem:

Given n, how many structurally unique BST's (binary search trees) 
that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */