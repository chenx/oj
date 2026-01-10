// Reversed morris in-order traversal.
// From: https://leetcode.com/problems/convert-bst-to-greater-tree/editorial/
// Time: O(n)
// Space: O(1)
class Solution3 {
public:
    TreeNode* getSuccessor(TreeNode* node) {
        TreeNode* succ = node->right;
        while (succ->left != NULL && succ->left != node) {
            succ = succ->left;
        }
        return succ;
    }

    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* node = root;

        while (node != NULL) {
            /* 
             * If there is no right subtree, then we can visit this node and
             * continue traversing left.
             */
            if (node->right == NULL) {
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
            /* 
             * If there is a right subtree, then there is at least one node that
             * has a greater value than the current one. therefore, we must
             * traverse that subtree first.
             */
            else {
                TreeNode* succ = getSuccessor(node);
                /* 
                 * If the left subtree is null, then we have never been here before.
                 */
                if (succ->left == NULL) {
                    succ->left = node;
                    node = node->right;
                }
                /* 
                 * If there is a left subtree, it is a link that we created on a
                 * previous pass, so we should unlink it and visit this node.
                 */
                else {
                    succ->left = NULL;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
            }
        }
        
        return root;
    }
};

// Inorder traversal (right to left)
// Time: O(n)
// Space: O(n)
class Solution2 {
public:
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* node = root;
        int sum = 0;

        while (true) {
            while (node) {
                stack.push(node);
                node = node->right;
            }

            if (stack.empty()) {
                break;
            }

            node = stack.top();
            stack.pop();
            sum += node->val;
            node->val = sum;

            node = node->left;
        }
        return root;
    }
};

// Recursion
// Time: O(n)
// Space: O(n)
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        return convert(root, sum);
    }

    TreeNode* convert(TreeNode* root, int& sum) {
        if (! root) return NULL;
        convert(root->right, sum);

        sum += root->val;
        root->val = sum;
        
        convert(root->left, sum);
        return root;
    }
};


/**
538. Convert BST to Greater Tree
Medium

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST 
is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
 */
