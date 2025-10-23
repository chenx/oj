class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;

        int[] DP = new int[n];
        DP[n-1] = 0;

        for (int i = n-2; i >= 0; -- i) {
            if (i + nums[i] >= n-1) DP[i] = 1;
            else {
                for (int j = nums[i]; j >= 0; -- j) {
                    if (i + j < n && DP[i+j] > 0) {
                        if (DP[i] == 0 || DP[i] > 1 + DP[i + j]) {
                            DP[i] = 1 + DP[i + j];
                        }
                    }
                }
            }
        }
        return DP[0];
    }
}
