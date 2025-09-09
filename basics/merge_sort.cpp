void mergesort(vector<int>& nums) {
  msort(nums, 0, nums.size() - 1);
}

void msort(vector<int>& nums, int left, int right) {
  if (left >= right) return;

  int M = left + (right - left) / 2;
  msort(nums, left, M);
  msort(nums, M+1, right);

  vector<int> copy(nums.size());

  int i = 0, j = M+1, k = 0, n = nums.size();
  while (i <= M && j < n) {
    if (nums[i] < nums[j]) copy[k ++] = nums[i ++];
    else copy[k ++] = nums[j ++];
  }
  while (i <= M) copy[k ++] = nums[i ++];
  while (j <= n) copy[k ++] = nums[j ++];
}
