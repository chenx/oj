//
// http://www.leetcode.com/onlinejudge#
// 3sum.
// @Author: Xin Chen
// @Created on: 12/12/2012
// @Last modified: 12/13/2012
//

// Improved from Solution_good. This is good, and passes all tests.
class Solution_good2 {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int len = num.size();
        int sum;
        
        for (int L = 0; L < len - 2; ++ L) {
            if (L > 0 && num[L] == num[L - 1]) continue;
            // search [L+1, len - 1] for 2 numbers whose sum = -num[L].
            for (int M = L + 1, R = len - 1; M < R; ) {
                sum = num[M] + num[R] + num[L];
                if (sum == 0) {
                    vector<int> x = getV(num[L], num[M], num[R]);
                    if (find(result.begin(), result.end(), x) == result.end()) {
                        result.push_back(x);
                    }
                    
                    ++ M; -- R;
                    while(M < R && num[M] == num[M - 1])  M ++;
                    while(M < R && num[R] == num[R + 1])  R --;
                } else if (sum < 0) {
                    ++ M;
                } else {
                    -- R;
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

// This one works without artificial hash! Just use find() method of <algorithm>:
//     if (find(result.begin(), result.end(), x) == result.end()) { ... }
// well, in most recent version, this will time out.
class Solution_good {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int len = num.size();
        int sum;
        
        for (int L = 0; L < len - 2; L ++) {
            // search [L+1, len - 1] for 2 numbers whose sum = -num[L].
            for (int M = L + 1, R = len - 1; M < R; ) {
                sum = num[M] + num[R] + num[L];
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


// This should work too, but O(n^2log(n)).
class Solution_3 {
public:
   vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        if (num.size() < 3) return ans;
        
        sort(num.begin(), num.end());
        
        for (int L = 0, len = num.size()-2; L < len; ++ L) {
            for (int R = L + 2; R < num.size(); ++ R) {
                //if (num[L] + num[R] > 0 && num[L] > 0) break;
                //if (num[L] + num[R] < 0 && num[R] < 0) break;
                
                int M = b(num, L, R, - (num[L] + num[R]));
                if (M != -1) {
                    vector<int> v(3); 
                    v[0] = num[L]; v[1] = num[M]; v[2] = num[R];
                    if (find(ans.begin(), ans.end(), v) == ans.end()) ans.push_back(v);
                    
                    //while (num[R+1] == num[R]) ++ R;
                }
            }
        }
        
        return ans;
    }
    
    int b(vector<int> &num, int L, int R, int k) {
        while (L < R) {
            int M = L + (R - L)/2;
            if (num[M] == k) return M;
            else if (num[M] < k) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
};


#include <vector>
#include <set>
#include <iostream>
using namespace std;

struct compVec3
{
    bool operator()(const vector<int> a, vector<int> b) const
    {
         if (a[0] != b[0]) return a[0] < b[0];
         if (a[1] != b[1]) return a[1] < b[1];
         return a[2] < b[2];
    }
};

struct compStr
{
    bool operator()(const char* a, const char* b) const
    {
         return strcmp(a, b) < 0;
    }
};

class Solution {
public:
    //    
    // complexity: Time: O(n^2). Space: O(1) other than space to store results.
    // Note: here the hash function is string comparison. 
    // This is a little slow than threeSum_int_hash, but solves its problem of 
    // potential conflict. Note the key is to use a customized compare function
    // for a set of strings.
    //
    // Time on large test set: ~ 560 +- 20 ms.
    //
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int len = num.size();
        int sum;
        set<char *, compStr> hash;
        char hash_val[40];
        
        for (int L = 0; L < len - 2; L ++) {
            // search [L+1, len - 1] for 2 numbers whose sum = -num[L].
            for (int M = L + 1, R = len - 1; M < R; ) {
                sum = num[M] + num[R] + num[L];
                if (sum == 0) {
                    sprintf(hash_val, "%d_%d_%d", num[L], num[M], num[R]);
                    if (hash.find(hash_val) == hash.end()) { 
                        hash.insert(strdup(hash_val)); // must use strdup()!
                        result.push_back(getV(num[L], num[M], num[R]));
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
    
    //
    // complexity: Time: O(n^2). Space: O(1) other than space to store results.
    //
    // Note: to find collision, we used the hash function:
    //     hash_val = num[L] * 200 + num[M] * 20 + num[R];
    // hash value must guarantee each digit does not interfere with other digits.
    // since each digit is in -9 to 9, total range is 19, so next digit should
    // be multiplied by 20 to not to collide with a previous digit.
    // NOTE: this analysis works only when each number is in [-9,9].
    // If x1 + y1 + z1 = 0, x2 + y2 + z2 = 0, it'll be possible that
    // a*x1 + b*y1 + c*z1 = a*x2 + b*y2 + c*z2
    // => x2 = x1 - k(b+c), y2 = y1 + k(a-c), z2 = 0 - x2 - y2.
    // And also satisfy: x1 < y1 < z1, x2 < y2 < z2.
    // For example, (-401,200,201) and (-382,1,381) are such 2 groups in conflict
    // when a = 200, b = 20, c = 1 as in the hash function above.
    // Thus the hash scheme here is not a perfect solution.                    
    //
    // Time on large test set: ~ 380 +- 20 ms.
    //    
    vector<vector<int> > threeSum_int_hash(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int len = num.size();
        int sum, hash_val;
        set<int> hash;
        
        for (int L = 0; L < len - 2; L ++) {
            // search [L+1, len - 1] for 2 numbers whose sum = -num[L].
            for (int M = L + 1, R = len - 1; M < R; ) {
                sum = num[M] + num[R] + num[L];
                if (sum == 0) {
                    // hash value must guarantee each digit does not interfere with other digits.
                    // since each digit is in -9 to 9, total range is 19, so next digit should
                    // be multiplied by 20 to not to collide with a previous digit.
                    hash_val = num[L] * 200 + num[M] * 20 + num[R];
                    if (hash.find(hash_val) == hash.end()) { // if not exist yet, add.
                        hash.insert(hash_val);
                        result.push_back(getV(num[L], num[M], num[R]));
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
    
    // complexity: Time: O(n^2). Space: O(1) other than space to store results.
    // Time on large test set: Time limit exceeded.
    vector<vector<int> > threeSum_better_hash(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int len = num.size();
        int sum, hash_val;
        set<vector<int>, compVec3> hash;
        
        for (int L = 0; L < len - 2; L ++) {
            // search [L+1, len - 1] for 2 numbers whose sum = -num[L].
            for (int M = L + 1, R = len - 1; M < R; ) {
                sum = num[M] + num[R] + num[L];
                if (sum == 0) {
                    vector<int> x = getV(num[L], num[M], num[R]);
                    if (hash.find(x) == hash.end()) {
                        hash.insert(x);
                        result.push_back(getV(num[L], num[M], num[R]));
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
    
        
    // Time on large test set: 800 +- 30 ms
    // This uses binary search, and in theory is faster.
    // but seems it's not the case probably due to large constant factor.
    vector<vector<int> > threeSum_bsearch(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() < 3) return result;
        
        sort(num.begin(), num.end());
        int len = num.size();
        int sum, hash_val;
        set<int> hash;
        int inc = 0, new_sum = 0;
                
        if (num[0] < 0) {
            inc = - num[0];
            for (int i = 0; i < num.size(); i ++) num[i] += inc; 
            // now all elem = 0, new sum should be 3*inc.
            new_sum = 3 * inc;
        }
        
        for (int L = 0, R = len - 1; L < R - 1; ) {
            if (num[L] + num[R] > new_sum) {
                R --;
            } else {
                int R0 = R;
                while((L < R0 - 1) && num[L] + num[R0] <= new_sum) {
                    int M = bsearch(num, L+1, R0-1, new_sum - num[L] - num[R0]);
                    if (M != -1) {
                    hash_val = (num[L]-inc) * 200 + (num[M]-inc) * 20 + (num[R0]-inc);
                    if (hash.find(hash_val) == hash.end()) { // if not exist yet, add.
                        hash.insert(hash_val);
                        result.push_back(getV(num[L] - inc, num[M] - inc, num[R0] - inc));
                    }
                  }
                  R0 --;
                }
                L ++;
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
    
    // use this if repetition not allowed in input.
    int bsearch(vector<int> a, int left, int right, int k) {
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (a[mid] == k) return mid;
            else if (a[mid] < k) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

vector<int> makeVector(int a[], int len) {
  int i;
  //int len = sizeof(a) / sizeof(int);
  vector<int> v;
  for (i = 0; i < len; i ++) {
      v.push_back(a[i]);
  }
  return v;
}

int main() {
    //int a[] = {1,200,-201,20,1,-21}; 
    //int a[] = {-401,200,201,-382,1,381};
    int a[] = {-1,0,1,2,-1,-4};
    vector<int> v = makeVector(a, sizeof(a) / sizeof(int));   
    Solution s;
    vector<vector<int> > so = s.threeSum( v );
    printf("hi. %d solutions exist\n", so.size());
    for (int i = 0; i < so.size(); i ++) {
        printf("%d: ", i);
        vector<int> u = so[i];
        for (int j = 0; j < u.size(); j ++) {
            printf("%d ", u[j]);    
        }
        puts("");
    }
}

/*
Problem:
        
Given an array S of n integers, are there elements a, b, c in S 
such that a + b + c = 0? Find all unique triplets in the array 
which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

 */
