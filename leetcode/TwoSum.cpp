//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/12/2012
// @Last modified: 12/13/2012
//

// Be careful of the use of map<int, int>, its iterator, insert, and first/second.
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int, int> s;
        for (int i = 0; i < numbers.size(); i ++) {
            map<int, int>::iterator it = s.find(numbers[i]);
            if (it != s.end()) {
                result.push_back((*it).second + 1);
                result.push_back(i + 1);                    
                //return result;
            }
            else {
                s.insert(pair<int, int>(target - numbers[i], i));
            }
        }
        return result;
    }
};


//
// This also works, and is better in syntax.
//
class Solution2 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ans;
        unordered_map<int, int> ht; // [num, index]
        
        for (int i = 0; i < numbers.size(); ++ i) {
            if (ht.find(numbers[i]) != ht.end()) {
                ans.push_back(ht[numbers[i]] + 1);
                ans.push_back(i+1);
                break;
            }
            else {
                ht[target - numbers[i]] = i;
            }
        }
        
        return ans;
    }
};