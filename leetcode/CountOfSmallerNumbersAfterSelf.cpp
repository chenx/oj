// Solution4. Works. Tested. By: XC.
// Use the augmented BST (similar to multiset) from CountOfRangeSum.cpp.
// This is better than Solution3, as Solution3 is more a shortcut rather 
// than a formal implementation of multiset, but this is a formal multiset.
// 
// Actually, the multiset here is an Ordered Statistics Tree, see:
// https://en.m.wikipedia.org/wiki/Order_statistic_tree
//
class Node {
public:
    long long val;
    int size;  // number of nodes in tree using this node as root.
    Node * left, * right;
    Node(long long v) : val(v), size(1), left(NULL), right(NULL) {}
};

// An augmented BST, with a field "size" for number of nodes in this tree.
class Tree {
public:
    Tree() : root(NULL) {}
    void insert(long long v) { insert(root, v); }
    int queryLE(long long num) { return queryLE(root, num); }
    int lower_bound(long long num) { return queryLE(root, num); }
    int upper_bound(long long num) { return queryLE(root, num - 1); }

private:
    Node *root;

    void insert(Node *& node, long long num) {
        if (! node) {
            node = new Node(num);
            return;
        }

        if (num < node->val) insert(node->left, num);
        else if (num > node->val) insert(node->right, num);

        node->size ++; // number of nodes in left and right subtrees.
    }

    // return number of nodes whose value <= num.
    int queryLE(Node * node, long long num) {
        if (node == NULL) return 0;

        if (num < node->val) {
            return queryLE(node->left, num);
        }
        else if (num > node->val) {
            int temp = node->size - (node->right ? node->right->size : 0);
            return queryLE(node->right, num) + temp;
        }
        else { // number of nodes in left subtree.
            return node->size - (node->right ? node->right->size : 0);
        }
    }    
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> v;
        Tree t;
        
        for (int i = nums.size() - 1; i >= 0; -- i) {
            v.push_back(t.queryLE(nums[i] - 1)); // smaller, not include self.
            t.insert(nums[i]);
        }
        
        reverse(v.begin(), v.end());
        return v;
    }
};

// Solution3 is modified from Solution2.
// Works, tested.
class Node {
public:
    int val, smaller;    
    Node * left, * right;
    Node(int v) : val(v), smaller(0), left(NULL), right(NULL) {}
};

// This tree allows duplicated value, and store them in different nodes.
class Tree {
public:
    Tree() { root = NULL; }
    int insert(int v) { return insertNode(root, v); }
    
private:
    Node * root;

    int insertNode(Node *& root, int v) {
        if (! root) {
            root = new Node(v);
            return 0;
        }
        
        if (v < root->val) {
            root->smaller ++;
            return insertNode(root->left, v);
        }
        else { // number of nodes whose value is smaller than v.
            return insertNode(root->right, v) + root->smaller + (v > root->val ? 1 : 0);
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> v;
        Tree t;
        
        for (int i = nums.size() - 1; i >= 0; -- i) {
            v.push_back(t.insert(nums[i]));
        }
        
        reverse(v.begin(), v.end());
        return v;
    }
};

// For another method, see: https://leetcode.com/discuss/74994/nlogn-divide-and-conquer-java-solution-based-bit-comparison


// Works too. Passes all tests. Uses BST with a "smaller" index. 
// From: https://leetcode.com/discuss/75586/14-line-44ms-c-building-bst
class Solution2 {
public:
    // In a tree of this node, duplicated values are in separate nodes.
    struct Node {
        int val, smaller;
        Node *left, *right;
        Node(int value, int small) : 
            val(value), smaller(small), left(NULL), right(NULL) { }
    };

    // Return: number of nodes whose value is smaller than v.
    int insert(Node *&root, int value) {
        if (root == NULL) {
            root = new Node(value, 0);
            return 0;
        }

        if (value < root->val) {
            ++ root->smaller;
            return insert(root->left, value);
        }
        else { 
            return insert(root->right, value) + root->smaller + (value > root->val ? 1 : 0);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        Node *root = NULL;
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; -- i) {
            ans.push_back(insert(root, nums[i]));
        }
        reverse(ans.begin(), ans.end());

        return ans; 
    }
}

    
// Works. But times out for large input. Naive solution, O(n^2).
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> counts(len);
        for (int i = 0; i < len; ++ i) {
            counts[i] = 0;
            for (int j = i + 1; j < len; ++ j) {
                if (nums[j] < nums[i]) ++ counts[i];
            }
        }
        return counts;
    }
};

/**
Count of Smaller Numbers After Self
Difficulty: Hard

You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller 
elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Return the array [2, 1, 1, 0]. 
 */
