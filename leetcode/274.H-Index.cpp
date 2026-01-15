// From: https://leetcode.com/problems/h-index/editorial/
// Counting sort
// Time: O(n)
// Space: O(n)
class Solution2 {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> papers(n+1, 0);
        // counting papers for each citation number
        for (int c: citations) papers[min(n, c)] ++;

        // finding the h-index. i - total number of papers; k - number of citations.
        int k = n;
        for (int s = papers[n]; k > s; s += papers[k]) -- k;
        return k;
    }
};


// sort first.
// Time: O(nlogn)
// Space: O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if (len == 0) return 0;
        
        sort(citations.begin(), citations.end());
        for (int i = 0; i < len; ++ i) {
            if (citations[i] >= len - i) return len - i;
        }
        
        return 0;
    }
};

/**
H-Index
Difficulty: Medium

Given an array of citations (each citation is a non-negative integer) 
of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has 
index h if h of his/her N papers have at least h citations each, and 
the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the 
researcher has 5 papers in total and each of them had received 
3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 
papers with at least 3 citations each and the remaining two with 
no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one 
is taken as the h-index.

Hint:

    An easy approach is to sort the array first.
    What are the possible values of h-index?
    A faster approach is to use extra space.

 */
