// From https://leetcode.com/problems/longest-consecutive-sequence/editorial
class Solution3 {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> s = new HashSet<Integer>();
        
        for (int num : nums) {
            s.add(num);
        }
        
        int mlen = 0;
        for (int num : s) {
            if (!s.contains(num - 1)) {
                int len = 0;
                for (int i = num; s.contains(i); ++ i) ++ len;
                mlen = Math.max(mlen, len);
            }
        }
        return mlen;
    }
}

class Solution2 {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> set = new HashSet();

        for (int num : nums) set.add(num);

        int maxLen = 0;
        while (! set.isEmpty()) {
            Iterator<Integer> it = set.iterator();
            maxLen = Math.max(maxLen, getLen(it.next(), set));
        }
        return maxLen;
    }

    int getLen(int n, HashSet<Integer> set) {
        int len = 1;
        set.remove(n);
        for (int i = n - 1; set.contains(i); -- i) {
            set.remove(i);
            ++ len;
        }
        for (int i = n + 1; set.contains(i); ++ i) {
            set.remove(i);
            ++ len;
        }
        return len;
    }
}

public class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> s = new HashSet<Integer>();
        
        for (int i = 0, len = nums.length; i < len; ++ i) {
            s.add(nums[i]);
        }
        
        int mlen = 0;
        while (s.iterator().hasNext()) {
            mlen = Math.max(mlen, getLen(s, s.iterator().next()));
        }
        return mlen;
    }
    
    private int getLen(HashSet<Integer> s, int val) {
        int len = 0;
        
        for (int v = val; s.contains(v); -- v) {
            ++ len;
            s.remove(v);
        }
        
        for (int v = val + 1; s.contains(v); ++ v) {
            ++ len;
            s.remove(v);
        }
        
        return len;
    }
}

/**
Longest Consecutive Sequence
Difficulty: Hard

Given an unsorted array of integers, find the length of the longest 
consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 
 */
