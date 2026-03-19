# Mergesort
# Time: O(nlogn)
# Space: O(logn) for recursion stack.
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next: # "not head.next" is import to avoid infinite cycle.
            return head

        fast, slow = head.next, head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        
        # slow is before the center node.
        h1 = head
        h2 = slow.next
        slow.next = None

        h1 = self.sortList(h1)
        h2 = self.sortList(h2)

        # merge sort
        dummy = ListNode()
        tail = dummy
        while h1 and h2:
            if h1.val < h2.val:
                tail.next = h1
                tail = h1
                h1 = h1.next
                tail.next = None
            else:
                tail.next = h2
                tail = h2
                h2 = h2.next
                tail.next = None
        
        tail.next = h1 if h1 else h2
        return dummy.next



# Definition for singly-linked list.
# Insertion sort
# Time: O(n^2)
# Space: O(1)
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # insertion sort
        dummy = ListNode()

        while head:
            node = head
            head = head.next
            node.next = None

            tail = dummy
            inserted = False
            while tail.next:
                if node.val <= tail.next.val:
                    # insert after tail
                    node.next = tail.next
                    tail.next = node
                    inserted = True
                    break
                tail = tail.next
            if not inserted: # insert at the end
                tail.next = node
        
        return dummy.next


/**
148. Sort List
Solved
Medium
Topics
conpanies iconCompanies

Given the head of a linked list, return the list after sorting it in ascending order.
 */
