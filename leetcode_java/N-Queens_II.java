public class Solution {
    private int ans;
    
    public int totalNQueens(int n) {
        if (n <= 0) return 0;
        ans = 0;

        int[] v = new int[n];
        Arrays.fill(v, 0);

        solve(v, 0, n);
        return ans;
    }
    
    private void solve(int[] v, int level, int n) {
        if (level == n) {
            ++ ans;
            return;
        }
        
        for (int i = 0; i < n; ++ i) {
            v[level] = i + 1;
            if (! conflict(v, level)) solve(v, level + 1, n);
        }
    }
    
    private boolean conflict(int[] v, int level) {
        for (int i = 0; i < level; ++ i) {
            if (v[i] == v[level] || level - i == Math.abs(v[level] - v[i])) return true;
        }
        return false;        
    }
}


/**
N-Queens II
Difficulty: Hard

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total 
number of distinct solutions.
 */
