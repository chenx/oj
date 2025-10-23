/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
var serialize = function(root) {
    let s = '';
    ser(root);
    return s;

    function ser(root) {
        if (root === null) {
            if (s !== '') s += ' ';
            s += 'null';
            return;
        }

        if (s !== '') s += ' ';
        s += root.val;

        ser(root.left);
        ser(root.right);
    }
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
    const values = data.split(' ');
    let p = 0;
    return des();

    function des() {
        if (values[p] === 'null') {
            if (p < values.length) ++ p;
            return null;
        }

        let root = new TreeNode(Number(values[p ++]));
        root.left = des();
        root.right = des();
        return root;
    }
};

/**
 * Your functions will be called as such:
 * deserialize(serialize(root));
 */
