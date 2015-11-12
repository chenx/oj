public class Solution {
    public int numTrees(int n) {
        if (n <= 1) return 1;
        
        int[] s = new int[n+1];
        s[0] = s[1] = 1;
        
        for (int i = 2; i <= n; ++ i) {
            s[i] = 0;
            for (int j = 0; j < i; ++ j) {
                s[i] += s[j] * s[i - 1 - j];
            }
        }
        
        return s[n];
    }
}

/**
Unique Binary Search Trees
Difficulty: Medium

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */
