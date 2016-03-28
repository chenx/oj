// Works. Tested, by comparing result with Solution.
// More clear on using isFirstLeve, instead of m. Better than Solution.
class Solution3 {
public:
    vector<string> findStrobogrammatic(int n) {
        return find(true, n);
    }

    vector<string> find(bool isFirstLevel, int n) {
        vector<string> v;
        if (n <= 0) return {""}; // or vector<string>({""});
        if (n == 1) return {"0", "1", "8"};

        vector<string> t = find(false, n - 2);

        for (int i = 0; i < t.size(); ++ i) {
            string s = t[i];
            if (! isFirstLevel) { v.push_back("0" + s + "0"); }
            v.push_back("1" + s + "1");
            v.push_back("6" + s + "9");
            v.push_back("8" + s + "8");
            v.push_back("9" + s + "6");
        }

        return v;
    }
};


// Should work. Not tested. Modified from Solution.
class Solution2 {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(true, n);
    }
    
    vector<string> helper(bool first, int n) {
        if (n == 0) return {""};
        if (n == 1) return {"0", "1", "8"};
        
        vector<string> v = helper(false, n - 2), ans;
        
        for (int i = 0; i < v.size(); ++ i) {
            if (! first) ans.push_back("0" + v[i] + "0");
            ans.push_back("1" + v[i] + "1");
            ans.push_back("8" + v[i] + "8");
            ans.push_back("6" + v[i] + "9");
            ans.push_back("9" + v[i] + "6");
        }
        
        return ans;
    }
};

// Works. Tested. 
// From: https://leetcode.com/discuss/85991/14-lines-concise-and-easy-understand-c-solution
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n , n);
    }
    
    vector<string> helper(int m, int n){
        if(m == 0) return vector<string>({""});
        if(m == 1) return vector<string>({"0", "1", "8"});
        
        vector<string> tmp = helper(m - 2, n), res;
        
        for(int i = 0; i < tmp.size(); i++){
            if(m < n) res.push_back("0" + tmp[i] + "0");
            res.push_back("1" + tmp[i] + "1");
            res.push_back("6" + tmp[i] + "9");
            res.push_back("8" + tmp[i] + "8");
            res.push_back("9" + tmp[i] + "6");
        }
        return res;
    }
};

/**
Strobogrammatic Number II
Difficulty: Medium

A strobogrammatic number is a number that looks the same when 
rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].

Hint:

Try to use recursion and notice that it should recurse with 
n - 2 instead of n - 1.
 */
