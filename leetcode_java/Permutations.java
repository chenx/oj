// Recursive version.
public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        int n = nums.length;

        int A[] = new int[n];
        for (int i = 0; i < n; ++ i) A[i] = 0;
        
        perm(list, nums, A, n, 0);
        return list;
    }
    
    private void perm(List<List<Integer>> list, int[] nums, int[] A, int n, int pos) {
        if (pos == n) {
            List<Integer> ls = new ArrayList<Integer>();
            for (int i = 0; i < n; ++ i) ls.add(nums[A[i] - 1]);
            list.add(ls);
            return;
        }
        
        for (int i = 0; i < n; ++ i) {
            if (A[i] == 0) {
                A[i] = pos + 1;
                perm(list, nums, A, n, pos + 1);
                A[i] = 0;
            }
        }
    }
}

// This works too. Iterative version.
// Modified from: https://leetcode.com/discuss/59888/my-concise-c-solution-without-using-recursion
public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        result.add(new ArrayList<Integer>());

        for(int i = 0, n = nums.length; i < n; ++ i){
            int size = result.size();
            int m = result.get(0).size();
            for(int j = 0; j < size; ++ j){
                result.get(j).add(nums[i]);
                for(int k = 0; k < m; ++ k){
                    ArrayList<Integer> v = clone( result.get(j) );
                    int tmp = v.get(k); v.set(k, v.get(m)); v.set(m, tmp); // swap(v[k], v[m])
                    result.add(v);
                }
            }     
        }
        return result;
    }
    
    private ArrayList<Integer> clone(List<Integer> v) {
        ArrayList<Integer> u = new ArrayList<Integer>();
        //Collections.copy(u, v); // copy, original. this not work here.
        for (int i = 0, n = v.size(); i < n; ++ i) u.add(v.get(i));
        return u;
    }
}

/**
Permutations
Difficulty: Medium

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
 */
