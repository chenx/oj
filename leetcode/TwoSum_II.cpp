// Works. Tested.
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans(2);
    int L = 0, R = numbers.size() - 1;
    while (L < R) {
        int sum = numbers[L] + numbers[R];
        if (sum == target) {
            ans[0] = L + 1, ans[1] = R + 1;
            break;
        }
        else if (sum < target) ++ L;
        else -- R;
    }
    return ans;
}

// Works. Tested.
// From https://leetcode.com/discuss/33192/a-simple-o-n-solution
vector<int> twoSum(vector<int>& numbers, int target) {
    int lo=0, hi=numbers.size()-1;
    while (numbers[lo]+numbers[hi]!=target){
        if (numbers[lo]+numbers[hi]<target){
            lo++;
        } else {
            hi--;
        }
    }
    return vector<int>({lo+1,hi+1});
}

/**
Two Sum II - Input array is sorted 
Difficulty: Medium

Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 
 */
