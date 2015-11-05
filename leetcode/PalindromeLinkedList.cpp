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
    // O(1) space, O(n) time.
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        
        ListNode *slow = head, *fast = head->next, *prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast == NULL) { // odd number of nodes. slow is at center node.
            prev->next = NULL;
            head = reverseList(head);
            return isEqualList(head, slow->next);
        }
        else { // even number of nodes. slow is at first of center 2 nodes.
            if (prev == NULL) {
                return slow->val == fast->val;
            }
            else {
                ListNode * tmp = slow->next;
                slow->next = NULL;
                head = reverseList(head);
                return isEqualList(head, tmp);
            }
        }
    }
    
private:
    bool isEqualList(ListNode *a, ListNode *b) {
        while (a != NULL && b != NULL) {
            if (a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        
        return a == NULL && b == NULL;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *h = NULL, *tmp;
        
        while (head != NULL) {
            tmp = head;
            head = head->next;
            tmp->next = h;
            h = tmp;
        }
        
        return h;
    }
};

/**
Palindrome Linked List
Difficulty: Easy

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
 */
