// Works. Use stack. O(n) time, O(n) space.
class Solution3 {
public:
    bool isPalindrome(ListNode* head) {
        if (! head || ! head->next) return true;

        stack<int> s;
        ListNode * slow = head, * fast = head->next;
        
        while (fast && fast->next) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // even number of nodes 
        if (fast != NULL) s.push(slow->val); // push last node of first half.
        slow = slow->next; // advance to first node of second half.
        
        while (slow != NULL) {
            if (s.top() != slow->val) return false;
            s.pop();
            slow = slow->next;
        }
        return true;
    }
};    
    
// Works. Tested. O(1) space, O(n) time.
// Idea: find mid point, reverse 2nd half (slow->next), compare with 1st half.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        
        ListNode * slow = head, * fast = slow->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode * head2 = rev(slow->next); // 2nd half.

        while (head2 != NULL) {
            if (head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
    
    // improved from isPalindrome(). This works too.
    bool isPalindrome2(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        
        ListNode * slow = head, * fast = slow->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        for (ListNode * head2 = rev(slow->next); 
             head2 != NULL; head = head->next, head2 = head2->next) {
            if (head->val != head2->val) return false;
        }
        return true;
    }
    
    // reverse a linked list.
    ListNode * rev(ListNode * head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode * h = NULL;
        while (head != NULL) {
            ListNode * tmp = head->next;
            head->next = h;
            h = head;
            head = tmp;
        }
        
        return h;
    }
};

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
