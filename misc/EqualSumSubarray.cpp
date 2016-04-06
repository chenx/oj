//
// This is a special case of the Partition problem:
// https://en.m.wikipedia.org/wiki/Partition_problem
//
// Given an array of 2n integers, their sum is SUM.
// Find n elements whose sum is closest to SUM/2.
//
// A similar problem can be solved the same way:
// Given an array of numbers, sum is SUM. Divide it into 2 subgroups,
// sum of each subgroup is SUM/2. 
// After getting the solution 2D array below, find i(s) where isOK[i][V] = 1.
//
// Solution here is from Beauty Of Programming, 2.18, page 204.
//
// @By: Xin Chen
// @Created on: 3/4/2013.
// @Last modified: 4/9/2013
//

#include <iostream>
#include <vector>
using namespace std;

void dump(vector<int> & s) {
    for (int i = 0; i < s.size(); ++ i) {
        cout << s[i] << " ";
    }
    cout << endl;
}

int get_sum(vector<int> & s) {
    int sum = 0;
    for (int i = 0; i < s.size(); ++ i) sum += s[i];
    return sum;
}

//
// Code is from "Bian Chen Zhi Mei"
//
class Solution {
public:
    vector<int> divide_array(vector<int> & nums) {
        vector<int> ans;
        int N2 = nums.size(); // 2n.
        if (N2 & 1 == 1) {
            cout << "size of input array should be even" << endl;
            //return ans;
        }
        int N = N2 / 2;
        
        int sum = get_sum(nums);
        int V = sum/2;
        
        // isOK[i][v]: whether can find i numbers, whose sum is v.
        int isOK[N + 1][V + 1];
        int val[N+1][V+1];
        for (int i = 0; i <= N; ++ i) {
            for (int j = 0; j <= V; ++ j) {
                isOK[i][j] = 0;
            }
        }
        isOK[0][0] = 1;

        // O(N^2 * sum)
        for (int k = 1; k <= N2; ++ k) {
            for (int i = min(k, N); i > 0; -- i) {
                for (int v = 1; v <= V; ++ v) {
                    if (v >= nums[k - 1] && isOK[i - 1][v - nums[k - 1]]) {
                        isOK[i][v] = 1;
                        val[i][v] = nums[k - 1];
                    }
                }
            }
        }

        // show isOK[][] or val[][] table.
        printf("     ");
        for (int j = 0; j <= V; ++ j) printf("%3d", j);
        cout << endl;
        
        int x = 0, y = 0;
        for (int i = 0; i <= N; ++ i) {
            cout << "n=" << i << ": ";
            for (int j = 0; j <= V; ++ j) {
                // This shows isOK[][] table.
                //printf("%3d", isOK[i][j]);
                //if (isOK[i][j] == 1 && i > 0) { x = i, y = j; } // record last element.
                
                // This shows val[][] table.
                if (isOK[i][j] && i > 0) {
                    printf("%3d", val[i][j]);
                    x = i, y = j;
                } else {
                    printf("   ");
                }
            }
            cout << endl;
        }
        
        // get the subarray.
        printf("for last element, i = %d, j = %d\n", x, y);
        while (y > 0) {
            ans.push_back(val[x][y]);
            y -= val[x][y];
            x -= 1;
        }
        
        return ans;
    }
    
};

/*
// The solution array isOK[i][v] with val[i][j] filled where isOK[i][v] == 1:
input (sum=44): 1 4 9 18 5 7
       0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22
n=0:
n=1:      1        4  5     7     9                         18
n=2:                  4  5     7  5  9  7  7  9  5     7       18       18
n=3:                                 5     7  7  9  5  7  7  5     7  7
for last element, i = 3, j = 21
*/
// 
// This is similar to knapsack, where w[i] = 1, v[i] = nums[i], i = 1,...,n.
// Limit W = sum_i_{v[i]} / 2, maximize sum{v[i]}
// --> However this is still different from knapsack. KS solution does not work.
// Knapsack: n objects, value: v[i], weight: w[i], restriction: sum{w[i]} <= W.
//           Ask for: subarray that maximize sum{v[i]}.
// EqualSumSubarray: 2n objects, value: v[i]. Restriction: divide into 2 
//           subarrays (equal length or not), sum is half total sum.
//           Ask for: subarray.
//


int main() {
    vector<int> nums;
    int a[] = {1,4,9,18,5,7};
    for (int i = 0; i < sizeof(a) / sizeof(int); ++ i) {
        nums.push_back(a[i]);
    }
    Solution s;
    
    cout << "input (sum=" << get_sum(nums) << "): "; dump(nums);
    
    vector<int> x = s.divide_array(nums);
    cout << "sub array found: "; dump(x);
    
    Solution2 s2;
    s2.divide_array(nums);
    
    return 0;
}
