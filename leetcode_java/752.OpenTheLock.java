// Time complexity: O(4(d+10^4))
// Space complexity: O(4(d+10^4))
// Here n=10 is the number of slots on a wheel, w=4 is the number of wheels, and d is the number of elements in the deadends array.
class Solution {
    public int openLock(String[] deadends, String target) {
        if (target.equals("0000")) return 0;

        HashSet<String> dead = new HashSet();
        for (String s : deadends) dead.add(s);
        if (dead.contains("0000")) return -1;

        HashSet<String> used = new HashSet();
        Queue<Pair<String, Integer>> queue = new LinkedList<>();

        queue.add(new Pair("0000", 0));
        used.add("0000");

        while (! queue.isEmpty()) {
            String val = queue.peek().getKey();
            int dist = queue.peek().getValue();
            queue.remove();

            char[] chars = val.toCharArray();
            for (int i = 0; i < 4; ++ i) {
                char backup = chars[i];
                int v = chars[i] - '0';

                int[] nextVals = new int[]{ (v+1) % 10, (v-1+10) % 10 };

                for (int j = 0; j < nextVals.length; ++ j) {
                    chars[i] = (char) ('0' + nextVals[j]);
                    String next = new String(chars);

                    if (! used.contains(next) && ! dead.contains(next)) {
                        if (next.equals(target)) return dist + 1;

                        used.add(next);
                        queue.add(new Pair(next, dist + 1));
                    }
                }

                chars[i] = backup;
            }
        }

        return -1;
    }
}


/**
752. Open the Lock
Medium

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of 
turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop 
turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required 
to open the lock, or -1 if it is impossible.
 */
