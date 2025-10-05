// Works. Best.
class FirstUnique {
    map<int, int> mp;

    // list + map = LinkedHashSet in Java, supports
    // O(1) for insert, find and delete.
    list<int> unique;
    unordered_map<int, list<int>::iterator> pos;
public:
    FirstUnique(vector<int>& nums) {  // O(n)
        for (int num : nums) ++ mp[num];

        for (int num : nums) {
            if (mp[num] == 1) {
                unique.push_front(num);
                pos[num] = unique.begin();
            }
        }
    }
    
    int showFirstUnique() {  // O(1)
        if (!unique.empty()) return unique.back();
        return -1;
    }
    
    void add(int value) {  // O(1)
        ++ mp[value];

        if (mp[value] == 1) {
            unique.push_front(value);
            pos[value] = unique.begin();
        } else if (mp[value] == 2) {
            unique.erase(pos[value]);
            pos.erase(value);
        }
    }
};

// Works, not efficient.
class FirstUnique {
    map<int, int> mp;
    vector<int> unique;
public:
    FirstUnique(vector<int>& nums) {  // O(n)
        for (int num : nums) ++ mp[num];

        for (int num : nums) {
            if (mp[num] == 1) unique.push_back(num);
        }
    }
    
    int showFirstUnique() {  // O(n)
        if (!unique.empty()) return unique[0];
        return -1;
    }
    
    void add(int value) {  // O(n^2)
        ++ mp[value];

        if (mp[value] == 1) unique.push_back(value);
        else if (mp[value] == 2) {
            for (int i = 0; i < unique.size(); ++ i) {
                if (value == unique[i]) {
                    unique.erase(unique.begin() + i);
                }
            }
        }
    }
};


/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

/**
1429. First Unique Number

You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

    FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
    int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
    void add(int value) insert value to the queue
 */
