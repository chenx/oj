class Solution2 {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]); 

        // minHeap
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < n; ++ i) {
            // start time of intervals[i] >= end time of the previous meeting.
            if (!pq.isEmpty() && intervals[i][0] >= pq.peek()) pq.remove();
            pq.add(intervals[i][1]);
        }
        return pq.size();
    }
};

class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]); 

        // maxQueue
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        for (int i = 0; i < n; ++ i) {
            // start time of intervals[i] >= end time of the previous meeting.
            if (!pq.isEmpty() && intervals[i][0] >= pq.peek()[1]) pq.remove();
            pq.add(intervals[i]);
        }
        return pq.size();
    }
}

/**
 Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], 
 return the minimum number of conference rooms required.
*/
