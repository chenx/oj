#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// This works too, and is much shorter.
// From: http://www.mitbbs.com/article_t/JobHunting/32576307.html
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummyHead(INT_MIN);
        ListNode *p = head;
        while(p != NULL)
        {
            ListNode *pre = &dummyHead;
            while(pre->next != NULL && pre->next->val < p->val)
                pre = pre->next;
            ListNode *temp = p->next;
            p->next = pre->next;
            pre->next = p;
            p = temp;
        }
        return dummyHead.next;
    }
};


// Java version. works too.
// From: http://www.mitbbs.com/article_t/JobHunting/32576307.html
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == null) return null;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
       
        ListNode i = head;
        while (i.next != null) {
            int n = i.next.val;
            ListNode j = dummy;
            while (j!=i&&j.next.val < n){
                j = j.next;
            }
            if (j == i) {
               
                i = i.next;
                continue;
            }
            ListNode pivot = i.next;
            i.next = i.next.next;
            pivot.next = j.next;
            j.next = pivot;
        }
       
        return dummy.next;
    }
}



// This works too. optimized from Solution2.
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode * cur, * cur_prev, * n, * prev;

        cur_prev = head, cur = head->next;
        while (cur != NULL) {
            for (prev = NULL, n = head; n != cur; prev = n, n = n->next) {
                if (n->val > cur->val) {
                    // take node cur out of the list.
                    ListNode * x = cur;
                    cur_prev->next = cur->next;
                    cur = cur->next;

                    if (prev == NULL) { // insert as head
                        x->next = head;
                        head = x;
                    } else { // insert between prev and n.
                        prev->next = x;
                        x->next = n;
                    }
                    
                    break;
                }
            }
            
            if (n == cur) {
                cur_prev = cur;
                cur = cur->next;
            }
        }
        
        return head;
    }
};

// This works.
class Solution2 {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode * cur, * cur_prev, * n, * prev;

        cur_prev = head, cur = head->next;
        while (cur != NULL) {
            bool done = false;
            for (prev = NULL, n = head; n != cur; prev = n, n = n->next) {
                if (prev == NULL && n->val > cur->val) { // insert as head
                    ListNode * x = cur;
                    cur_prev->next = cur->next;
                    cur = cur->next;
                    
                    x->next = head;
                    head = x;
                    
                    done = true;
                    break;
                }
                else if (prev && prev->val <= cur->val && n->val > cur->val) { // insert between prev and n
                    ListNode * x = cur;
                    cur_prev->next = cur->next;
                    cur = cur->next;
                    
                    prev->next = x;
                    x->next = n;
                
                    done = true;
                    break;
                }
            }
            
            if (! done && n == cur) {
                cur_prev = cur;
                cur = cur->next;
            }
        }
        
        return head;
    }
};

void dump(ListNode * n) {
    while (n) {
        cout << n->val << " ";
        n = n->next;
    }
    cout << endl;
}

int main() {
    ListNode * head = new ListNode(1);
    head->next = new ListNode(1);
    dump(head);
//    return 0;

    Solution2 so;
    ListNode * r = so.insertionSortList(head);
    
    dump(r);
    
    return 0;
}
