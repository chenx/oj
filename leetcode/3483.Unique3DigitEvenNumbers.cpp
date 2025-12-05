// Try all permutations.
// Time: O(n!)
class Solution3 {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> nums;
        sort(digits.begin(), digits.end());
        do {
            if (digits[0] != 0 && digits[2] % 2 == 0) {
                int val = digits[0] * 100 + digits[1] * 10 + digits[2];
                nums.insert(val);
            }
        } while (std::next_permutation(digits.begin(), digits.end()));
        return nums.size();
    }
};


// Use the iterative version of nextPermutation.
// Works.
class Solution2 {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> nums;
        sort(digits.begin(), digits.end());
        do {
            if (digits[0] != 0 && digits[2] % 2 == 0) {
                int val = digits[0] * 100 + digits[1] * 10 + digits[2];
                nums.insert(val);
            }
        } while (nextPermutation(digits));

        return nums.size();
    }

    bool nextPermutation(vector<int>& nums) {
       int n = nums.size();

       int i, j;
       // Find first i, nums[i] < nums[i+1]
       for (i = n-2; i >= 0 && nums[i] >= nums[i+1]; -- i) ;
       if (i == -1) {
           reverse(nums.begin(), nums.end());
           return false;
       }

       // Find first item from right, nums[i] < nums[j]
       for (j = n-1; nums[i] >= nums[j]; --j) ;
       swap(nums[i], nums[j]);
       reverse(nums.begin() + i + 1, nums.end());
       return true;
   }
};

// Use the recursive version of getPermutations.
// Times out for large input.
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> nums;
        vector<vector<int>> permutations;
        getPermutations(digits, 0, permutations);
        for (auto& permutation : permutations) {
            if (permutation[0] != 0 && permutation[2] % 2 == 0) {
                int val = permutation[0] * 100 + permutation[1] * 10 + permutation[2];
                nums.insert(val);
            }
        }

        return nums.size();
    }

    void getPermutations(vector<int>& digits, int pos, vector<vector<int>>& result) {
        if (pos == digits.size()) {
            result.push_back(digits);
            return;
        }

        for (int i = pos; i < digits.size(); ++ i) {
            swap(digits[i], digits[pos]);
            getPermutations(digits, pos + 1, result);
            swap(digits[i], digits[pos]);
        }
    }
};


/**
3483. Unique 3-Digit Even Numbers
Easy

You are given an array of digits called digits. Your task is to determine the number of distinct 
three-digit even numbers that can be formed using these digits.

Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.

 

Example 1:

Input: digits = [1,2,3,4]

Output: 12

Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 
234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy 
of the digit 2.

Example 2:

Input: digits = [0,2,2]

Output: 2

Explanation: The only 3-digit even numbers that can be formed are 202 and 220. Note that the digit 
2 can be used twice because it appears twice in the array.

Example 3:

Input: digits = [6,6,6]

Output: 1

Explanation: Only 666 can be formed.

Example 4:

Input: digits = [1,3,5]

Output: 0

Explanation: No even 3-digit numbers can be formed.
 */
