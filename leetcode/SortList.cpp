// Works too. Similar to Solution2.
class Solution3 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        // split.
        ListNode * h1 = head, * slow = head, * fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode * h2 = slow->next;
        slow->next = NULL;
        
        // recursion.
        h1 = sortList(h1);
        h2 = sortList(h2);
        
        // merge.
        ListNode dummy(0);
        ListNode * n = & dummy;
        
        while (h1 && h2) {
            if (h1->val < h2->val) add(n, h1);
            else add(n, h2);
        }
        
        n->next = h1 ? h1 : h2;
        
        return dummy.next;
    }
    
    void add(ListNode *& n, ListNode *& h) {
        n->next = h;
        n = h;
        h = h->next;
        //n->next = NULL; // ok with this too.
    }
};

// This works. Much better than Solution! Recurive. O(log(n)) space.
// Improved from: https://leetcode.com/discuss/73367/c-merge-sort-solution
class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *fast = head->next->next, *slow = head; // if fast = head->next, works too.
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *r = sortList(slow->next);
        slow->next = NULL;
        ListNode *l = sortList(head);
        return merge(l, r);
    }
    
    ListNode *merge(ListNode *l, ListNode *r) {
        ListNode dummy(0);
        ListNode *n = &dummy;
        while (l && r) {
            if (l->val < r->val) {
                n->next = l;
                l = l->next;
            } else {
                n->next = r;
                r = r->next;
            }
            n = n->next;
        }
        n->next = l ? l : r;
        return dummy.next;
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
 
// This works. Can be simplified though. O(1) space. Iterative.
class Solution {
public:
    ListNode *sortList(ListNode *head) {
      ListNode * L, * A, * B, * A_tail, * B_tail;
      int step, len;
    
      if (head == NULL || head->next == NULL) return head;
    
      L = new ListNode(0);
      L->next = head;
      A = new ListNode(0);
      B = new ListNode(0);
    
      for (step = 1, len = ListLen(head); step < len; step *= 2) {
        A_tail = B_tail = NULL;
        while (L->next != NULL) {
          A_tail = Append(A, A_tail, L, step);
          B_tail = Append(B, B_tail, L, step);
        }
    
        Merge(L, A, B, step); 
      }
      
      head = L->next;
      free(L); free(A); free(B);

      return head;
  }
    
    int ListLen(ListNode *head) {
        int n = 0;
        while (head) {
            head = head->next;
            ++ n;
        }
        return n;
    }
    
    /*
     * Append the first n nodes of L to the end of list H.
     * T points to the end of list H.
     * Return the tail of the appended list.
     */
    static ListNode * Append(
        ListNode * H, ListNode * H_tail, ListNode * L, int n) {
      int i;
      ListNode * head;
      
      for (i = 0; i < n; i ++) {
        if ((head = ListDetachHead(L)) == NULL) break;
        H_tail = ListAttachTail(H, H_tail, head);
      }
    
      return H_tail;
    }
    
    
    /*
     * Merge lists A and B to L by segment, each segment length is n.
     * Initially, L is empty and has only the dummy node.
     */
    static void Merge(ListNode * L, ListNode * A, ListNode * B, int n) {
      int i, j;
      ListNode * L_tail = NULL;
      ListNode * head;
    
      if (n <= 0) return;
    
      while (A->next != NULL && B->next != NULL) {
        for (i = 0, j = 0; 
             i < n && j < n && A->next != NULL && B->next != NULL; ) {
          //puts("for loop"); ListDump(A); ListDump(B); ListDump(L);
          //if (ListNodeCmp(A->next, B->next) <= 0) {
          if (A->next->val <= B->next->val) {
            head = ListDetachHead(A);
            i ++;
          } else {
            head = ListDetachHead(B);
            j ++;
          }
          L_tail = ListAttachTail(L, L_tail, head);
        } // end for. L_tail != NULL.
    
        while (i < n && A->next != NULL) {
          L_tail->next = ListDetachHead(A);
          L_tail = L_tail->next;
          i ++;
        }
        while (j < n && B->next != NULL) {
          L_tail->next = ListDetachHead(B);
          L_tail = L_tail->next;
          j ++;
        }
      } // end while
    
      while (A->next != NULL) {
        L_tail->next = ListDetachHead(A);
        L_tail = L_tail->next;
      }
    
      while (B->next != NULL) {
        L_tail->next = ListDetachHead(B);
        L_tail = L_tail->next;
      }
    }
    
    /*
     * Assumption: first node of L is a dummy node.
     */
    static ListNode * ListDetachHead(ListNode * L) {
      ListNode * n = L->next;
      if (n == NULL) return NULL;
      L->next = L->next->next;
      n->next = NULL;
      return n;
    }
    
    /*
     * Attach n to the end of list L. L_tail points to the end of list L.
     * L is a dummy node. L_tail is NULL initially. 
     * Example:
     * L_tail = ListAttachTail(L, L_tail, n);
     */
    static ListNode * ListAttachTail(
        ListNode * L, ListNode * L_tail, ListNode * n) {
      if (n == NULL) return L_tail;
      if (L_tail == NULL) L_tail = L->next = n;
      else {
        L_tail->next = n;
        L_tail = L_tail->next;
      }
      return L_tail;
    }

};
