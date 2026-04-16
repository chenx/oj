/**
  In C++, a std::map automatically stores its elements in a sorted order based on their keys. 
  This is a fundamental characteristic of std::map, as it is typically implemented using a self-balancing 
  binary search tree (like a Red-Black tree).

  So it's possible to erase mp.begin() on the smallest (earliest) timestamps.
 */

// Implemented as circular array. The most popular implementation.
// Time: O(1) for hit, O(300) =~ O(1) for getHits.
// Space: O(300) =~ O(1).
class HitCounter {
    vector<vector<int>> counter; //(300, vector<int>(2, 0)); // <timestamp, count> 
    int capacity;
public:
    HitCounter() : capacity(300) {
        counter.resize(capacity, {0,0});
    }
    
    void hit(int timestamp) {
        int index = timestamp % capacity;
        if (timestamp != counter[index][0]) {
            counter[index] = {timestamp, 0};
        }
        counter[index][1] ++;
    }
    
    int getHits(int timestamp) {
        int count = 0;
        for (const auto& item : counter) {
            if (timestamp - item[0] < capacity) {
                count += item[1];
            }
        }
        return count;
    }
};


// Implemented as deque.
// Time: O(1) for hit, O(n) for getHits, where n = number of valid hits.
// Space: O(n)
class HitCounter2 {
    queue<int> q;
public:
    HitCounter() {
    }
    
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (! q.empty() && timestamp - q.front() >= 300) {
            q.pop();
        }
        return q.size();
    }
};


class HitCounter {
    map<int, int> mp; // <timestamp, hits>
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        mp[timestamp] ++;
    }
    
    int getHits(int timestamp) {
        // This leads to timeout.
        // while (timestamp - mp.begin()->first >= 300) {
        //     mp.erase(mp.begin()->first);
        // }

        int sum = 0;
        for (auto entry : mp) {
            if (timestamp - entry.first >= 300) mp.erase(entry.first);
            else sum += entry.second;
        }
        return sum;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

/**
362. Design Hit Counter

Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).

Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being 
made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive 
roughly at the same time.

Implement the HitCounter class:

    HitCounter() Initializes the object of the hit counter system.
    void hit(int timestamp) Records a hit that happened at timestamp (in seconds). Several hits may happen 
        at the same timestamp.
    int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp (i.e., the past 300 seconds).

 */
