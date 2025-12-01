// See: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/editorial/
// Time: O(n)
// Space: O(n)
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        map<TreeNode*, set<TreeNode*>> graph;

        buildGraph(root, graph);

        queue<pair<TreeNode*, int>> q; // <node, distance>
        q.push({target, 0});

        set<TreeNode*> used;
        used.insert(target);

        while (! q.empty()) {
            TreeNode* node = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (dist == k) {
                result.push_back(node->val);
                continue;
            }

            for (auto nextNode : graph[node]) {
                if (! used.contains(nextNode)) {
                    used.insert(nextNode);
                    q.push({nextNode, dist + 1});
                }
            }
        }
        return result;
    }

    void buildGraph(TreeNode* root, map<TreeNode*, set<TreeNode*>>& graph) {
        if (!root) return;

        if (root->left) {
            graph[root].insert(root->left);
            graph[root->left].insert(root);
            buildGraph(root->left, graph);
        }
        if (root->right) {
            graph[root].insert(root->right);
            graph[root->right].insert(root);
            buildGraph(root->right, graph);
        }
    }
};


/**
863. All Nodes Distance K in Binary Tree
Medium

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of 
the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
 */
