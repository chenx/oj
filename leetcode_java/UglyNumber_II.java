public class Solution {
    private LinkedList<Long> v2;
    private LinkedList<Long> v3;
    private LinkedList<Long> v5;

    public int nthUglyNumber(int n) {
        if (n < 1) return -1; // n >= 1.
        
        v2 = new LinkedList<Long>();
        v3 = new LinkedList<Long>();
        v5 = new LinkedList<Long>();
        
        v2.add(new Long(2));
        v3.add(new Long(3));
        v5.add(new Long(5));
        
        long val = 1;
        for (int i = 1; i < n; ++ i) {
            val = getNext(); 
        }
        
        return (int) val;
    }
    
    long getNext() {
        long n2 = v2.size() > 0 ? v2.getFirst() : Long.MAX_VALUE;
        long n3 = v3.size() > 0 ? v3.getFirst() : Long.MAX_VALUE;
        long n5 = v5.size() > 0 ? v5.getFirst() : Long.MAX_VALUE;
        
        long next = Math.min(n2, Math.min(n3, n5));
        
        if (next == n2) {
            v2.add(next * 2);
            v3.add(next * 3);
            v5.add(next * 5);
            
            v2.removeFirst();
        }
        else if (next == n3) {
            v3.add(next * 3);
            v5.add(next * 5);
            
            v3.removeFirst();
        }
        else {
            v5.add(next * 5);
            
            v5.removeFirst();
        }
        
        return next;
    }
}

/**
Ugly Number II
Difficulty: Medium
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number.
Hint:
    The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
    An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
    The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
    Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).

 */
