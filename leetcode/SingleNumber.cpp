// Works too. Tested.
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int v = 0;
        for (int n : nums) v ^= n;
        return v;
    }
};

class Solution {
public:
    int singleNumber(int A[], int n) {
        int x = 0;
        for (int i = 0; i < n; ++ i) {
            x ^= A[i];
        }
        
        return x;
    }
};

/*


Single Number
Total Accepted: 4471 Total Submissions: 9907

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/
