/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == NULL) return ans;

        int minCol = INT_MAX, maxCol = INT_MIN;

        map<int, vector<int> > mp; // (col, values)
        queue<pair<TreeNode *, int> > q; // (node, col).
        q.push(pair<TreeNode *, int>(root, 0));

        while (! q.empty()) {
            map<int, vector<int>> row; // <col, values>
            for (int ct = q.size(); ct > 0; -- ct) {
                TreeNode * n = q.front().first;
                int col = q.front().second;
                q.pop();

                row[col].push_back(n->val);

                minCol = min(minCol, col);
                maxCol = max(maxCol, col);

                if (n->left) q.push(pair<TreeNode *, int>(n->left, col - 1));
                if (n->right) q.push(pair<TreeNode *, int>(n->right, col + 1));
            }

            for (auto [col, values] : row) {
                sort(values.begin(), values.end());
                for (int val : values) mp[col].push_back(val);
            }
        }

        for (int i = minCol; i <= maxCol; ++ i) {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};

/**
987. Vertical Order Traversal of a Binary Tree
Hard

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions 
(row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each 
column index starting from the leftmost column and ending on the rightmost column. There 
may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
 */
