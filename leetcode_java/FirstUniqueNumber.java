class FirstUnique {
    HashMap<Integer, Boolean> unique = new HashMap<>(); // num, pos
    Set<Integer> queue = new LinkedHashSet<>();

    public FirstUnique(int[] nums) {
        for (int num : nums) {
            this.add(num);
        }
    }
    
    public int showFirstUnique() {
        if (queue.isEmpty()) return -1;
        return queue.iterator().next();
    }
    
    public void add(int value) {
        if (unique.containsKey(value)) {
            unique.put(value, false);
            queue.remove(value);
        } else {
            unique.put(value, true);
            queue.add(value);
        }
    }
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique obj = new FirstUnique(nums);
 * int param_1 = obj.showFirstUnique();
 * obj.add(value);
 */

/**
1429. First Unique Number
 */
