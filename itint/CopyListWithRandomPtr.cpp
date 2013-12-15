/**
链表结点的定义(请不要在代码中定义该类型)
struct ListNode {
    ListNode *next;
    ListNode *random;
};
*/
// 返回复制的新链表头结点
ListNode* copyListWithRandomPtr(ListNode *head) {
    if (! head) return NULL;
    
    ListNode * h = head;
    while (h) {
        ListNode * n = new ListNode();
        n->next = h->next;
        h->next = n;
        h = h->next->next;
    }
    
    for (h = head; h; h = h->next->next) {
        h->next->random = h->random ? h->random->next : NULL;
    }
    
    ListNode * new_head = head->next;
    ListNode * t;
    
    for (h = head; h; h = h->next) {
        t = h->next;
        h->next = h->next->next;
        
        if (h->next == NULL) t->next = NULL;
        else t->next = h->next->next;
    }
    
    return new_head;
}