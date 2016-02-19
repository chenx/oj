// Works too. Tested. By: XC
// This is more clear than Solution.
class Solution2 {
public:
    string rangeToStr(vector<int> &nums, int start, int end) {
         return (start == end) ? to_string(nums[start]) : 
                (to_string(nums[start]) + "->" + to_string(nums[end]));
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int L = 0, len = nums.size();
        if (len == 0) return ans;
        
        for (int i = 1; i < len; ++ i) {
            if (nums[i] > nums[i-1] + 1) {
                ans.push_back( rangeToStr(nums, L, i-1) );
                L = i;
            }
        }
        
        ans.push_back( rangeToStr(nums, L, len-1) );

        return ans;
    }
};


#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// This works.
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) return ans;
        
        int start = 0, end = 0;
        for (int i = 1, n = nums.size(); i < n; ++ i) {
            if (nums[i] == nums[i-1] + 1) {
                end = i;
            }
            else {
                ans.push_back( rangeToStr(nums, start, end) );
                start = end = i;
            }
        }
        
        ans.push_back( rangeToStr(nums, start, end) );
        
        return ans;
    }    
    
    string rangeToStr(vector<int> &nums, int start, int end) {
         return (start == end) ? (to_string(nums[start]) + "") : 
                (to_string(nums[start]) + "->" + to_string(nums[end]));
    }
    
    // C++0x introduces std::stoi (and variants for each numeric type) and std::to_string, 
    // the counterparts of the C atoi and itoa but expressed in term of std::string.
    string to_string( int Number ) {
        ostringstream ss;
        ss << Number;
        return ss.str();
    }    
};

void dump(vector<int> & v) {
    for (int i = 0, n = v.size(); i < n; ++ i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    Solution so;
    int input[] = {1,2,4};
    vector<int> nums;
    for (int i = 0, n = sizeof(input) / sizeof(int); i < n; ++ i) {
        nums.push_back(input[i]);
    }
    dump(nums);

    vector<string> ans = so.summaryRanges(nums);
    
    for (int i = 0, n = ans.size(); i < n; ++ i) {
        cout << ans[i] << " ";
    }
    cout << endl;
        
    return 0;
}


/*
Summary Ranges

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
 */
