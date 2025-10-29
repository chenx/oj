class Solution {
    private int[] prefixSum;
    private int total;
    
    public Solution(int[] w) {
        int n = w.length;
        if (n == 0) return;

        prefixSum = new int[w.length];
        prefixSum[0] = w[0];
        for (int i = 1; i < n; ++ i) {
            prefixSum[i] = w[i] + prefixSum[i-1];
        }
        total = prefixSum[n-1];
    }

    public int pickIndex() {
        double v = Math.random() * total;
        for (int i = 0; i < prefixSum.length; ++ i) {
            if (prefixSum[i] > v) return i; //  >= also works.
        }
        return prefixSum.length - 1;
    }

    public int pickIndex2() {
        Random random = new Random();
        // int min = 0;
        // double v = random.nextInt(total - min + 1) + min;
        double v = random.nextInt(total);
        for (int i = 0; i < prefixSum.length; ++ i) {
            if (prefixSum[i] > v) return i; //  >= also works.
        }
        return prefixSum.length - 1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */

/**
528. Random Pick with Weight
Medium

You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] 
(inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the 
probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
 */
