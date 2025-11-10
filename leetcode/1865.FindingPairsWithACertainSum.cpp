class FindSumPairs {
    vector<int> v1, v2;
    map<int, int> map;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
        for (int n : nums2) ++ map[n];
    }
    
    void add(int index, int val) {
        map[v2[index]] --;
        v2[index] += val;
        map[v2[index]] ++;
    }
    
    int count(int tot) {
        int ct = 0;
        for (int n : v1) {
            ct += map[tot - n];
        }
        return ct;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */


/**
1865. Finding Pairs With a Certain Sum
Medium

You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

    Add a positive integer to an element of a given index in the array nums2.
    Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).

Implement the FindSumPairs class:

    FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
    void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
    int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.
 */
