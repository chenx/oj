// Time: O(V+E)
// Space: O(V+E)
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        if (! root) return 0;

        map<int, vector<int>> graph;
        createGraph(root, graph);

        int time = -1;
        queue<int> q;
        q.push(start);
        set<int> used;
        used.insert(start);

        while (! q.empty()) {
            time += 1;
            int count = q.size();

            for (int i = 0; i < count; ++ i) {
                int node = q.front();
                q.pop();

                for (int nextNode : graph[node]) {
                    if (! used.contains(nextNode)) {
                        used.insert(nextNode);
                        q.push(nextNode);
                    }
                }
            }
        }

        return time;
    }

    void createGraph(TreeNode* root, map<int, vector<int>>& graph) {
        if (!root) return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            createGraph(root->left, graph);
        }
        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            createGraph(root->right, graph);
        }
    }
};


/**
2385. Amount of Time for Binary Tree to Be Infected
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given the root of a binary tree with unique values, and an integer start. At minute 0, 
an infection starts from the node with value start.

Each minute, a node becomes infected if:

    The node is currently uninfected.
    The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.

 

Example 1:

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Example 2:

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
 */
