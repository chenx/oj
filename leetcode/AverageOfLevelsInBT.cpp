class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            double sum = 0;
            int count = q.size();
            for (int i = 0; i < count; ++ i) {
                TreeNode* n = q.front();
                sum += n->val;

                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
                q.pop();
            }
            ans.push_back(sum / count);
        }
        return ans;
    }
};

/**
637. Average of Levels in Binary Tree.

Given the root of a binary tree, return the average value of the nodes on each level in the form of an array.
Answers within 10-5 of the actual answer will be accepted. 
 */
