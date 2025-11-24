/**
 * Definition for _Node.
 * class _Node {
 *     val: number
 *     left: _Node | null
 *     right: _Node | null
 *     parent: _Node | null
 *     
 *     constructor(v: number) {
 *         this.val = v;
 *         this.left = null;
 *         this.right = null;
 *         this.parent = null;
 *     }
 * }
 */

function lowestCommonAncestor(p: _Node | null, q: _Node | null): _Node | null {
    const path = new Set();

    while (p !== null) {
        path.add(p);
        p = p.parent;
    }

    while (q !== null) {
        if (path.has(q)) return q;
        q = q.parent;
    }

    return null;
};


/**
1650. Lowest Common Ancestor of a Binary Tree III
Medium

Given two nodes of a binary tree p and q, return their lowest common ancestor (LCA).

Each node will have a reference to its parent node. The definition for Node is below:

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}

According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q 
in a tree T is the lowest node that has both p and q as descendants (where we allow a node to be 
a descendant of itself)."
 */
