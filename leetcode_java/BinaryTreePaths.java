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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<String>();
        String path = "";
        getPaths(root, ans, path);
        return ans;
    }
    
    void getPaths(TreeNode root, List<String> ans, String path) {
        if (null == root) return;

        path = (path.equals("")) ? ("" + root.val) : (path + "->" + root.val);
        if (null == root.left && null == root.right) {
            ans.add(path);
            return;
        }
        if (root.left != null) getPaths(root.left, ans, path);
        if (root.right != null) getPaths(root.right, ans, path);
    }
}


/**
Binary Tree Paths
Difficulty: Easy

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]
 */
