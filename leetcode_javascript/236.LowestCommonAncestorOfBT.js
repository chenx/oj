/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    if (root === null || p === null || q === null) return null;
    if (root === p || root === q) return root;

    const L = lowestCommonAncestor(root.left, p, q);
    const R = lowestCommonAncestor(root.right, p, q);

    return (L && R) ? root : (L ? L : R);

    // if (L !== null && R !== null) return root;
    // if (L !== null) return L;
    // if (R !== null) return R;
    // return null;
};
