//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/13/2012
// @Last modified: 12/13/2012
//

struct compStr
{
    bool operator()(const char* a, const char* b) const
    {
         return strcmp(a, b) < 0;
    }
};

class Solution {
public:
    // O(n^3).
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<vector<int> > sum3;
        set<char *, compStr> hash;
        char hash_val[50];
        sort(num.begin(), num.end());
        
        int i, len = num.size(), len3;
        for (i = 0; i < len - 3; i ++) {
            sum3 = threeSum(num, i + 1, num[i], target);
            if ((len3 = sum3.size()) > 0) {
                for (int j = 0; j < len3; j ++) {
                    vector<int> v(4);
                    v[0] = num[i], v[1] = sum3[j][0], v[2] = sum3[j][1], v[3] = sum3[j][2];
                    
                    sprintf(hash_val, "%d_%d_%d_%d", v[0], v[1], v[2], v[3]);
                    if (hash.find(hash_val) == hash.end()) {
                        hash.insert(strdup(hash_val));
                        result.push_back(v);
                    }
                }
            }
        }
        return result;
    }
    
    
    vector<vector<int> > threeSum(vector<int> &num, int left, int v1, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int len = num.size();
        int sum;
        set<char *, compStr> hash;
        char hash_val[40];
        
        for (int L = left; L < len - 2; L ++) {
            // search [L+1, len - 1] for 2 numbers whose sum = -num[L].
            for (int M = L + 1, R = len - 1; M < R; ) {
                sum = num[M] + num[R] + num[L] + v1;
                if (sum == target) {
                    sprintf(hash_val, "%d_%d_%d", num[L], num[M], num[R]);
                    if (hash.find(hash_val) == hash.end()) { 
                        hash.insert(strdup(hash_val));
                        
                        vector<int> v(3);
                        v[0] = num[L], v[1] = num[M], v[2] = num[R];
                        result.push_back(v);
                    }
                    
                    M ++; // R -- also gets it all right.
                } else if (sum < target) {
                    M ++;
                } else {
                    R --;
                }
            }
        }
        return result;
    }  
    
};


// This one works. This uses the new threeSum function, and don't use the hash.
class Solution2 {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        int len = num.size();
        if (len < 4) return ans;
        
        sort(num.begin(), num.end());
        
        for (int i = 0; i < len - 3; ++ i) { // first num: num[i].
            vector<vector<int> > sum3 = threeSum(num, i+1, target - num[i]);
            for (int j = 0; j < sum3.size(); ++ j) {
                vector<int> v(4);
                v[0] = num[i];
                v[1] = sum3[j][0];
                v[2] = sum3[j][1];
                v[3] = sum3[j][2];
                if (find(ans.begin(), ans.end(), v) == ans.end()) {
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
    
    vector<vector<int> > threeSum(vector<int> &num, int left, int target) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int len = num.size();
        int sum;
        
        for (int L = left; L < len - 2; L ++) {
            // search [L+1, len - 1] for 2 numbers whose sum = -num[L].
            for (int M = L + 1, R = len - 1; M < R; ) {
                sum = num[M] + num[R] + num[L] - target;
                if (sum == 0) {
                    vector<int> x = getV(num[L], num[M], num[R]);
                    if (find(result.begin(), result.end(), x) == result.end()) {
                        result.push_back(x);
                    }
                    
                    M ++; // R -- also gets it all right.
                } else if (sum < 0) {
                    M ++;
                } else {
                    R --;
                }
            }
        }
        return result;
    }  
    
    
    vector<int> getV(int a, int b, int c) {
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        return v;
    }
};