// Merge 2 arrays.

void mergesort(vector<int>& nums) {
  msort(nums, 0, nums.size() - 1);
}

void msort(vector<int>& nums, int left, int right) {
  if (left >= right) return;

  int M = left + (right - left) / 2;
  msort(nums, left, M);
  msort(nums, M+1, right);

  int n = nums.size();
  vector<int> copy(n);

  int i = 0, j = M+1, k = 0;
  while (i <= M && j < n) {
    if (nums[i] < nums[j]) copy[k ++] = nums[i ++];
    else copy[k ++] = nums[j ++];
  }
  while (i <= M) copy[k ++] = nums[i ++];
  while (j < n) copy[k ++] = nums[j ++];
}


// Merge 2 lists
class Solution {
public:
   ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       if (!list1) return list2;
       if (!list2) return list1;


       ListNode *h = NULL, *t = NULL;
       while (list1 && list2) {
           if (list1->val < list2->val) {
               getNextNode(list1, list2, h, t);
           } else {
               getNextNode(list2, list1, h, t);
           }
       }


       if (list1) { t->next = list1; }
       if (list2) { t->next = list2; }


       return h;
   }


   void getNextNode(ListNode*& list1, ListNode*& list2,
                    ListNode*& h, ListNode*& t) {
       if (h == NULL) {
           h = t = list1;
           list1 = list1->next;
           t->next = NULL;
       } else {
           t->next = list1;
           list1 = list1->next;
           t = t->next;
           t->next = NULL;
       }
   }
};

