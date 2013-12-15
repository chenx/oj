// 
// O(N). Also works.
// The idea is: this can be converted to the maximum subarray sum problem: 
//    find the max subarray, use the start of this subarray as the starting point.
//    If this is not possible, then other starting points will not be possible either.
// http://stackoverflow.com/questions/2286849/algorithm-for-truck-moving-around-a-circle-of-gas-stations
//


// This also works.

发信人: surongr (surongr), 信区: JobHunting
标  题: Gas station 的另一种解题思路
发信站: BBS 未名空间站 (Wed Oct 23 01:56:31 2013, 美东)

今天做了 Gas station，然后来看讨论发现市面上的解法已经很经典，通过计算所有和
检测是否有解，通过计算部分和找到 index。

本题本质是找到一个序列使所有前缀和非负。所以是这样想的，假设 index 0 （用
beg 表示）就是解，如果假设成立，那么从这开始的前缀和（假设已经走到了 end）都
是非负的，一直累加。然而一旦发现不成立，那么就退一步把 beg 设为 beg - 1 作为
候选。直到 beg == end。这样只要一个累加和就好了。

初始时把 beg = 0, end = (beg + 1) % n ，更新时是 beg = (beg - 1 + n) % n，
end = (end + 1) % n，但这样并不美观。所以技巧是把 beg 初值设为 n - 1，end 设
为 0，两数更新就都是单调的了。

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int beg = gas.size() - 1, end = 0;
        int sum = gas[beg] - cost[beg];
        while (beg != end) {
            if (sum < 0) {
                --beg;
                sum += gas[beg] - cost[beg];
            } else {
                sum += gas[end] - cost[end];
                ++end;
            }
        }
        return (sum >= 0) ? (beg) : (-1);
    }
};

当然可以写一个省字节的脑残解，just more fun
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int beg = gas.size() - 1, end = 0;
        int sum = gas[beg] - cost[beg];
        while (beg != end) {
            int k = (sum < 0) ? (--beg) : (end++);
            sum += gas[k] - cost[k];
        }
        return (sum >= 0) ? (beg) : (-1);
    }
};


// This also works.
for(int i = 0; i < size; i++){
            sum += gas[i] - cost[i];
           
            if(subSum > 0)
                subSum += gas[i] - cost[i];
            else{
                subSum = gas[i] - cost[i];
                index = i;
            }
        }
       
        if(sum < 0) return -1;
        return index;
}


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
    
    int selectGasStation(const vector<int> &a, const vector<int> &g) {
        int n = a.size();
        if (n == 0) return -1;
        
        vector<int> A(n);
        for (int i = 0; i < n; ++ i) A[i] = a[i] - g[i];
        
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
    int selectGasStation(const vector<int> &a, const vector<int> &g) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = a.size();
        if (n == 0) return -1;
        
        for (int start = 0; start < n; ++ start) {
            int total_gas = 0, i = 0;
            for (; i < n; ++ i) {
                int k = (start + i) % n;
                total_gas += (a[k] - g[k]);
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
};


//
// This also works. Basically same as Solution2.
//
int selectGasStation(const vector<int> &a, const vector<int> &g) {
    int total=0;
    int start=-1;
    for(int i=0,sum=0; i<a.size(); ++i)
    {
        sum+=a[i]-g[i];
        total+=a[i]-g[i];
        if(sum<0)
        {
           start=i;
           sum=0;
        }
    }
   
    return total>=0?start+1:-1;    
}

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
            int total_gas = 0, i = 0;
            for (; i < n; ++ i) {
                int k = (start + i) % n;
                total_gas += (a[k] - g[k]);
                if (total_gas < 0) break;
            }
            if (i == n) return start;
        }
        return -1;
    }
};