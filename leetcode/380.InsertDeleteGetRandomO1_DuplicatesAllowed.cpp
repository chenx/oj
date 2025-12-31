// Works.
class RandomizedSet {
    vector<int> vals;
    map<int, int> positionMap;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (positionMap.contains(val)) return false;

        vals.push_back(val);
        positionMap[val] = vals.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (! positionMap.contains(val)) return false;

        int index = positionMap[val];

        positionMap[vals[vals.size() - 1]] = index;
        vals[index] = vals[vals.size() - 1];
        positionMap.erase(val);
        vals.pop_back();

        return true;
    }
    
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};


// Works.
class RandomizedSet {
    unordered_map<int, int> m;  // map<val, pos>
    vector<int> v;  // (200000, 0);
    int size;
public:
    RandomizedSet() {
        size = 0;
        v.resize(20000);
    }
    
    bool insert(int val) {
        if (m.contains(val)) return false;
        m[val] = size;
        v[size] = val;
        ++ size;
        return true;
    }
    
    bool remove(int val) {
        if (!m.contains(val)) return false;
        int pos = m[val];
        v[pos] = v[size - 1];
        m[v[pos]] = pos;  // don't forget this.
        -- size;
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        if (size == 0) return 0;
        return v[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


/**
381. Insert Delete GetRandom O(1) - Duplicates allowed
Hard

RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset). 
It should support inserting and removing specific elements and also reporting a random element.

Implement the RandomizedCollection class:

    RandomizedCollection() Initializes the empty RandomizedCollection object.
    bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if 
        the item is not present, false otherwise.
    bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false 
        otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
    int getRandom() Returns a random element from the current multiset of elements. The probability of each element 
        being returned is linearly related to the number of the same values the multiset contains.

You must implement the functions of the class such that each function works on average O(1) time complexity.

Note: The test cases are generated such that getRandom will only be called if there is at least one item in the 
RandomizedCollection.
 */
