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
    int getNodeCounting(TreeNode* root) {
        int count = getCount(root);
        cout << "count = " << count << endl;
        return count;
    }

    int getCount(TreeNode* root) {
        if (! root) {
            return 0;
        }

        if (! root->left && ! root->right) {
            return 1;
        }
        return 1 + getCount(root->left) + getCount(root->right);
    }
};

/**
Coding Problem 6: Node counting

Prompt: Rewrite the following unclear problem description into a structured interview question:
You are given a tree, where each node represents a machine.
Communication is only possible between parent and child nodes.

The communication relies on the provided interfaces:
sendAsyncMessage(target, message): Sends an asynchronous message (already implemented, no need to implement).
receiveMessage(message): A method you need to implement for handling incoming messages.

Question 1: Count the total number of machines

Goal: Design a method to count how many machines exist in the entire tree.

Basic logic:

When receiveMessage(message) receives a count message, it forwards the same message to all of its children.
When it receives a response message from a child, it records the child’s count.
Once all child responses are collected, it computes the sum and sends the result back to its parent.

Special cases:
If the node is a leaf (no children), it directly returns 1 to its parent.
If the node is the root, the final sum is the total number of machines in the tree.

Example:
A 3-level tree: root → 2 children → each child has 2 leaves.
The result should be 7 machines in total.

Key Points:
Distributed communication model: Only parent-child message passing is allowed.
Recursive counting logic: count request propagates down → responses bubble up → aggregate results.

Boundary conditions: Special handling for root and leaf nodes.
Robustness: Must handle potential failures (e.g., lost messages, missing child responses).
 */
