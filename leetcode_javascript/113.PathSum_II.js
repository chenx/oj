/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} targetSum
 * @return {number[][]}
 */
var pathSum = function(root, targetSum) {
    const ans = [];
    traversal(root, [], targetSum);
    return ans;

    function traversal(root, path, targetSum) {
        if (root === null) return;
        path.push(root.val);

        if (root.left === null && root.right === null) {
            if (targetSum === root.val) ans.push(path);
            return;
        }

        targetSum -= root.val;
        if (root.left !== null) traversal(root.left, [... path], targetSum);
        if (root.right !== null) traversal(root.right, [... path], targetSum);
    }
};
