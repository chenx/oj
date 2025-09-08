// Works. Adapted from Solution4.
class Solution5 {
public:
    int minPatches(vector<int>& nums, int n) {
        int ct = 0, i = 0;
        long long top = 0;        
        while (top < n) {
            if (i < nums.size() && nums[i] <= top + 1) {
                top += nums[i];
                ++ i;
            } else {
                ++ ct; // patch number: top + 1.
                top = top + (top + 1);
            }
        }

        return ct;
    }
};

// Works. Almost same as Solution3.
class Solution4 {
public:
    int minPatches(vector<int>& nums, int n) {
        int ct = 0, len = nums.size();
        long long top = 0;
        
        for (int i = 0; top < n; ) {
            if (i < len && nums[i] <= top + 1) {
                top += nums[i];
                ++ i;
            }
            else {
                ++ ct; // patch number: top + 1.
                top = top + (top + 1);
            }
        }
        
        return ct;
    }
};

// Works. Basically same as Solution, but written easier to understand.
// Basically there is a gap when nums[index] > top + 1, and need patch.
class Solution3 {
public:
    int minPatches(vector<int>& nums, int n) {
        int size = nums.size(), index = 0, ct = 0;
        long long top = 0;
        while (top < n) {
            if (index < size && nums[index] <= top + 1) { 
                // add nums[index].
                top += nums[index];
                ++ index;
            }
            else { 
                // there is gap now, add number top+1.
                top = 2 * top + 1;
                ++ ct;
            }
        }
        return ct;
    }
};

// Works. From: https://leetcode.com/discuss/83570/simple-c-solution
//
// Basic idea is to check every nid from 1 to n. If number from nums 
// is too large, then we need to patch nid itself, otherwise we can 
// use nums[i]. we know that 1 to nid -1 all meet requirements. 
// Adding nid or nums[i] will extend this range to nid + (nid or nums[i]) - 1. 
// Then we start next check at nid + (nid or nums[i]).
// 
class Solution2 {
public:
    int minPatches(vector<int>& nums, int n) {
        int ret = 0, i = 0;
        long long nid = 1;
        while(nid <= n) {
            if(i >= nums.size() || nums[i] > nid) {
                ret++;
                nid += nid;
            } else {
                nid += nums[i];
                i++;
            }
        }

        return ret;
    }
};

// Works. From: https://leetcode.com/discuss/83145/my-8-ms-o-n-c-code
//
// The basic idea is to use "bound" to save the maximum number that can be 
// generated with nums[0..i-1] and the added numbers (i.e. using nums[0..i-1] 
// and the added numbers, we can generate all the numbers in [1..bound]). 
// If bound is less than n and nums[i] is larger than bound+1, then we need 
// to add bound+1, which extend the maximum number that can be generated to 
// bound*2 +1. If nums[i] is no larger than bound+1, then by add nums[i], 
// we can extend the maximum number that can be generated to bound + nums[i].
//
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int len = nums.size(), i = 0, res = 0;
        long long bound = 0;
        while (bound<n) { // if it does not reach to the end
            if(i<len && nums[i]<=(bound+1)) bound += nums[i++]; 
            // if nums[i] is no larger than bound, then including nums[i] 
            // allow us to generate all the numbers [1.. bound+nums[i]]

            else { ++res; bound= 2*bound+1; }  
            // we need to add a new number bound+1, and that extend the bound to 2*bound+1
        }
        return res;
    }
};

/**
Patching Array
Difficulty: Medium

Given a sorted positive integer array nums and an integer n, 
add/patch elements to the array such that any number in range 
[1, n] inclusive can be formed by the sum of some elements 
in the array. Return the minimum number of patches required.

Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.
 */
