class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
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