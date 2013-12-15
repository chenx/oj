
//
// http://www.mitbbs.com/article_t/JobHunting/32569169.html
//
void quick_sort(node *&head, node *&tail) {
    if (!head) return;
    node *lh, *lt, *rh, *rt;
    lh = lt = rh = rt = NULL;
    for (node *p = head->next; p; p = p->next) {
        if (p->val < head->val) {
            if (!lh) lh = lt = p;
            else lt->next = p, lt = p;
        } else {
            if (!rh) rh = rt = p;
            else rt->next = p, rt = p;
        }
    }
    if (lh) lt->next = NULL;
    if (rh) rt->next = NULL;
    quick_sort(lh, lt);
    quick_sort(rh, rt);
    node *p = head;
    p->next = NULL, tail = p;
    if (lh) head = lh, lt->next = p;
    if (rh) p->next = rh, tail = rt;
}
