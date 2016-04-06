// Works too. Use method of MajorityElement_II.cpp to simplify code.
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int ct = 0, e = -1; // e can be any default value when not exist.
        for (auto n : nums) {
            if (n == e) ++ ct;
            else if (ct == 0) e = n, ct = 1;
            else -- ct;
        }
        
        return e;
    }
};

//
// This works.
//
class Solution {
public:
    int majorityElement(vector<int> &num) {
        if (num.size() == 0) return -1;
        
        int v = num[0];
        int ct = 1;
        for (int i = 1; i < num.size(); ++ i) {
            if (num[i] == v) {
                ++ ct;
            }
            else {
                -- ct;
                if (ct == 0) {
                    v = num[i];
                    ct = 1;
                }
            }
        }
        
        return v;
    }
};

/**
Majority Element 
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
 */
