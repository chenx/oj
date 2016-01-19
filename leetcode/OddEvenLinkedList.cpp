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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *h1 = NULL, *t1 = NULL, *h2 = NULL, *t2 = NULL;
        
        for (bool odd = true; head != NULL; odd = ! odd) {
            if (odd) add(h1, t1, head);
            else add(h2, t2, head);
        }
        
        if (t1 == NULL) return h2;
        // else
        t1->next = h2;
        return h1;
    }
    
    void add(ListNode *& h, ListNode *& t, ListNode *& n) {
        if (h == NULL) {
            h = t = n;
        }
        else {
            t->next = n;
            t = n;
        }
        
        n = n->next;
        t->next = NULL;
    }
};


/**
Odd Even Linked List
Difficulty: Easy

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ... 
 */
