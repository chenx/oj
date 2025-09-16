/*
 * Solution from: http://blog.sina.com.cn/s/blog_b9285de20101iqar.html
 * Adapted from the Java version above.
 *
 * Idea: use hash table's O(1) access. 
 * Insert all elements into a hash table. Then for each element, 
 * search in 2 directions for consecutive elements, if found, increase count
 * and remove the element.
 * 
 * unordered_set: C++2011, insert(), erase(), find().
 *
 * @By: X.C.
 * @On: 2/18/2013
 */

class Solution5 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) s.insert(num);

        int maxLen = 0;
        while (!s.empty()) {
            int n = *s.begin();
            s.erase(n);
            int len = 1;
            for (int i = n - 1; s.contains(i); -- i) { 
                s.erase(i);
                ++ len;
            }
            for (int i = n + 1; s.contains(i); ++ i) { 
                s.erase(i);
                ++ len;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

// Works. Tested. Same as Solution3, just shorter. But Solution3 is easier to understand.
class Solution4 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto n: nums) s.insert(n);
        
        int maxLen = 0;
        while (! s.empty()) {
            maxLen = max(maxLen, getMaxLen(s));
        }
        
        return maxLen;
    }
    
    int getMaxLen(unordered_set<int> &s) {
        int n = *s.begin(), len = 0;

        // Note there ++i, --i should come last.
        for (int i = n; s.count(i); ++ len, s.erase(i), ++ i) ;
        for (int i = n - 1; s.count(i); ++ len, s.erase(i), -- i) ;
        
        return len;
    }
};


// Works too. Tested.
class Solution3 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto n: nums) s.insert(n);
        
        int maxLen = 0;
        while (! s.empty()) {
            maxLen = max(maxLen, getMaxLen(s));
        }
        
        return maxLen;
    }
    
    int getMaxLen(unordered_set<int> &s) {
        int n = *s.begin(), len = 1;
        s.erase(n);

        // s.count(i) can be replaced by "s.find(i) != s.end()" Or "s.contains(i)".
        // The "contains()" function in unorder_set or set is available since C++20.
        for (int i = n + 1; s.count(i); ++ i) {
            s.erase(i);
            ++ len;
        }
        
        for (int i = n - 1; s.count(i); -- i) {
            s.erase(i);
            ++ len;
        }
        
        return len;
    }
};


// This works too. 11/11/2014
class Solution2 {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> hash;
        for (int i = 0; i < num.size(); ++ i) {
            hash.insert(num[i]);
        }
        
        int len = 0;
        while (! hash.empty()) {
            len = max(len, getLen(hash, * hash.begin()));
        }
        return len;
    }
    
    int getLen(unordered_set<int> &hash, int v) {
        int len = 1;
        hash.erase(v); // also can do: hash.erase(hash.find(v));
        
        for (int i = v-1; hash.find(i) != hash.end(); -- i) {
            ++ len;
            hash.erase(i);
        }
        for (int i = v+1; hash.find(i) != hash.end(); ++ i) {
            ++ len;
            hash.erase(i);
        }
        
        return len;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s;
        int ans = 0;
        
        int len = num.size();
        for (int i = 0; i < len; ++ i) s.insert(num[i]);
        
        for (int i = 0; i < len; ++ i) {
            ans = max(ans, getCount(s, num[i], -1) + getCount(s, num[i]+1, 1));
        }
        
        return ans;
    }
    
    // search in 2 directions. each element used once. each access is O(1).
    int getCount(unordered_set<int> &s, int v, int inc) {
        int ct = 0;
        while (s.find(v) != s.end()) {
            s.erase(v);
            ++ ct;
            v += inc;
        }
        return ct;
    }
};

/*
Problem:
        
Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 
 */

