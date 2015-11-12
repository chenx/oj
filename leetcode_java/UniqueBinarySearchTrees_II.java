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
    public List<TreeNode> generateTrees(int n) {
        return g(1, n);
    }
    
    private List<TreeNode> g(int L, int R) {
        List<TreeNode> list = new ArrayList<TreeNode>();

        if (L > R) {
            list.add(null);
            return list;
        }
        
        if (L == R) {
            list.add(new TreeNode(L));
            return list;
        }
        
        for (int i = L; i <= R; ++ i) {
            List<TreeNode> left = g(L, i-1);
            List<TreeNode> right = g(i+1, R);
            for (int j = 0, lenj = left.size(); j < lenj; ++ j) {
                for (int k = 0, lenk = right.size(); k < lenk; ++ k) {
                    TreeNode n = new TreeNode(i);
                    n.left = left.get(j);
                    n.right = right.get(k);
                    list.add(n);
                }
            }
        }
        
        return list;
    }
}


/**
Problem:
Given n, generate all structurally unique BST's (binary search trees) 
that store values 1...n.
For example,
Given n = 3, your program should return all 5 unique BST's shown below.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
