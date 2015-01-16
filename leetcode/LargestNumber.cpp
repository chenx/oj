#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

// Solution 2. This works too.
// Function to_string() convert int to string.
// See: http://www.cplusplus.com/reference/string/to_string/
// Use header: #include <string>
// In C++11, also in GCC4.5, compile with -std=c++0x flag.
bool cmp2(const string &a, const string &b) {
    return a + b > b + a;
}
class Solution2 {
public:
    string largestNumber(vector<int> &num) {
        vector<string> nums;
        for (int i = 0; i < num.size(); ++ i) {
            nums.push_back( to_string( num[i] ) );
        }
        
        sort(nums.begin(), nums.end(), cmp2);
        
        string s = "";
        for (int i = 0, n = nums.size(); i < n; ++ i) {
            if (s == "" && nums[i] == "0" && i < n-1) continue;
            s += nums[i];
        }
        
        return s;
    }
};

// Solution 1. This works.
// Solution starts.

string int2str(int n) {
    stringstream o;
    o << n;
    return o.str();
}

bool cmp(int a, int b) {
    string s1 = int2str(a);
    string s2 = int2str(b);
    string x = s1 + s2, y = s2 + s1;
    return x > y;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), cmp); // this is the key.
                
        string s = "";
        for (int i = 0, n = num.size(); i < n; ++ i) {
            if (s == "" && num[i] == 0 && i < n-1) continue; // avoid "00" or "012" etc.
            s += int2str(num[i]);
        }
        
        return s;
    }
};

// Solution ends.

int main() {
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    
    Solution so;
    cout << so.largestNumber(num) << endl;
    
    return 0;
}

// Note, convert string to int:
double str2int(string s) {
    int n;
    istringstream iss(s);
    iss >> n;
    return n;
}

/**
Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
 */
