public class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int n = nums.length;
        if (n == 0) return ans;

        // count elements that are unique and duplicated.
        ArrayList<Integer> uniq = new ArrayList<Integer>();
        ArrayList<Integer> dupl = new ArrayList<Integer>();
        ArrayList<Integer> dupl_ct = new ArrayList<Integer>();
        
        Arrays.sort(nums);
        int v = nums[0];
        int ct = 1;
        for (int i = 1; i < n; ++ i) {
            if (nums[i] == v) ++ ct;
            else {
                addCount(v, ct, uniq, dupl, dupl_ct);
                
                v = nums[i];
                ct = 1;
            }
        }
        addCount(v, ct, uniq, dupl, dupl_ct);
        
        // Get subsets for unique elements.
        int[] arr_uniq = new int[uniq.size()];
        for (int i = 0, len = uniq.size(); i < len; ++ i) arr_uniq[i] = uniq.get(i);
        ans = subsets(arr_uniq);
        
        // Add duplicated elements to obtain all subsets.
        for (int i = 0, len = dupl.size(); i < len; ++ i) {
            addDupl(ans, dupl.get(i), dupl_ct.get(i));
        }
        
        return ans;
    }
    
    // Add elements to uniq or dupl lists, and save count if dupl.
    private void addCount(int v, int ct, ArrayList<Integer> uniq, 
                     ArrayList<Integer> dupl, ArrayList<Integer> dupl_ct) {
        if (ct == 1) {
            uniq.add(v);
        }
        else {
            dupl.add(v);
            dupl_ct.add(ct);
        }
    }
    
    // Add duplicated elements.
    private void addDupl(List<List<Integer>> ans, int v, int ct) {
        for (int i = 0, len = ans.size(); i < len; ++ i) {
            for (int j = 1; j <= ct; ++ j) {
                List<Integer> row = new ArrayList<Integer>(ans.get(i));
                for (int k = 0; k < j; ++ k) {
                    row.add(v);
                    Collections.sort(row);
                }
                ans.add(row);
            }
        }
    }
    
    // Return subsets list for unique elements.
    private List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        int n = nums.length, len = (1 << n);
        Arrays.sort(nums);
        
        for (int i = 0; i < len; ++ i) {
            List<Integer> v = new ArrayList<Integer>();
            for (int j = 0; j < n; ++ j) {
                if ( (i & (1 << j)) != 0) {
                    v.add(nums[j]);
                }
            }
            ans.add(v);
        }
        
        return ans;
    }    
}


/**
Subsets II
Difficulty: Medium

Given a collection of integers that might contain duplicates, nums, 
return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

 */
