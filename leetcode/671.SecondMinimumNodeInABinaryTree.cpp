// Time: O(n)
// Space: O(n)
class Solution2 {
public:
    int findSecondMinimumValue(TreeNode* root) {
        unordered_set<int> values;
        dfs(root, values);

        if (values.size() <= 1) return -1;
        int min1 = root->val, min2 = INT_MAX;
        for (int v : values) {
            if (min1 < v && v < min2) min2 = v;
        }
        return min2;
    }

    void dfs(TreeNode* root, unordered_set<int>& values) {
        if (! root) return;
        values.insert(root->val);
        dfs(root->left, values);
        dfs(root->right, values);
    }
};

// Time: O(nlogn). get through n nodes. insert into set (a red-black tree) is log(n) each node.
// Space: O(n)
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> values;
        dfs(root, values);

        if (values.size() <= 1) return -1;
        return * (++ values.begin());
    }

    void dfs(TreeNode* root, set<int>& values) {
        if (! root) return;
        values.insert(root->val);
        dfs(root->left, values);
        dfs(root->right, values);
    }
};


/**
671. Second Minimum Node In a Binary Tree
Easy

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node 
in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is 
the smaller value among its two sub-nodes. More formally, the property 
root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' 
value in the whole tree.

If no such second minimum value exists, output -1 instead.
 */
