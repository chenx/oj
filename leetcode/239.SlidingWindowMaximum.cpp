// Invariant: nums[q.back()] is alwasy the largest number of the current window.
// Best answer so far.
class Solution3 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;

        int i = 0;
        for (; i < k; ++ i) {
            while (! q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
        }
        for (; i < nums.size(); ++ i)    {
            ans.push_back(nums[q.front()]);
            if (i - q.front() == k) q.pop_front();
            
            while (! q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
        }
        if (! q.empty()) ans.push_back(nums[q.front()]);
        return ans;
    }
};


// Works too. Slightly better than Solution.
// Note: see code comments.
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> Q;  // deque
        
        for (int i = 0; i < k; ++ i) {
            while (! Q.empty() && nums[i] >= nums[Q.back()]) Q.pop_back();
            Q.push_back(i);
        }
        
        for (int i = k, len = nums.size(); i < len; ++ i) {
            ans.push_back(nums[Q.front()]);   // Q.front().
            //while (! Q.empty() && (i - Q.front() >= k)) Q.pop_front();
            while (! q.empty() && i >= q.front() + k) q.pop_front(); // this is more clear.
            while (! Q.empty() && nums[i] >= nums[Q.back()]) Q.pop_back();   // >= // order of these 2 while doesn't matter.
            Q.push_back(i);
        }
        if (! Q.empty()) ans.push_back(nums[Q.front()]);   // end of loop processing
        
        return ans;
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> Q;
        int len = nums.size(), i;
        
        for (i = 0; i < k; ++ i) {
            while (! Q.empty() && nums[i] >= nums[Q.back()]) Q.pop_back();
            Q.push_back(i);
        }

        for (; i < len; ++ i) {
            ans.push_back(nums[Q.front()]);
            while (! Q.empty() && nums[i] >= nums[Q.back()]) Q.pop_back();
            while (! Q.empty() && i - Q.front() >= k) Q.pop_front();
            Q.push_back(i);
        }
        if (! Q.empty()) ans.push_back(nums[Q.front()]);
        
        return ans;
    }
};

/**
239. Sliding Window Maximum
Difficulty: Hard

Given an array nums, there is a sliding window of size k 
which is moving from the very left of the array to the 
very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

Hint:

    How about using a data structure such as deque (double-ended queue)?
    The queue size need not be the same as the window’s size.
    Remove redundant elements and the queue should store only elements that 
    need to be considered.

 */
