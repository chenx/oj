
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        
        int m = n/2;
        for (int i = -m; i < 0; ++ i) result.push_back(i);
        if (n % 2 == 1) result.push_back(0);
        for (int i = 1; i <= m; ++ i) result.push_back(i);
        
        return result;
    }

    vector<int> sumZero2(int n) {
        vector<int> result;
        if (n % 2 == 1) {
            int m = n/2;
            for (int i = -m; i < 0; ++ i) result.push_back(i);
            result.push_back(0);
            for (int i = 1; i <= m; ++ i) result.push_back(i);
        } else {
            int m = n/2;
            for (int i = -m; i < 0; ++ i) result.push_back(i);
            for (int i = 1; i <= m; ++ i) result.push_back(i);
        }
        return result;
    }
};

/**
1304. Find N Unique Integers Sum up to Zero
Easy

Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].

Example 2:

Input: n = 3
Output: [-1,0,1]

Example 3:

Input: n = 1
Output: [0]
 */
