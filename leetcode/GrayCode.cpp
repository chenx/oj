//
// http://www.leetcode.com/onlinejudge#
// @Author: Xin Chen
// @Created on: 12/19/2012
// @Last modified: 12/19/2012
//

/*
 * Note:
 * 1) n = 0, v = {0}, this is by definition.
 * 2) Notice that:
   n = 1:   0,   1
   n = 2:  00,  01,  11,  10
   n = 3: 000, 001, 011, 010, 110, 111, 101, 110
   for n = k: x1, ... xm, m = 2^k
   then for n = k+1: 0x1, ..., 0xm, 1xm, ..., 1x0, there are 2^(k+1) items.
   i.e., the first m items are same as those for n=k, 
         the second m items are those for n=k in reverse order, attach 1 in front of them.
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        if (n == 0) { 
            v.push_back(0);
            return v;
        }
        
        v.push_back(0);
        v.push_back(1);

        int k = 1;
        for (int i = 1; i < n; i ++) {
            k = k << 1;
            for (int j = v.size() - 1; j >= 0; j --) {
                v.push_back(v[j] + k);
            }
        }
        
        return v;
    }
};

// This works too. Simplified from Solution above.
class Solution2 {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        
        ans.push_back(0);
        for (int i = 0; i < n; ++ i) {
            for (int j = ans.size()-1; j >= 0; -- j) {
                ans.push_back(ans[j] + (1 << i));
            }
        }
        
        return ans;
    }
};

/*
http://www.mitbbs.com/article_t/JobHunting/32295763.html
Another method:

vector<int> grayCode(int n)
{
         vector<int> ret;
         int size = 1 << n;
         for(int i = 0; i < size; ++i)
             ret.push_back((i >> 1)^i);
         return ret;
}


*/


/**
Gray Code
Difficulty: Medium

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, 
print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */
