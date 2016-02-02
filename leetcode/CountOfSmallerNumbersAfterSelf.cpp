// For another method, see: https://leetcode.com/discuss/74994/nlogn-divide-and-conquer-java-solution-based-bit-comparison


// Works too. Passes all tests. Uses BST with a "smaller" index. 
// From: https://leetcode.com/discuss/75586/14-line-44ms-c-building-bst
class Solution {
public:
    struct Node {
        int val, smaller;
        Node *left, *right;
        Node(int value, int small) : 
            val(value), smaller(small), left(NULL), right(NULL) { }
    };

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
