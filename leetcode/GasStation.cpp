// O(N). This also works. Seems the best.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size(), sum = 0, total = 0, index = 0;
        for (int i = 0; i < len; ++ i) {
            if (sum <= 0) {
                index = i;
                sum = 0;
            }
            
            int gain = gas[i] - cost[i];
            sum += gain;
            total += gain;
        }
        
        return total < 0 ? -1 : index;
    }
};

// 
// O(N). Also works.
// The idea is: this can be converted to the maximum subarray sum problem: 
//    find the max subarray, use the start of this subarray as the starting point.
//    If this is not possible, then other starting points will not be possible either.
// http://stackoverflow.com/questions/2286849/algorithm-for-truck-moving-around-a-circle-of-gas-stations
//
class Solution3 {
public:
    int maxSubarrayIndex(vector<int> A) {
        int sum = A[0];
        int msum = A[0];
        int msum_i = 0;
        
        for (int i = 1; i < A.size(); ++ i) {
            if (sum < 0) {
                sum = 0;
                msum_i = i;
            }
            sum += A[i];
            msum = max(sum, msum);
        }
        
        return msum_i;
    }
    
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = gas.size();
        if (n == 0) return -1;
        
        vector<int> A(n);
        for (int i = 0; i < n; ++ i) A[i] = gas[i] - cost[i];
        
        int k = maxSubarrayIndex(A);
        
        int sum = 0;
        for (int i = 0; i < n; ++ i) {
            sum += A[(i + k) % n];
            if (sum < 0) return -1;
        }
        
        return k;
    }
};

//
// O(N). Works.
// The idea is: 
// 1) if you start from station x, and run out of gas at station y, then 
//    next trial can start from station y+1, instead of x+1.
//    This is because starting from any station between [x+1, y-1], you will run out
//    of gas for sure at station y. This is because:
//       sum(gas[x]-cost[x] + ... + gas[y]-cost[y]) < 0, 
//    for any x' in [x+1, y-1], sum(gas[x]-cost[x] + ... + gas[x']-cost[x']) >= 0
//    since it's possible to reach x' from x; therefore, 
//    sum(gas[x']-cost[x'] + ... + gas[y]-cost[y]) < 0.
//    We also can't start from y, since obviously gas[y]-cost[y] < 0.
// 2) if the next start point has passed the starting station (station 0),
//    then no chance, just stop, since we already tried.
//
// Another idea: this is the maximum subarray sum problem: 
//    find the max subarray, use the start of this subarray as the starting point.
//    If this is not possible, then other starting points will not be possible either.
//
class Solution2 {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = gas.size();
        if (n == 0) return -1;
        
        for (int start = 0; start < n; ++ start) {
            int total_gas = 0, i = 0;
            for (; i < n; ++ i) {
                int k = (start + i) % n;
                total_gas += (gas[k] - cost[k]);
                if (total_gas < 0) {
                    start = start + i;
                    if (start > n-1) return -1;
                    break;
                }
            }
            if (i == n) return start;
        }
        return -1;
    }

    //
    // This works too. More succinct.
    // http://www.mitbbs.com/article_t/JobHunting/32566647.html
    //
    int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int start = -1;
        for(int i=0, sum=0; i < gas.size(); ++ i)
        {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0)
            {
               start = i;
               sum = 0;
            }
        }
       
        return total >= 0 ? start+1 : -1;    
    }
    
    // This works too, adapted from canCompleteCircuit2.
    int canCompleteCircuit3(vector<int> &gas, vector<int> &cost) {
        int index = 0;
        int sum = 0, total = 0;
        
        for (int i = 0; i < gas.size(); ++ i) {
            if (sum < 0) {
                index = i; 
                sum = 0;
            }
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
        }
        
        return total < 0 ? -1 : index;
    }    
};


// N^2. Works. but time out for large input.
class Solution {
public:
    // n^2. TLE
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = gas.size();
        if (n == 0) return -1;
        
        for (int start = 0; start < n; ++ start) {
            int g = 0, i = 0;
            for (; i < n; ++ i) {
                int k = (start + i) % n;
                g += (gas[k] - cost[k]);
                if (g < 0) break;
            }
            if (i == n) return start;
        }
        return -1;
    }
};


/**
Gas Station
Difficulty: Medium

There are N gas stations along a circular route, where 
the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas 
to travel from station i to its next station (i+1). You begin the 
journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around 
the circuit once, otherwise return -1. 
 */
