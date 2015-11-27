// This works. 
// The Manancher-like solution scan the array from left to right (for i loop) 
// and only check those sub-strings centered at s[i]; once a non-palindrome 
// string is found, it will stop and move to i+1. Same as the DP solution, 
// minCUTS[i] is used to save the minimum cuts for s[0:i-1]. For each i, we 
// do two for loops (for j loop) to check if the substrings s[i-j .. i+j] 
// (odd-length substring) and s[i-j-1.. i+j] (even-length substring) are palindrome.
// By increasing j from 0, we can find all the palindrome sub-strings centered 
// at i and update minCUTS accordingly. Once we meet one non-palindrome sub-string, 
// we stop for-j loop since we know there no further palindrome substring centered 
// at i. This helps us avoid unnecessary palindrome substring checks, as we did 
// in the DP algorithm. Therefore, this version is faster. 
// From: https://leetcode.com/discuss/47140/two-versions-given-one-28ms-one-manancher-like-algorithm-10
public class Solution {
    public int minCut(String s) {
        int N = s.length();
        if(N<=1) return 0;

        int i, j;
        int[] minCUTS = new int[N+1];
        for(i=0; i<=N; ++i) minCUTS[i] = i-1;

        for(i=1;i<N;i++)
        {
            for(j=0;(i-j)>=0 && (i+j)<N && s.charAt(i-j) == s.charAt(i+j); ++j) // odd-length substrings 
                minCUTS[i+j+1] = Math.min(minCUTS[i+j+1], 1 + minCUTS[i-j]);

            for(j=0;(i-j-1)>=0 && (i+j)<N && s.charAt(i-j-1) == s.charAt(i+j); ++j) // even-length substrings
                minCUTS[i+j+1] = Math.min(minCUTS[i+j+1], 1 + minCUTS[i-j-1]);
        }
        return minCUTS[N];        
    }
}

/**
Palindrome Partitioning II
Difficulty: Hard

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 
 */
