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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) { // remove head.
            ListNode * tmp = head;
            head = head->next;
            delete tmp;
        }
        
        if (! head) return NULL;
        
        ListNode * n = head;
        while (n->next) { 
            if (n->next->val == val) { // remove head->next
                ListNode * tmp = n->next;
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

/**
Remove Linked List Elements.

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5 
*/
