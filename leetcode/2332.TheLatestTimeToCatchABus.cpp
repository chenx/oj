// From: https://algo.monster/liteproblems/2332
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int passengerIndex = 0;
        int remainingCapacity = 0;

        for (int busTime : buses) {
            remainingCapacity = capacity;

            // Board passengers who arrived before or at bus departure time
            while (remainingCapacity > 0 && 
                   passengerIndex < passengers.size() && 
                   passengers[passengerIndex] <= busTime) {
                remainingCapacity--;
                passengerIndex++;
            }
        }

        // Move back to the last boarded passenger
        passengerIndex--;
        // Determine the latest possible arrival time
        int latestArrivalTime;
        if (remainingCapacity > 0) {
            // Last bus has space, arrive at the last bus's departure time
            latestArrivalTime = buses[buses.size() - 1];
        } else {
            // Last bus is full, arrive just before the last boarded passenger
            latestArrivalTime = passengers[passengerIndex];
        }
      
        // Find a valid time slot by avoiding conflicts with existing passengers
        while (passengerIndex >= 0 && latestArrivalTime == passengers[passengerIndex]) {
            passengerIndex--;
            latestArrivalTime--;
        }
      
        return latestArrivalTime;
    }
};


/**
2332. The Latest Time to Catch a Bus
Medium

You are given a 0-indexed integer array buses of length n, where buses[i] represents the departure time 
of the ith bus. You are also given a 0-indexed integer array passengers of length m, where passengers[j] 
represents the arrival time of the jth passenger. All bus departure times are unique. All passenger 
arrival times are unique.

You are given an integer capacity, which represents the maximum number of passengers that can get on each bus.

When a passenger arrives, they will wait in line for the next available bus. You can get on a bus that 
departs at x minutes if you arrive at y minutes where y <= x, and the bus is not full. Passengers with 
the earliest arrival times get on the bus first.

More formally when a bus arrives, either:

    If capacity or fewer passengers are waiting for a bus, they will all get on the bus, or
    The capacity passengers with the earliest arrival times will get on the bus.

Return the latest time you may arrive at the bus station to catch a bus. You cannot arrive at the same 
time as another passenger.

Note: The arrays buses and passengers are not necessarily sorted.
 */
