// This works.
// But may use a lot of space in path.
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        getPath(root, sum, path, ans);
        return ans;
    }
    
    private void getPath(TreeNode root, int sum, List<Integer> path, List<List<Integer>> ans) {
        if (root == null) return;
        
        sum -= root.val;
        path.add(root.val);
        if (root.left == null && root.right == null) {
            if (sum == 0) ans.add(new ArrayList<Integer>(path));
        }
        else {
            getPath(root.left, sum, path, ans);
            getPath(root.right, sum, path, ans);
        }
        
        path.remove(path.size() - 1);
    }
}

// This works too.
// This uses linear space for path, is more efficient.
public class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        getPath(root, sum, path, ans);
        return ans;
    }
    
    private void getPath(TreeNode root, int sum, List<Integer> path, List<List<Integer>> ans) {
        if (root == null) return;
        
        sum -= root.val;
        path.add(root.val);
        if (root.left == null && root.right == null) {
            if (sum == 0) ans.add(new ArrayList<Integer>(path));
            path.remove(path.size() - 1);
            return;
        }

        getPath(root.left, sum, path, ans);
        getPath(root.right, sum, path, ans);

        path.remove(path.size() - 1);
    }
}


/**
Path Sum II
Difficulty: Medium

Given a binary tree and a sum, find all root-to-leaf paths 
where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]

 */
