/**
 * Given a row of N houses. Paint them with 3 colors R, G, B,
 * the cost is c1, c2, c3 respectively. Adjacent houses cannot
 * have the same color. Output the minimal cost.
 *
 * Solution:
 * cost[r][n] = cost[r] + min {cost[g][n-1], cost[b][n-1]};
 * cost[g][n] = cost[g] + min {cost[r][n-1], cost[b][n-1]};
 * cost[b][n] = cost[b] + min {cost[b][n-1], cost[g][n-1]};
 * and cost[n] = min(cost[r][n], cost[g][n], cost[b][n]);
 *      
 * where c = 1, 2, 3, standing for the 3 colors.
 *          
 * By: X.C. 
 * On: 3/9/2015
 */
        
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: 
    // This works.
    int getCost(int cost[3], int n) {
        if (n == 0) return 0;
        
        vector<vector<int> > c(3, vector<int>(n, 0));
        c[0][0] = cost[0];
        c[1][0] = cost[1];
        c[2][0] = cost[2];
        
        for (int i = 1; i < n; ++ i) {
            c[0][i] = cost[0] + min(c[1][i-1], c[2][i-1]);
            c[1][i] = cost[1] + min(c[0][i-1], c[2][i-1]);
            c[2][i] = cost[2] + min(c[1][i-1], c[2][i-1]);
        }
        
        return min(c[0][n-1], min(c[1][n-1], c[2][n-1]));
    }
    
    // This works too. Use 6 variables instead of a 2-D array.
    int getCost2(int cost[3], int n) {
        if (n == 0) return 0;

        int c0, c1, c2, c00, c10, c20;
        c0 = c00 = cost[0];
        c1 = c10 = cost[1];
        c2 = c20 = cost[2];

        for (int i = 1; i < n; ++ i) {
            c0 = cost[0] + min(c10, c20);
            c1 = cost[1] + min(c00, c20);
            c2 = cost[2] + min(c00, c10);
            c00 = c0, c10 = c1, c20 = c2;
        }
        
        return min(c0, min(c1, c2));
    }
};

void test1() {
    Solution so;
    int cost[3] = {1,2,3};
    for (int i = 1; i <= 10; ++ i) {
        cout << "i = " << i << ": cost = " << so.getCost(cost, i) << endl;
        cout << "i = " << i << ": cost2 = " << so.getCost2(cost, i) << endl;
    }
}

int main() {
    test1();
    return 0;
}
