class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pos = -1;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == 1) {
                if (pos == -1) pos = i;
                else {
                    if (i - pos - 1 < k) return false; // NOTE: i - pos - 1
                    else pos = i;
                }
            }
        }
        return true;
    }
};


/**
1437. Check If All 1's Are at Least Length K Places Away
Easy

Given an binary array nums and an integer k, return true if all 1's are at least k places away 
from each other, otherwise return false.
 */
