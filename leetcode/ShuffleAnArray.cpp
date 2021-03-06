class Solution {
    vector<int> arr;
public:
    Solution(vector<int> nums) {
        arr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums = arr;
        
        for (int i = nums.size(); i >= 1; -- i) {
            int index = std::rand() % i;
            swap(nums[i - 1], nums[index]);
        }
        
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    // This works too.
    vector<int> shuffle2() {
        vector<int> nums = arr;
        
        for (int n = nums.size(), i = n - 1; i >= 0; -- i) {
            int index = std::rand() % (i + 1);
            swap(nums[i], nums[index]);
        }
        
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
 
 
 /**
 384. Shuffle an Array
 
    Difficulty: Medium

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();

  */
