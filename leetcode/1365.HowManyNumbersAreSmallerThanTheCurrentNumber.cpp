// From: https://algo.monster/liteproblems/1365
// Time: O(nlogn)
// Space: O(n)
class Solution3 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Create a copy of the original array for sorting
        vector<int> sortedArray = nums;
      
        // Sort the copied array in ascending order
        sort(sortedArray.begin(), sortedArray.end());
      
        // For each element in the original array, find how many elements are smaller
        for (int i = 0; i < nums.size(); ++i) {
            // Use binary search to find the first occurrence of nums[i] in sorted array
            // The index of first occurrence equals the count of smaller elements
            nums[i] = lower_bound(sortedArray.begin(), sortedArray.end(), nums[i]) - sortedArray.begin();
        }
      
        // Return the modified array containing counts of smaller elements
        return nums;
    }
};


// Time: O(nlogn)
// Space: O(n)
class Solution2 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> nums2 = nums;
        sort(nums.begin(), nums.end());

        map<int, int> smallerNumCount;
        int count = 0, numCount = 0, cur = nums[0];
        for (int num : nums) {
            if (num == cur) {
                ++ numCount;
            } else {
                smallerNumCount[cur] = count;
                cur = num;
                count += numCount;
                numCount = 1;  // Note: 1
            }
        }
        smallerNumCount[cur] = count;

        vector<int> result;
        for (int num : nums2) result.push_back(smallerNumCount[num]);
        return result;
    }
};


// Maybe the best solution so far.
// Time: O(nlogn), map insert in logn
// Space: O(n)
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> numMap;
        for (int num : nums) numMap[num] ++;

        int count = 0;
        for (auto [num, ct] : numMap) {
            numMap[num] = count;
            count += ct;
        }

        vector<int> result;
        for (int num : nums) result.push_back(numMap[num]);
        return result;
    }
};


/**
1365. How Many Numbers Are Smaller Than the Current Number
Easy

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. 
That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
 */
