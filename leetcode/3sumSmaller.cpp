// This works. Tested.
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() <= 2) return 0;
        int ct = 0; 
        sort(nums.begin(), nums.end());
        
        for (int L = 0, len = nums.size(); L < len - 2; ++ L) {
            // It's asking for index triplets, not unique value triplets.
            //if (L > 0 && nums[L] == nums[L - 1]) ++ L; 
            int M = L + 1, R = len - 1;
            
            while(M < R){
                if(nums[L] + nums[M] + nums[R] < target){
                    ct += R - M;
                    ++ M;
                }
                else{
                    -- R;
                }
            }
        }
        
        return ct;
    }
};

/**
3Sum Smaller 
Difficulty: Medium

Given an array of integers nums and a target, find the number of triplets that 
satisfy the condition nums[i] + nums[j] + nums[k] < target, where i != j != k.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
 */
