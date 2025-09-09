// Iterative
ListNode* reverse(ListNode * head) {
  // if (!head || !head->next) return head;

  ListNode * h = NULL;
  while (head) {
    ListNode * tmp = head;
    head = head->next;
    tmp->next = h;
    h = tmp;
  }
  return h;
}

// Recursive
ListNode* reverse(ListNode * head, ListNode*& tail) {
  if (!head || !head->next) return head;

  ListNode* h = head;
  head = reverse(head->next, tail);
  tail->next = h;
  tail = h;
}
