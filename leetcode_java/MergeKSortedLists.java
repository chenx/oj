// complexity: (n1 + n2 + .. + nk) * log(k)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode h = null, t = null;
        
        Comparator<ListNode> comp = new MyComp();
        PriorityQueue<ListNode> q = new PriorityQueue<ListNode>(comp);
        
        for (int i = 0, len = lists.length; i < len; ++ i) {
            if (lists[i] != null) q.add(lists[i]);
        }
        
        while (! q.isEmpty()) {
            ListNode tmp = q.peek();
            q.remove();
            if (tmp.next != null) q.add(tmp.next);
            
            if (h == null) h = t = tmp;
            else {
                t.next = tmp;
                t = tmp;
            }
        }
        
        return h;        
    }
    
    class MyComp implements Comparator<ListNode> {
        @Override
        public int compare(ListNode a, ListNode b) {
            if (a.val == b.val) return 0;
            if (a.val < b.val) return -1; // min heap
            return 1;
        }
    }
}

/**
Merge k Sorted Lists
Difficulty: Hard

Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity. 
 */
