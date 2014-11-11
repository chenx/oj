/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// This works. Can be simplified though.
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