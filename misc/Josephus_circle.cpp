//
// The quick solution (DP): f(n, m) = (f(n-1, m) + m) % n
// Code below are from [2].
//
// Can think this way:
//   0, 1, 2, .... k-1, k, ..., n-1
//   ^                  ^
//   f(n,m)+0           f(n-1,m)+k
//
//   Survivor: f(n,m)+0 = (f(n-1,m)+k) % n ==> these two are the same person. 
//
// [1] http://en.wikipedia.org/wiki/Josephus_problem
// [2] http://zhedahht.blog.163.com/blog/static/2541117420072250322938/
//
// Created on: 3/5/2013
//

class Solution {

    ///////////////////////////////////////////////////////////////////////
    // n integers (0, 1, ... n - 1) form a circle. Remove the mth from
    // the circle at every time. Find the last number remaining
    // Input: n - the number of integers in the circle initially
    //        m - remove the mth number at every time
    // Output: the last number remaining when the input is valid,
    //         otherwise -1
    //
    // O(n) time, O(1) space.
    ///////////////////////////////////////////////////////////////////////

    int LastRemaining_Solution2(int n, unsigned int m)
    {
        // invalid input
        if(n <= 0 || m < 0)
            return -1;

        // if there are only one integer in the circle initially,
        // of course the last remaining one is 0
        int lastinteger = 0;

        // find the last remaining one in the circle with n integers
        for (int i = 2; i <= n; i ++) 
            lastinteger = (lastinteger + m) % i;

        return lastinteger;
    }


    ///////////////////////////////////////////////////////////////////////
    // n integers (0, 1, ... n - 1) form a circle. Remove the mth from
    // the circle at every time. Find the last number remaining
    // Input: n - the number of integers in the circle initially
    //        m - remove the mth number at every time
    // Output: the last number remaining when the input is valid,
    //         otherwise -1
    ///////////////////////////////////////////////////////////////////////

    int LastRemaining_Solution1(unsigned int n, unsigned int m)
    {
      // invalid input
      if(n < 1 || m < 1)
            return -1;

      unsigned int i = 0;

      // initiate a list with n integers (0, 1, ... n - 1)
      list<int> integers;
      for(i = 0; i < n; ++ i)
            integers.push_back(i);

      list<int>::iterator curinteger = integers.begin();
      while(integers.size() > 1)
      {
            // find the mth integer. Note that std::list is not a circle
            // so we should handle it manually
            for(int i = 1; i < m; ++ i)
            {
                  curinteger ++;
                  if(curinteger == integers.end())
                        curinteger = integers.begin();
            }

            // remove the mth integer. Note that std::list is not a circle
            // so we should handle it manually
            list<int>::iterator nextinteger = ++ curinteger;
            if(nextinteger == integers.end())
                  nextinteger = integers.begin();

            -- curinteger;
            integers.erase(curinteger);
            curinteger = nextinteger;
      }

      return *(curinteger);
    }

};