/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        for (; l1; l1 = l1->next) s1.push(l1->val);
        for (; l2; l2 = l2->next) s2.push(l2->val);

        ListNode * h = nullptr, * t = nullptr;
        int carry = 0;
        while (! s1.empty() && ! s2.empty()) {
            addNode(h, t, s1.top() + s2.top() + carry, carry);
            s1.pop(), s2.pop();
        }
        while (! s1.empty()) {
            addNode(h, t, s1.top() + carry, carry);
            s1.pop();
        }
        while (! s2.empty()) {
            addNode(h, t, s2.top() + carry, carry);
            s2.pop();
        }
        if (carry > 0) {
            addNode(h, t, carry, carry);
        }
        return h;
    }

    void addNode(ListNode *& h, ListNode *& t, int sum, int& carry) {
        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        if (h == nullptr) {
            h = t = new ListNode(sum);
        } else {
            ListNode * tmp = new ListNode(sum);
            tmp->next = h;
            h = tmp;
        }
    }
};

/**
445. Add Two Numbers II
Solved
Medium
Topics
conpanies iconCompanies

You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */
