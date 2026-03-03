# Time: O(n)
# Space: O(1)
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        size = 0
        h = head
        while h:
            size += 1
            h = h.next
        
        n = size - n # nth node from beginning of list will be deleted
        
        dummy = ListNode(0, head)
        tail = dummy

        while n > 0:
            n -= 1
            tail = tail.next
            tail = tail

        tail.next = tail.next.next
        return dummy.next



/**
19. Remove Nth Node From End of List
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []
 */
