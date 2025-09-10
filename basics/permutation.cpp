class Solution {
public:
   void nextPermutation(vector<int>& nums) {
       int n = nums.size();


       int i, j;
       // Find first i, nums[i] < nums[i+1]
       for (i = n-2; i >= 0 && nums[i] >= nums[i+1]; i --) ;
       if (i == -1) {
           reverse(nums.begin(), nums.end());
           return;
       }


       // Find first item from right, nums[j] > nums[i]
       for (j = n-1; nums[j] <= nums[i]; --j) ;
       swap(nums[i], nums[j]);
       reverse(nums.begin() + i + 1, nums.end());
   }
};
