// A more efficient method without reversing the list. O(n)
// You only need to find the first non-9 node, add 1 to it; for all later nodes equals to 9, set to 0.
class Solution2 {
public:
   ListNode* plusOne(ListNode* head) {
       // sentinel head
       ListNode* sentinel = new ListNode(0);
       sentinel->next = head;
       ListNode* notNine = sentinel;

       // find the rightmost not-nine digit
       while (head != nullptr) {
           if (head->val != 9) notNine = head;
           head = head->next;
       }
       // increase this rightmost not-nine digit by 1
       notNine->val++;
       notNine = notNine->next;
       // set all the following nines to zeros
       while (notNine != nullptr) {
           notNine->val = 0;
           notNine = notNine->next;
       }

       delete notNine;
       return sentinel->val != 0 ? sentinel : sentinel->next;
   }
};

// O(3n)
class Solution {
public:
   ListNode* plusOne(ListNode* head) {
       int carry = 1;
       head = reverse(head);
       for (ListNode* h = head; h; h = h->next) {
           h->val += carry;
           carry = 0;
           if (h->val > 9) {
               h->val -= 10;
               carry = 1;
           }
       }
       head = reverse(head);

       if (carry > 0) {
           ListNode * h = new ListNode(carry);
           h->next = head;
           head = h;
       }
       return head;
   }

   ListNode* reverse(ListNode* head) {
       ListNode* h = NULL;
       while (head) {
           ListNode* tmp = head;
           head = head->next;
           tmp->next = h;
           h = tmp;
       }
       return h;
   }
};

/**
Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.

Example 1:

Input: head = [1,2,3]
Output: [1,2,4]

Example 2:

Input: head = [0]
Output: [1]
 */
