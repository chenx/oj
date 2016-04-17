class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        vector<int> ans(2);
        int n = A.size();
        if (n == 0) return ans;
        
        int sum = A[0], maxSum = sum, start0 = 0, start = 0, end = 0;
        for (int i = 1; i < A.size(); ++ i) {
            if (sum < 0) {
                sum = 0;
                start0 = i;  // Note this!
            }
            sum += A[i];
            if (sum > maxSum) {
                maxSum = sum;
                start = start0;  // Note this!
                end = i;
            }
        }
        
        ans[0] = start, ans[1] = end;
        return ans;
    }
};


/**
Continuous Subarray Sum

Given an integer array, find a continuous subarray where the sum of 
numbers is the biggest. Your code should return the index of the first 
number and the index of the last number. (If their are duplicate 
answer, return anyone)

Example

Give [-3, 1, 3, -3, 4], return [1,4].

 */
