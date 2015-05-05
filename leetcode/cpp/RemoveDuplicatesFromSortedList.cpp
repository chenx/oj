//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/24/2012
// @Last modified: 12/24/2012
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        // now list contains at least 2 nodes.
        ListNode * tmp;
        
        for (ListNode *n = head; n->next != NULL; ) {
            if (n->next->val == n->val) {
                tmp = n->next;
                n->next = n->next->next;
                delete tmp;
            }
            else {
                n = n->next;
            }            
        }
        
        return head;
    }
};
