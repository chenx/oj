// Works. Tested. Modified from Solution5. But Solution5 is most intuitive.
class Solution6 {
private:
    unordered_map<TreeNode *, int> ranks;
public:
    int rob(TreeNode* root) {
        if (! root) return 0;
        return ranks[root] = max(robNoRoot(root), 
            root->val + robNoRoot(root->left) + robNoRoot(root->right));
    }
    
    int robNoRoot(TreeNode * root) { // rob next level, without root.
        if (! root) return 0;
        return getV(root->left) + getV(root->right);
    }
    
    int getV(TreeNode * n) { // retrieve cached value
        if (! n) return 0;
        if (ranks.count(n)) return ranks[n];
        return rob(n);
    }
};

// Works. Tested. Simplified from Solution4.
class Solution5 {
private:
    unordered_map<TreeNode *, int> ranks;
public:
    int rob(TreeNode* root) {
        if (! root) return 0;
        
        int v1 = getV(root->left) + getV(root->right); // no root.
        
        int v2 = root->val; // include root.
        if (root->left) v2 += getV(root->left->left) + getV(root->left->right);
        if (root->right) v2 += getV(root->right->left) + getV(root->right->right);
        
        return ranks[root] = max(v1, v2);
    }
    
    int getV(TreeNode * n) {
        if (! n) return 0;
        if (ranks.count(n)) return ranks[n];
        return rob(n);
    }
};

// Works. Tested. Simplified form Solution3.
class Solution4 {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> ranks;
        return helper(root, ranks);
    }
    
    int helper(TreeNode *root, unordered_map<TreeNode *, int> &ranks) {
        if (! root) return 0;
        
        int v1 = getNodeVal(root->left, ranks)
                + getNodeVal(root->right, ranks); // not include root.

        int v2 = root->val; // include root.
        if (root->left)
            v2 += getNodeVal(root->left->left, ranks) +
                  getNodeVal(root->left->right, ranks);
        if (root->right)
            v2 += getNodeVal(root->right->left, ranks) +
                  getNodeVal(root->right->right, ranks);
        
        return ranks[root] = max(v1, v2);
    }
    
    int getNodeVal(TreeNode * n, unordered_map<TreeNode *, int> &ranks) {
        if (! n) return 0;
        if (ranks.count(n)) return ranks[n];
        return ranks[n] = helper(n, ranks);
    }
};

// Works. Tested. Simplified from Solution2.
class Solution3 {
public:
    int rob(TreeNode* root) {
        unordered_map<int, int> ranks;
        return helper(root, ranks, 1);
    }
    
    int helper(TreeNode *root, unordered_map<int, int> &ranks, int rank) {
        if (! root) return 0;
        
        // not include root.
        int v1 = getNodeVal(root->left, ranks, 2 * rank)
                + getNodeVal(root->right, ranks, 2 * rank + 1);

        // include root.
        int v2 = root->val;
        if (root->left)
            v2 += getNodeVal(root->left->left, ranks, 4 * rank) +
                  getNodeVal(root->left->right, ranks, 4 * rank + 1);
        if (root->right)
            v2 += getNodeVal(root->right->left, ranks, 4 * rank + 2) +
                  getNodeVal(root->right->right, ranks, 4 * rank + 3);
        
        ranks[rank] = max(v1, v2);
        return ranks[rank];
    }
    
    int getNodeVal(TreeNode * n, unordered_map<int, int> &ranks, int rank) {
        if (! n) return 0;
        if (ranks.count(rank)) return ranks[rank];
        return ranks[rank] = helper(n, ranks, rank);
    }
};

// Works too. Tested.
// With memorization, this is more efficient. O(n).
class Solution2 {
public:
    int rob(TreeNode* root) {
        unordered_map<int, int> ranks;
        return helper(root, ranks, 1);
    }
    
    int helper(TreeNode *root, unordered_map<int, int> &ranks, int rank) {
        if (! root) {
            return 0;
        }
        if (! root->left && ! root->right) {
            ranks[rank] = root->val;
            return root->val;
        }
        
        // not include root.
        int v1 = 0;
        if (root->left) v1 += getNodeRankVal(root->left, ranks, 2 * rank);
        if (root->right) v1 += getNodeRankVal(root->right, ranks, 2 * rank + 1);

        // include root.
        int v2 = root->val;
        if (root->left) {
            v2 += getNodeRankVal(root->left->left, ranks, 4 * rank) +
                  getNodeRankVal(root->left->right, ranks, 4 * rank + 1);
        }
        if (root->right) {
            v2 += getNodeRankVal(root->right->left, ranks, 4 * rank + 2) +
                  getNodeRankVal(root->right->right, ranks, 4 * rank + 3);
        }
        
        ranks[rank] = max(v1, v2);
        return ranks[rank];
    }
    
    int getNodeRankVal(TreeNode * n, unordered_map<int, int> &ranks, int rank) {
        if (! n) return 0;
        if (ranks.find(rank) == ranks.end()) {
            ranks[rank] = helper(n, ranks, rank);
        }
        return ranks[rank];
    }
};

// Works. Tested. By: X.C.
// Just straighforward recursive. This is not efficient though.
class Solution {
public:
    int rob(TreeNode* root) {
        if (! root) return 0;
        
        // without this may work, but times out for large input.
        if (! root->left && ! root->right) return root->val;
        
        return max(
            root->val + (root->left ? (rob(root->left->left) + rob(root->left->right)) : 0)
                   + (root->right ? (rob(root->right->left) + rob(root->right->right)) : 0),
            rob(root->left) + rob(root->right)
            );
    }
};


/**
House Robber III
Difficulty: Medium

The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called the "root." 
Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this 
place forms a binary tree". It will automatically contact the 
police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight 
without alerting the police.

Example 1:

     3
    / \
   2   3
    \   \ 
     3   1

Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:

     3
    / \
   4   5
  / \   \ 
 1   3   1

Maximum amount of money the thief can rob = 4 + 5 = 9. 
 */
