// From https://leetcode.com/problems/broken-calculator/editorial/
// Time Complexity: O(logtarget).
// Space Complexity: O(1).
class Solution {
    public int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (target > startValue) {
            ans++;
            if (target % 2 == 1)
                target++;
            else
                target /= 2;
        }

        // (startValue - target) is for the substract one steps.
        return ans + (startValue - target);
    }
}

// TLE for large answer.
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (startValue == target) return 0;

        queue<pair<unsigned long long, int>> q;
        q.push({startValue, 0});

        set<unsigned long long> used;
        used.insert(startValue);

        while (! q.empty()) {
            int value = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (value == target) return dist;

            if (!used.contains((unsigned long long) value * 2)) {
                used.insert((unsigned long long) value * 2);
                q.push({(unsigned long long) value * 2, dist + 1});
            }
            if (!used.contains((unsigned long long) value - 1)) {
                used.insert((unsigned long long) value -1);
                q.push({(unsigned long long) value - 1 , dist + 1});
            } 
        }

        return 0;
    }
};

/**
991. Broken Calculator

There is a broken calculator that has the integer startValue on its display initially. In one operation, you can:

    multiply the number on display by 2, or
    subtract 1 from the number on display.

Given two integers startValue and target, return the minimum number of operations needed to display target on the calculator.
 */
