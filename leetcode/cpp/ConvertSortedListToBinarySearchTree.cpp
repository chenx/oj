//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/18/2012
// @Last modified: 12/18/2012
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// List will be destroyed.
// If not to destroy list, may use a counter.

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);
        
        ListNode *n1_prev = NULL, * n1 = head, * n2 = head->next;
        
        while (n2 != NULL) {
            n1_prev = n1;
            n1 = n1->next;
            n2 = n2->next;
            if (n2 == NULL) break;
            n2 = n2->next;
        }
        
        // now n1 is middle of list.
        TreeNode *n = new TreeNode(n1->val); // no need to create new node, just n = n1.
        
        if (n1_prev != NULL) n1_prev->next = NULL; // break list.
        n->left = sortedListToBST(head);
        
        n->right = sortedListToBST(n1->next);
        
        return n;
    }
};


//
// This works too, and codes looks a little better.
//
class Solution2 {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (! head ) return NULL;
        if (! head->next) return new TreeNode(head->val);
        
        ListNode * fast = head->next, * slow = head, * prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        // now slow is middle of list.
        TreeNode * n = new TreeNode(slow->val);
        
        if (prev) {
            prev->next = NULL; // break list    
            n->left = sortedListToBST(head);
            n->right = sortedListToBST(slow->next);
        } else {
            n->left = NULL;
            n->right = new TreeNode(fast->val);
        }
        return n;
    }
};