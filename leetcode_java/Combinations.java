// Recursive version.
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

// This works too. Iterative version.
// From: https://leetcode.com/discuss/67405/java-my-iterative-13ms-and-recursive-7ms-solutions
public class Solution2 {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        List<Integer> kind = new ArrayList<Integer>();
        int i = 1;
        while(i<=n || kind.size()!=0){
            if(kind.size()==k){
                list.add(new ArrayList(kind));
            }
            if(i>n||kind.size()==k){
                i = kind.get(kind.size()-1)+1;
                kind.remove(kind.size()-1);
            }
            else{
                kind.add(i);
                i++;
            }
        }
        return list;
    }
}

// This works too. Another iterative version.
// From: https://leetcode.com/discuss/63109/short-iterative-c-answer-8ms
public class Solution3 {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        int[] p = new int[n];
        for (int i = 0; i < n; ++ i) p[i] = 0;
        
        int i = 0;
        while (i >= 0) {
            p[i] ++;
            if (p[i] > n) -- i;
            else if (i == k - 1) { // note Arrays.asList(int []) won't work here.
                List<Integer> q = new ArrayList<Integer>();
                for (int j = 0; j < k; ++ j) q.add(p[j]);
                result.add(q);
            }
            else {
                ++ i;
                p[i] = p[i - 1];
            }
        }
        return result;      
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
