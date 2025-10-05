class RandomizedSet {
    private Random random; // = new Random();
    private Map<Integer, Integer> map; // = new HashMap<>(); // <value, position>
    private List<Integer> arr; // = new ArrayList<>(); // value at position

    public RandomizedSet() {
        random = new Random();
        map = new HashMap<>(); // <value, position>
        arr = new ArrayList<>(); // value at position
    }
    
    public boolean insert(int val) {
        if (map.containsKey(val)) return false;
        
        arr.add(val);
        map.put(val, arr.size() - 1);
        return true;
    }
    
    public boolean remove(int val) {
        if (!map.containsKey(val)) return false;
        
        int pos = map.get(val);
        arr.set(pos, arr.get(arr.size() - 1)); // arr[pos] = arr[arr.size() - 1];
        map.put(arr.get(pos), pos);  // don't forget this.
        
        arr.remove(arr.size() - 1);
        map.remove(val);
        
        return true;
    }
    
    public int getRandom() {
        return arr.get(random.nextInt(arr.size()));  // 0 to arr.size()-1
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

/**
380. Insert Delete GetRandom O(1)

We're asked to implement the structure which provides the following operations in average O(1) time:

    Insert
    Delete
    GetRandom

First of all - why this weird combination? The structure looks quite theoretical, but it's widely used 
in popular statistical algorithms like Markov chain Monte Carlo and Metropolis–Hastings algorithm. 
These algorithms are for sampling from a probability distribution when it's difficult to compute the 
distribution itself.
 */
