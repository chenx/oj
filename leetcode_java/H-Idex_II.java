public class Solution {
    public int hIndex(int[] citations) {
        if (citations.length == 0) return 0;
        
        int L = 0, R = citations.length - 1, h = 0, M;
        while (L <= R) {
            M = L + (R - L)/2;
            if (citations[M] >= citations.length - M) {
                h = citations.length - M; // !
                R = M - 1;
            }
            else {
                L = M + 1;
            }
        }
        
        return h;
    }
}


/**
H-Index II
Difficulty: Medium

Follow up for H-Index: What if the citations array is sorted in ascending order? 
Could you optimize your algorithm?

Hint:

    Expected runtime complexity is in O(log n) and the input is sorted.

 */
