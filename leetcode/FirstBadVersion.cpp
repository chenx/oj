// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

// Works. Best version.
class Solution {
public:
   int firstBadVersion(int n) {
       int L = 0, R = n;
       while (L <= R) {
           int M = L + (R - L)/2;
           if (isBadVersion(M)) {
               R = M - 1;
           } else if (!isBadVersion(M)) {
               L = M+1;
           }
       }
       return R + 1;
   }
};


// This works too. 
// Find the right boundary of good ones, add by 1 for left boundary of bad ones.
class Solution2 {
public:
    int firstBadVersion(int n) {
        int L = 0, R = n - 1, M, ret = -1;
        
        while (L <= R) {
            M = L + (R-L)/2;
            if (! isBadVersion(M)) {
                ret = M;
                L = M + 1;
            }
            else {
                R = M - 1;
            }
        }
        
        return ret + 1;
    }
};

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1, R = n, ret = -1;
        
        while (L <= R) {
            int M = L + (R - L)/2;
            if (isBadVersion(M)) {
                ret = M;
                R = M - 1;
            }
            else {
                L = M + 1;
            }
        }
        
        return ret;
    }
};


/**
First Bad Version
Difficulty: Easy

You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions 
after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first 
bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether 
version is bad. Implement a function to find the first bad version. 
You should minimize the number of calls to the API. 
 */
