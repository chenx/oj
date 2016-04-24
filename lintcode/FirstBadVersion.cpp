/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // find left most.
        int L = 1, R = n, ret = -1;//n + 1; // n+1 or -1, both work.
        
        while (L <= R) {
            int M = L + (R - L)/2;
            if (SVNRepo::isBadVersion(M)) {
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

The code base version is an integer start from 1 to n. One day, 
someone committed a bad version in the code case, so it caused 
this version and the following versions are all failed in the 
unit tests. Find the first bad version.

You can call isBadVersion to help you determine which version is 
the first bad one. The details interface can be found in the 
code's annotation part.

Notice

Please read the annotation in code area to get the correct way 
to call isBadVersion in different language. For example, Java 
is SVNRepo.isBadVersion(v)
Example

Given n = 5:

isBadVersion(3) -> false
isBadVersion(5) -> true
isBadVersion(4) -> true

Here we are 100% sure that the 4th version is the first bad version.
Challenge

You should call isBadVersion as few as possible.

 */
