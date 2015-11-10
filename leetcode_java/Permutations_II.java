public class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        if (nums.length == 0) return list;
        
        Arrays.sort(nums);
        
        do {
            list.add(arrayToList(nums));
        } while (nextPermutation(nums));
        
        return list;
    }
    
    private List<Integer> arrayToList(int[] A) {
        List<Integer> lst = new ArrayList<Integer>();
        for (int i = 0, n = A.length; i < n; ++ i) lst.add(A[i]);
        return lst;
    }
    
    private boolean nextPermutation(int[] nums) { // e.g. 14322 -> 24321 -> 21234
        int n = nums.length, i, j;
        
        for (i = n - 2; i >= 0 && nums[i] >= nums[i+1]; -- i) {}
        if (i < 0) {
            //reverse(nums, 0, n-1);
            return false;
        }
        // now nums[i] < nums[i+1]
        
        for (j = n - 1; nums[j] <= nums[i]; -- j) {}
        // nums[j] is the first that > nums[i].
        swap(nums, i, j);
        
        reverse(nums, i+1, n-1);
        return true;
    }
    
    private void swap(int[] A, int L, int R) {
        int tmp = A[L];
        A[L] = A[R];
        A[R] = tmp;
    }
    
    private void reverse(int[] A, int L, int R) {
        while (L < R) {
            int tmp = A[L];
            A[L] = A[R];
            A[R] = tmp;
            ++ L; -- R;
        }
    }    
}

/**
Permutations II
Difficulty: Medium

Given a collection of numbers that might contain duplicates, 
return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1]. 
 */
