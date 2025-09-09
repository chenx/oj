// Works. add() - O(n), find() - O(1).
class TwoSum8 {
public:
    TwoSum() {}
    
    void add(int number) {
        for (int n : nums) sums.insert(number + n);
        nums.insert(number);
    }
    
    bool find(int value) {
        return sums.count(value) > 0;
    }

private:
    unordered_set<int> nums;
    unordered_set<int> sums;
};

// Works. add() - O(N), find() - O(1).
class TwoSum7 {
public:
    TwoSum() {}
    
    void add(int number) {
        for (int i = 0; i < v.size(); i ++) {
            s.insert(number + v[i]);
        }
        
        if (std::find(v.begin(), v.end(), number) == v.end()) {
            v.push_back(number);
        }
    }
    
    bool find(int value) {
        return s.find(value) != s.end();
    }

private:
    vector<int> v;
    unordered_set<int> s;
};

// Should work. Tested locally, not on lc.
class Solution6 {
    map<int, int> m; // value, count
public:
    void add(int number) {
        m[number] ++;
    }
    bool find(int value) {
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++ it) {
            int v = it->first;

            int ct = (value == 2 * v ? 2 : 1);
            //if (m.find(value - v) != m.end() && m[value - v] >= ct) return true;
            if (m.count(value - v) && m[value - v] >= ct) return true;
        }
        return false;
    }
};

// Should work. Note tested.
class TwoSum5 {
public:
    void add(int number) {
        ++ nums[number];
    }
    
    bool find(int value) {
        for (auto v : nums) {
            int val = v.first, ct = v.second;
            if (value == 2*val && ct >= 2) return true;
            else if (nums.find(value - val) != nums.end()) return true;
        }
        return false;
    }
private:
    unordered_map<int, int> nums; // (num, count)
};

// This works too! Tested.
class TwoSum4 {
public:
    void add(int number) {
        ++ nums[number];
    }
    
    bool find(int value) {
        for (unordered_map<int, int>::iterator it = nums.begin(); 
                it != nums.end(); ++ it) {
            int i = it->first; //(*it).first; // key, inserted number.
            int count = (value == 2 * i) ? 2 : 1;
            if (nums.find(value - i) != nums.end() && nums[value - i] >= count) return true;
            
            // note: code below fails. Because if x does not exist in nums, 
            // use of nums[x] will insert x into nums where value nums[x] = -1. 
            // This changes the nums map and it will fail.
            //if (nums[value - i] >= count) return true;
        }
        
        return false;
    }
    
private:
    unordered_map<int, int> nums;  // store values that are sum of 2 numbers added.
};


// This works. Tested. 
// From: https://leetcode.com/discuss/59376/fast-and-concise-c-multiset-solution
/**
 * Multiple-key set
 * Multisets are containers that store elements following a specific order, 
 * and where multiple elements can have equivalent values.
 * 
 * In a multiset, the value of an element also identifies it (the value is 
 * itself the key, of type T). The value of the elements in a multiset 
 * cannot be modified once in the container (the elements are always const), 
 * but they can be inserted or removed from the container.
 * 
 * Internally, the elements in a multiset are always sorted following a 
 * specific strict weak ordering criterion indicated by its internal 
 * comparison object (of type Compare).
 * 
 * multiset containers are generally slower than unordered_multiset 
 * containers to access individual elements by their key, but they 
 * allow the direct iteration on subsets based on their order.
 * 
 * Multisets are typically implemented as binary search trees.
 */
class TwoSum3 {
    unordered_multiset<int> nums;
public:
    void add(int number) {
        nums.insert(number);
    }
    bool find(int value) {
        for (int i : nums) {
            int count = (value == 2 * i) ? 2 : 1;
            if (nums.count(value - i) >= count) {
                return true;
            }
        }
        return false;
    }
};


// Should work. But times out for large input. Tested.
class TwoSum2 {
public:
    void add(int number) {
        // a little optimization, to avoid adding repeated number.
        if (std::find(nums.begin(), nums.end(), number) != nums.end()) {
            sumFound.insert(number * 2);
            return;
        }
        
        nums.push_back(number);
        if (nums.size() == 1) return;
        
        for (int i = 0, len = nums.size() - 1; i < len; ++ i) {
            int v = nums[i] + number;
            if (sumFound.find(v) == sumFound.end()) {
                sumFound.insert(v);
            }
        }
    }
    
    bool find(int value) {
        return sumFound.find(value) != sumFound.end();
    }

private:
    vector<int> nums; // store numbers added.
    unordered_set<int> sumFound;  // store values that are sum of 2 numbers added.
};


#include <iostream>
#include <vector>
#include <set>
using namespace std;

// This fails.
class TwoSum {
public:
        void add(int number) {
            nums.push_back(number);
        }

        bool find(int value) {
            if (sumFound.find(value) != sumFound.end()) return true;
            
            set<int> m; // why use this? 
            for (int i = 0; i < nums.size(); ++ i) {
                if (m.find(nums[i]) == m.end()) {
                    m.insert(value - nums[i]);
                }
                else {
                    sumFound.insert(value);
                    break;
                }
            }

            return sumFound.find(value) != sumFound.end();
        }

private:
    vector<int> nums; // store numbers added.
    set<int> sumFound;  // store values that are sum of 2 numbers added.
};

void ok(bool isOk, string s) {
    if (isOk) cout << "ok: " << s << endl;
    else cout << "Not ok: " << s << endl;
}

void test() {
    TwoSum ts;
    ok(ts.find(2) == false, "2 not exist");

    ts.add(1);
    ts.add(0);
    ts.add(2);
    ok(ts.find(2) == true, "2 exists");
}

int main() {
    test();
    return 0;
}

/**
Two Sum III - Data structure design
Difficulty: Easy

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
 */
