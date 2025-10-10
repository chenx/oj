// Works.
class HitCounter2 {
    Queue<Integer> hits; // timestamp

    public HitCounter() {
        hits = new LinkedList<>();
    }
    
    public void hit(int timestamp) {
        hits.add(timestamp); // add to back
    }
    
    public int getHits(int timestamp) {
        while (!hits.isEmpty()) {
            if (timestamp - hits.peek() >= 300) hits.remove(); // remove from front
            else break;
        }
        return hits.size();
    }
}

class HitCounter {
    HashMap<Integer, Integer> map = new HashMap<>();

    public HitCounter() {
        
    }
    
    public void hit(int timestamp) {
        // map.put(timestamp, map.get(timestamp) != null ? 1 + map.get(timestamp) : 1);
        map.put(timestamp, 1 + map.getOrDefault(timestamp, 0));
    }
    
    public int getHits(int timestamp) {
        int count = 0;
        List<Integer> keysToRemove = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (timestamp - entry.getKey() >= 300) {
                keysToRemove.add(entry.getKey());
            } else {
                count += entry.getValue();
            }
        }
        for (int i = 0; i < keysToRemove.size(); ++ i) {
            map.remove(keysToRemove.get(i));
        }
        return count;
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

/**
362. Design Hit Counter

Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).

Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being 
made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive 
roughly at the same time.

Implement the HitCounter class:

    HitCounter() Initializes the object of the hit counter system.
    void hit(int timestamp) Records a hit that happened at timestamp (in seconds). Several hits 
      may happen at the same timestamp.
    int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp (i.e., the past 300 seconds).

 */
