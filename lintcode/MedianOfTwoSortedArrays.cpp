class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        int n1 = A.size(), n2 = B.size(), total = n1 + n2;
        if (total & 1) 
            return getKth(A, 0, B, 0, total / 2 + 1);
        else 
            return 0.5 * (getKth(A, 0, B, 0, total / 2) + getKth(A, 0, B, 0, total / 2 + 1));
    }
    
    double getKth(vector<int> &A, int offset1, vector<int> &B, int offset2, int k) {
        int m = A.size() - offset1, n = B.size() - offset2;
        if (m > n) return getKth(B, offset2, A, offset1, k);
        if (m == 0) return B[offset2 + k - 1];
        if (k == 1) return min(A[offset1], B[offset2]);
        
        int pa = min(k/2, m), pb = k - pa;
        
        if (A[offset1 + pa - 1] < B[offset2 + pb - 1]) {
            return getKth(A, offset1 + pa, B, offset2, k - pa);
        }
        else {
            return getKth(A, offset1, B, offset2 + pb, k - pb);
        }
    }
};
