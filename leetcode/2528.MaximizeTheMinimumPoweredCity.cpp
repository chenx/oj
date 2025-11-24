// From: https://leetcode.com/problems/maximize-the-minimum-powered-city/editorial/
// Binary Search + Difference Array
// Let n be the length of the array stations, D=sum(stations)+k.
// Time complexity: O(nlogD).
// Space complexity: O(n).
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n, i + r + 1);
            cnt[left] += stations[i];
            cnt[right] -= stations[i];
        }

        auto check = [&](long long val) -> bool {
            vector<long long> diff = cnt;
            long long sum = 0;
            long long remaining = k;

            for (int i = 0; i < n; i++) {
                sum += diff[i];
                if (sum < val) {
                    long long add = val - sum;
                    if (remaining < add) {
                        return false;
                    }
                    remaining -= add;
                    int end = min(n, i + 2 * r + 1);
                    diff[end] -= add;
                    sum += add;
                }
            }
            return true;
        };

        long long lo = ranges::min(stations);
        long long hi = accumulate(stations.begin(), stations.end(), 0LL) + k;
        long long res = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }
};


/**
2528. Maximize the Minimum Powered City
Hard

You are given a 0-indexed integer array stations of length n, where stations[i] represents the number of 
power stations in the ith city.

Each power station can provide power to every city in a fixed range. In other words, if the range is 
denoted by r, then a power station at city i can provide power to all cities j such that |i - j| <= r 
and 0 <= i, j <= n - 1.

    Note that |x| denotes absolute value. For example, |7 - 5| = 2 and |3 - 10| = 7.

The power of a city is the total number of power stations it is being provided power from.

The government has sanctioned building k more power stations, each of which can be built in any city, 
and have the same range as the pre-existing ones.

Given the two integers r and k, return the maximum possible minimum power of a city, if the additional 
power stations are built optimally.

Note that you can build the k power stations in multiple cities.

 

Example 1:

Input: stations = [1,2,4,5,0], r = 1, k = 2
Output: 5
Explanation: 
One of the optimal ways is to install both the power stations at city 1. 
So stations will become [1,4,4,5,0].
- City 0 is provided by 1 + 4 = 5 power stations.
- City 1 is provided by 1 + 4 + 4 = 9 power stations.
- City 2 is provided by 4 + 4 + 5 = 13 power stations.
- City 3 is provided by 5 + 4 = 9 power stations.
- City 4 is provided by 5 + 0 = 5 power stations.
So the minimum power of a city is 5.
Since it is not possible to obtain a larger power, we return 5.
 */
