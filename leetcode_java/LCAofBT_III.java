class Solution {
    public Node lowestCommonAncestor(Node p, Node q) {
        HashSet<Node> set = new HashSet<Node>();

        for (; p != null; p = p.parent) {
            set.add(p);
        }

        for (; q != null; q = q.parent) {
            if (set.contains(q)) return q;
        }
        return null;
    }
}

/**
1650. Lowest Common Ancestor of a Binary Tree III

Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}

According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a tree T 
is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)."
 */
