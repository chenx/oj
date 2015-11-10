public class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        
        int[] A = new int[n];
        for (int i = 0; i < n; ++ i) A[i] = 0;
        comb(list, A, n, k, 0);
        return list;
    }
    
    private void comb(List<List<Integer>> list, int[] A, int n, int m, int pos) {
        if(m == 0) {
            List<Integer> ls = new ArrayList<Integer>();
            for (int i = 0; i < n; ++ i) {
                if (A[i] == 1) ls.add(i+1);
            }
            list.add(ls);
            return;
        }
        
        for (int i = pos; i < n; ++ i) {
            A[i] = 1;
            comb(list, A, n, m - 1, i + 1);
            A[i] = 0;
        }
    }
}

/**
Combinations
Difficulty: Medium

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

 */
