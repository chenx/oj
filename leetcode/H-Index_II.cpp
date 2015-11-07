class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if (len == 0) return 0;
        
        int L = 0, R = len - 1, hIndex = 0, M;
        while (L <= R) {
            M = L + (R - L)/2;
            if (citations[M] >= len - M) {
                R = M - 1;
                hIndex = len - M;
            }
            else {
                L = M + 1;
            }
        }
        
        return hIndex;
    }
};


/**
H-Index II
Difficulty: Medium

Follow up for H-Index: What if the citations array is sorted in ascending order? 
Could you optimize your algorithm?

Hint:

    Expected runtime complexity is in O(log n) and the input is sorted.

 */
