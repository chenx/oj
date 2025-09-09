void quick_sort(vector<int> nums) {
  qsort(nums, 0, nums.length() - 1);
}

void qsort(vector<int>& nums, int left, int right) {
  if (left >= right) return;

  int M = left + (right - left)/2;
  swap(nums[left], nums[M]);
  int pivot = nums[left], L = left + 1, R = right;

  while (L <= R) {
    while (L <= R && nums[L] < pivot) ++ L;
    while (L <= R && nums[R] > pivot) -- R;
    if (L < R) swap(nums[L], nums[R]);
    ++ L;
  }

  swap(nums[left], nums[R]);
  if (k < R) qsort(nums, left, R - 1);
  if (k > R) qsort(nums, R + 1, right);
}
