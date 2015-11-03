// O(N).
public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int len = gas.length, sum = 0, total = 0, index = 0;
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
}

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
