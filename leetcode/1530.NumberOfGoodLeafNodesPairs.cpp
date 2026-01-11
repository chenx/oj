// Conversion to graph and BFS.
// From: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/editorial/
// Time: O(n)
// Space: O(n)
class Solution2 {
private:
    void traverseTree(TreeNode* currNode, TreeNode* prevNode,
                      unordered_map<TreeNode*, vector<TreeNode*>>& graph,
                      unordered_set<TreeNode*>& leafNodes) {
        if (!currNode) {
            return;
        }
        if (!currNode->left && !currNode->right) {
            leafNodes.insert(currNode);
        }
        if (prevNode) {
            graph[prevNode].push_back(currNode);
            graph[currNode].push_back(prevNode);
        }
        traverseTree(currNode->left, currNode, graph, leafNodes);
        traverseTree(currNode->right, currNode, graph, leafNodes);
    }

public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        unordered_set<TreeNode*> leafNodes;

        traverseTree(root, nullptr, graph, leafNodes);

        int ans = 0;

        for (auto leaf : leafNodes) {
            queue<TreeNode*> bfsQueue;
            unordered_set<TreeNode*> seen;
            bfsQueue.push(leaf);
            seen.insert(leaf);

            // Go through all nodes within the given distance of the current leaf node.
            for (int i = 0; i <= distance; i++) {
                int size = bfsQueue.size();
                for (int j = 0; j < size; j++) {
                    TreeNode* currNode = bfsQueue.front();
                    bfsQueue.pop();
                    if (leafNodes.count(currNode) && currNode != leaf) {
                        ans++;
                    }
                    if (graph.count(currNode)) {
                        for (auto neighbor : graph[currNode]) {
                            if (!seen.count(neighbor)) {
                                bfsQueue.push(neighbor);
                                seen.insert(neighbor);
                            }
                        }
                    }
                }
            }
        }
        return ans / 2;
    }
};


// Post-Order Traversal With Prefix Sum Counting
// From: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/editorial/
//
// N is size of the binary tree rooted at root, 
// D be the maximum distance given by distance, and 
// H be the height of the binary tree.
// Time Complexity: O(N⋅D)
// Space: O(H)
class Solution {
private:
    vector<int> postOrder(TreeNode* currentNode, int distance) {
        if (!currentNode)
            return vector<int>(12);
        else if (!currentNode->left && !currentNode->right) {
            vector<int> current(12);
            // Leaf node's distance from itself is 0
            current[0] = 1;
            return current;
        }

        // Leaf node count for a given distance i
        vector<int> left = postOrder(currentNode->left, distance);
        vector<int> right = postOrder(currentNode->right, distance);

        vector<int> current(12);

        // Combine the counts from the left and right subtree and shift by +1 distance
        for (int i = 0; i < 10; i++) {
            current[i + 1] = left[i] + right[i];
        }

        // Initialize to total number of good leaf nodes pairs from left and right subtrees.
        current[11] += left[11] + right[11];

        // Count all good leaf node distance pairs
        int prefixSum = 0;
        int i = 0;
        for (int d2 = distance - 2; d2 >= 0; d2--) {
            prefixSum += left[i++];
            current[11] += prefixSum * right[d2];
        }

        return current;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        return postOrder(root, distance)[11];
    }
};


/**
1530. Number of Good Leaf Nodes Pairs
Medium

You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes 
of a binary tree is said to be good if the length of the shortest path between them is less than or 
equal to distance.

Return the number of good leaf node pairs in the tree.
 */
