// Time complexity: O(Nlog(N)) for sorting.
// Space complexity: O(N) since in the worst case we need O(N) to store timestamp.
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int n = trips.length;
        HashMap<Integer, Integer> map = new HashMap();
        
        for (int i = 0; i < n; ++ i) { // get number of passengers changed at each stop.
            map.put(trips[i][1], map.getOrDefault(trips[i][1], 0) + trips[i][0]);
            map.put(trips[i][2], map.getOrDefault(trips[i][2], 0) - trips[i][0]);
        }

        int[][] stops = new int[map.size()][2];
        int i = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) { // convert map to array.
            stops[i ++] = new int[]{entry.getKey(), entry.getValue()};
        }

        Arrays.sort(stops, (a, b) -> a[0] - b[0]); // sort array by stop number.

        int ct = 0; // count of passengers.
        for (i = 0; i < stops.length; ++ i) { // get absolute number of passengers at each stop.
            ct += stops[i][1];
            if (ct > capacity) return false;
        }
        return true;
    }
}


/**
1094. Car Pooling
Medium

There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that 
the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. 
The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
 */
