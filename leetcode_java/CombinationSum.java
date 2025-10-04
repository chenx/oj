class Solution2 {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<List<Integer>>> ans = new ArrayList<>();
        Arrays.sort(candidates);
        
        for (int i = 1; i <= target; ++ i) {
            List<List<Integer>> row = new ArrayList<>();
            for (int j = 0; j < candidates.length; ++ j) {
                if (i < candidates[j]) {
                    break;
                } else if (i == candidates[j]) {
                    row.add(new ArrayList<Integer>(Arrays.asList(i)));
                    break;
                } else {
                    List<List<Integer>> v = ans.get(i - candidates[j] - 1);
                    for (int k = 0; k < v.size(); ++ k) {
                        int size = v.get(k).size();
                        if (candidates[j] >= v.get(k).get(size - 1)) {  // need this!
                            List<Integer> copy =  new ArrayList<>(v.get(k)); // copy
                            copy.add(candidates[j]);
                            row.add(copy);
                        }
                    }
                }
            }
            ans.add(row);
        }
        return ans.get(target - 1);
    }
}

// This works.
public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<List<Integer>>> ans = new ArrayList<List<List<Integer>>>();
        
        Arrays.sort(candidates);
        for (int i = 1; i <= target; ++ i) {
            List<List<Integer>> cur = new ArrayList<List<Integer>>();
            for (int j = 0; j < candidates.length; ++ j) {
                if (i == candidates[j]) {
                    List<Integer> u = new ArrayList<Integer>();
                    u.add(i);
                    cur.add(u);
                }
                else if (i > candidates[j]) {
                    int v = i - candidates[j] - 1; // be careful of "-1" at the end.
                    for (int k = 0; k < ans.get(v).size(); ++ k) {
                        List<Integer> u = ans.get(v).get(k);
                        if (candidates[j] >= u.get(u.size() - 1)) {
                            //List w = new ArrayList<Integer>();
                            //w = (List) ((ArrayList<Integer>) u).clone(); // this works.
                            List w = ((List) ( (ArrayList<Integer>) u).clone());

                            w.add(candidates[j]);
                            cur.add(w);
                        }
                    }
                }
            }
            ans.add(cur);
        }
        
        return ans.get(ans.size() - 1);
    }
}

/**
Combination Sum
Total Accepted: 65186 Total Submissions: 227878 Difficulty: Medium

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3] 
 */
