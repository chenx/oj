public class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<List<String>>();
        if (n <= 0) return ans;
        
        int[] v = new int[n];
        Arrays.fill(v, 0);

        solve(ans, v, 0, n);
        return ans;
    }
    
    private void solve(List<List<String>> ans, int[] v, int level, int n) {
        if (level == n) {
            List<String> u = new ArrayList<String>();
            for (int i = 0; i < n; ++ i) {
                String s = getStr(v[i] - 1, '.') + "Q" + getStr(n - v[i], '.');
                u.add(s);
            }
            ans.add(u);
            return;
        }
        
        for (int i = 0; i < n; ++ i) {
            v[level] = i + 1;
            if (! conflict(v, level)) solve(ans, v, level + 1, n);
        }
    }
    
    private String getStr(int n, char c) {
        char[] arr = new char[n];
        Arrays.fill(arr, c);
        return new String(arr);
    }
    
    private boolean conflict(int[] v, int level) {
        for (int i = 0; i < level; ++ i) {
            if (v[i] == v[level] || Math.abs(level - i) == Math.abs(v[level] - v[i])) return true;
        }
        return false;
    }
}


/**
N-Queens
Difficulty: Hard

The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
 */
