// Works.
struct comp {
    bool operator()(const pair<double, int>& a, const pair<double, int>& b) {
        return a.first > b.first;
    }
};
class Solution3 {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        if (!root) return ans;

        priority_queue<pair<double, int>, vector<pair<double, int>>, comp> minHeap;
        inorderTraversal(root, target, minHeap);

        int len = k < minHeap.size() ? k : minHeap.size();
        for (int i = 0; i < len; ++ i) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }

    void inorderTraversal(TreeNode* root, double target,
        priority_queue<pair<double, int>, vector<pair<double, int>>, comp>& minHeap) {
        if (!root) return;
        inorderTraversal(root->left, target, minHeap);
        minHeap.push(pair<double, int>(abs(root->val - target), root->val));
        inorderTraversal(root->right, target, minHeap);
    }
};

// Should work. Tested locally, not in lc. 
// comp is the same as in Solution.
class Solution2 {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        if (! root) return ans;
        
        priority_queue<pair<double, int>, vector<pair<double, int>>, comp> maxQ;
        
        stack<TreeNode *> s;
        s.push(root);
        
        while (! s.empty()) {
            TreeNode * n = s.top();
            s.pop();
            
            maxQ.push(pair<double, int>(abs(target - n->val), n->val));
            if (maxQ.size() > k) maxQ.pop();
            
            if (n->left) s.push(n->left);
            if (n->right) s.push(n->right);
        }
        
        for (int i = 0; i < k; ++ i) {
            ans.push_back(maxQ.top().second);
            maxQ.pop();
        }
        
        return ans;
    }
};


// Works. Tested.
// Note the way of using custom comparator for priority queue.

class comp {
public:
    bool operator()(const pair<double, int> &a, const pair<double, int> &b) {
        return a.first < b.first;   // "<" for max heap.
    }
};
 
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        // max heap.
        priority_queue<pair<double, int>, vector<pair<double, int>>, comp> maxQ;

        stack<TreeNode *> s;
        s.push(root);
        
        while (! s.empty()) {
            TreeNode * n = s.top();
            s.pop();
            
            double dist = abs(target - n->val);
            if (maxQ.size() < k) {
                maxQ.push(pair<double, int>(dist, n->val));
            }
            else if (dist < maxQ.top().first) {
                maxQ.push(pair<double, int>(dist, n->val));
                maxQ.pop(); // pop value with the max distance from target.
            }
            
            if (n->right != NULL) s.push(n->right);
            if (n->left != NULL) s.push(n->left);
        }
        
        while (! maxQ.empty()) {
            ans.push_back(maxQ.top().second);
            maxQ.pop();
        }
        
        return ans;
    }
};    


/**
Closest Binary Search Tree Value II My Submissions Question
Difficulty: Hard

Given a non-empty binary search tree and a target value, find k values 
in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.

Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Hint:

1. Consider implement these two helper functions:
   i. getPredecessor(N), which returns the next smaller node to N.
   ii.getSuccessor(N), which returns the next larger node to N.
2. Try to assume that each node has a parent pointer, it makes the problem much easier.
3. Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
4. You would need two stacks to track the path in finding predecessor and successor node separately.
 */
