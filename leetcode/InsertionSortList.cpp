#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Works too.
class Solution8 {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        while (head != NULL) {
            ListNode * n = & dummy;
            for (; n->next && n->next->val < head->val; n = n->next) ;
            
            ListNode * tmp = n->next;
            n->next = head;
            head = head->next;
            n->next->next = tmp;
        }
        
        return dummy.next;
    }
};

// Works too.
class Solution7 {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        while (head != NULL) {
            ListNode * n = & dummy;
            while (n->next && n->next->val < head->val) 
                n = n->next;
            
            ListNode * tail = n->next;
            n->next = head;
            head = head->next;
            n->next->next = tail;
        }

        return dummy.next;
    }
};

// This works too. Best so far. Improved from Solution4.
class Solution6 {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        while (head != NULL) {
            ListNode * n = & dummy;
            while (n->next != NULL && n->next->val < head->val) {
                n = n->next;
            }
            // insert after n.
            ListNode * tmp = head->next;
            head->next = n->next;
            n->next = head;
            
            head = tmp;
        }
        
        return dummy.next;
    }
};

// This works too.
// start from head, find insertion point and insert.
// Considerations: 1) insert before head, 2) no move, 3) insert between head and current position.
class Solution5 {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (! head || ! head->next) return head;
        ListNode * cur = head->next, * cur_prev = head;
        
        while (cur) {
            if (head->val >= cur->val) { // 1) insert before head. Note ">=".
                cur_prev->next = cur->next;
                cur->next = head;
                head = cur;
                cur = cur_prev->next;
            }
            else {
                ListNode * p = head;
                while (p->next->val < cur->val) { p = p->next; }
                
                if (p->next == cur) { // 2) no move.
                    cur_prev = cur;
                    cur = cur->next;
                }
                else { // 3) now, insert cur after p.
                    cur_prev->next = cur->next;
                    cur->next = p->next;
                    p->next = cur;
                    cur = cur_prev->next;
                }
            }
        }
        
        return head;
    }
};

// This works too, and is much shorter.
// From: http://www.mitbbs.com/article_t/JobHunting/32576307.html
// --> However, this is a memory leak on dummyHead. Should delete it before return.
// --> No, this is not a memory leak, because dummyHead is a local variable.
// This basically inserts each node in give list to a new list starting with dummyHead.
class Solution4 {
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
public class Solution3 {
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
