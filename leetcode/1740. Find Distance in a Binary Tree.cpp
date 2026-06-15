// BFS
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        if (root == NULL || p == q) return 0;

        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        TreeNode* np = NULL, *nq = NULL;
        buildGraph(graph, root, np, nq, p, q);

        if (np == NULL || nq == NULL) return -1;

        queue<pair<TreeNode*, int>> queue; // <node, dist>
        queue.push({np, 0});
        set<TreeNode*> used;
        used.insert(np);

        while (! queue.empty()) {
            TreeNode* node = queue.front().first;
            int dist = queue.front().second;
            queue.pop();
            
            for (int i = 0, len = graph[node].size(); i < len; ++ i) {
                TreeNode* nextNode = graph[node][i];
                if (! used.contains(nextNode)) {
                    if (graph[node][i] == nq) {
                        return dist + 1;
                    }
                    used.insert(nextNode);
                    queue.push({nextNode, dist + 1});
                }
            }
        }

        return 0;
    }

    void buildGraph(unordered_map<TreeNode*, vector<TreeNode*>>& graph, TreeNode* root, 
            TreeNode*& np, TreeNode*& nq, int p, int q) {
        if (! root) return;
        if (root->val == p) { np = root; }
        else if (root->val == q) { nq = root; }

        if (root->left) {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
            buildGraph(graph, root->left, np, nq, p, q);
        }
        if (root->right) {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
            buildGraph(graph, root->right, np, nq, p, q);
        }
    }
};


/**
1740. Find Distance in a Binary Tree
Medium
Topics
conpanies iconCompanies
Hint

Given the root of a binary tree and two integers p and q, return the distance between the nodes of 
value p and value q in the tree.

The distance between two nodes is the number of edges on the path from one to the other.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
Output: 3
Explanation: There are 3 edges between 5 and 0: 5-3-1-0.
 */
