// Works. Same as Solution3 but simplified.
// O( 5^high.length() ), i.e., O(5^log(n)).
class Solution4 {
public:
    int strobogrammaticInRange(string low, string high) {
        if (! le(low, high)) return 0; // <-- note this!

        int ct = 0;
        getCount(low, high, "", ct);
        getCount(low, high, "0", ct);
        getCount(low, high, "1", ct);
        getCount(low, high, "8", ct);
        return ct;
    }

    void getCount(string low, string high, string s, int &ct) {
        if (high.length() < s.length()) return;

        if (le(low, s) && le(s, high) && valid(s)) ++ ct;

        getCount(low, high, "0" + s + "0", ct);
        getCount(low, high, "1" + s + "1", ct);
        getCount(low, high, "6" + s + "9", ct);
        getCount(low, high, "8" + s + "8", ct);
        getCount(low, high, "9" + s + "6", ct);
    }

    bool valid(string s) {
        return s == "0" || (s.length() > 0 && s[0] != '0');
        // or:
        // return s.length() == 1 || (s.length() > 1 && s[0] != '0');
    }
    
    bool le(string a, string b) {
        return stoi(a) <= stoi(b);
    }
};

// Should work. Tested locally against Solution.
class Solution3 {
public:
    // compare s1, s2. returns true if s1 <= s2.
    bool le(string s1, string s2) {
        return stoi(s1) <= stoi(s2);
    }

    void getCount(const string& low, const string& high, string t, int & cnt) {
        if (high.length() < t.length()) return;

        if (le(low, t) && le(t, high)) {
            if (t.length() == 1 || (t.length() > 1 && t[0] != '0')) ++ cnt;
        }

        for (int i = 0; i < nums.size(); ++ i) {
            getCount(low, high, nums[i][0] + t + nums[i][1], cnt);
        }
    }

    int strobogrammaticInRange(string low, string high) {
        if (! le(low, high)) return 0;

        int cnt = 0;
        getCount(low, high, "", cnt);
        getCount(low, high, "0", cnt);
        getCount(low, high, "1", cnt);
        getCount(low, high, "8", cnt);

        return cnt;
    }

    vector<vector<string> > nums = {
        {"0", "0"}, {"1", "1"}, {"6", "9"}, {"8", "8"}, {"9", "6"}
    };
    
    /*
    int stoi(string s) {
        stringstream ss(s);
        int val;
        ss >> val;
        return val;
    }
    
    Solution() {
        vector<string> v(2);
        v[0] = "0", v[1] = "0"; nums.push_back(v);
        v[0] = "1", v[1] = "1"; nums.push_back(v);
        v[0] = "6", v[1] = "9"; nums.push_back(v);
        v[0] = "8", v[1] = "8"; nums.push_back(v);
        v[0] = "9", v[1] = "6"; nums.push_back(v);
    }*/
};


// Works too. Tested.
// From: https://leetcode.com/discuss/53191/c-accepted-solution
class Solution2 {
public:
    bool compare(string s1, string s2) {
        if (s1.length() != s2.length())
            return s1.length() <= s2.length();
    
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] < s2[i]) return true;
            else if (s1[i] > s2[i]) return false;
        }
    
        return true;
    }
    
    int strobogrammaticInRange(const vector<pair<char, char>>& nums, const string& low, const string& high, string t, int cnt) {
        if (high.length() < t.length())
            return cnt;
        if (compare(low, t) && compare(t, high)) 
            if (t.length() == 1 || t.length() > 1 && t.front() != '0')
                cnt++;
    
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) 
            cnt = strobogrammaticInRange(nums, low, high, string(1, iter->first) + t + string(1, iter->second), cnt);
    
        return cnt;
    }
    
    int strobogrammaticInRange(string low, string high) {
        if (!compare(low, high)) return 0;
    
        vector<pair<char, char>> nums = { { '0', '0' }, { '1', '1' }, { '6', '9' }, { '8', '8' }, { '9', '6' } };
    
        int cnt = strobogrammaticInRange(nums, low, high, "", 0);
        cnt = strobogrammaticInRange(nums, low, high, "0", cnt);
        cnt = strobogrammaticInRange(nums, low, high, "1", cnt);
        cnt = strobogrammaticInRange(nums, low, high, "8", cnt);
    
        return cnt;
    }
};

// Works. Tested. 
// Idea:
// The idea is pretty straightforward! If we try to generalize how many strobo 
// numbers are there with length = N, we can obtain the following formula:
//
// total(1) = 3 // {"0", "1", "8"}
// total(2) = 4 // {"11", "69", "88", "96"}
// for (n >= 3) 
//     if (n & 1) { // odd
//          total(n) = total(n-1) * 3  // insert [0, 1, 8] into the middle position of
//                                     // each strobogrammatic numbers with length = n-1
//     else {
//          total(n) = total(n-2) * 5 // insert [00, 11, 69, 88, 96] into the middle 
//                                    // position of each strobogrammatic numbers with length = n-1
//     }
// Therefore, we can quickly count out how many strobogrammatic numbers are 
// there in certain length. For the edge case when i=low.size() and 
// i=high.size(), we kind of use the brutal force solution to generate all 
// the strobogrammatic numbers with that length and then prune them off. 
// From: https://leetcode.com/discuss/62710/c-solution-reuse-strobogrammatic-ii-with-math
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int l=low.size(), u=high.size(), count=0;
        for (int i=l; i<=u; i++) {
            if (i == l || i == u) {
                count += calcInRange(i, low, high);            
            } else {
                count += calcWithLength(i);   
            }
        }
        return count;
    }
private:
    vector<string> stroboHelper(int len) {
        vector<string> result, Middle, strobos;
        vector<string> oddMiddle = {"0", "1", "8"};
        vector<string> evenMiddle = {"11", "69", "88", "96"};
        if (len == 1)
            return oddMiddle;
        else if (len == 2)
            return evenMiddle;
        if (len&1) { // odd
            strobos = stroboHelper(len-1);
            Middle = oddMiddle;
        } else { // even
            strobos = stroboHelper(len-2);
            evenMiddle.insert(evenMiddle.begin(), "00");
            Middle = evenMiddle;
        }
        int mid = (len-1)/2;
        for (auto &middle : Middle) {
            for (auto strobo : strobos) {
                strobo.insert(mid, middle);
                result.push_back(strobo);
            }
        }
        return result;
    }
    // true if a <= b
    bool lessThan(string &a, string &b) {
        if (a.size() != b.size())
            return a.size() < b.size();
        for (int i=0; i<a.size(); i++) {
            if (a[i] < b[i])
                break;
            else if (a[i] > b[i])
                return false;
        }
        return true;
    }
    int calcInRange(int len, string &low, string &high) {
        int count = 0;
        vector<string> strobos = stroboHelper(len);
        for (auto &strobo : strobos)
            if (lessThan(low, strobo) && lessThan(strobo, high))
                count ++;
        return count;
    }
    int calcWithLength(int len) {
        if (len == 1)
            return 3;
        else if (len == 2)
            return 4;
        else
            return len&1 ? calcWithLength(len-1)*3 : calcWithLength(len-2)*5;
    }
};


/**
Strobogrammatic Number III
Difficulty: Hard

A strobogrammatic number is a number that looks the same when 
rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers 
that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 
96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high 
numbers are represented as string.
 */
