// From: https://leetcode.com/problems/sliding-window-median/editorial/
// Use two multisets. 
// One can see that multisets are a great way to keep elements sorted while providing efficient access to the first 
// and last elements. Inserting and deleting arbitrary elements are also fairly efficient operations in a multiset.
// Time complexity: O((n−k)⋅6⋅logk)≈O(nlogk).
// Space complexity: O(k) 

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        multiset<int> lo, hi;

        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) { //remove outgoing element
                int out = nums[i - k]; // the element going out.
                if (out <= *lo.rbegin()) lo.erase(lo.find(out));
                else hi.erase(hi.find(out));
            }

            lo.insert(nums[i]); // insert incoming element

            // balance the sets
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));

            if (lo.size() < hi.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }

            // get median
            if (i >= k - 1) {
                medians.push_back(k & 1 ? *lo.rbegin() : 
                                          ((double)(*lo.rbegin()) + (double)(*hi.begin())) * 0.5);
            }
        }

        return medians;
    }
};


/**
480. Sliding Window Median
Hard

The median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value. So the median is the mean of the two middle values.

    For examples, if arr = [2,3,4], the median is 3.
    For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.

You are given an integer array nums and an integer k. There is a sliding window of size k 
which is moving from the very left of the array to the very right. You can only see the k 
numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the 
actual value will be accepted.
 */
