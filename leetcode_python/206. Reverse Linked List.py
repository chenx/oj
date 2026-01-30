# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        t = None
        while head:
            tmp = head
            head = head.next
            tmp.next = t
            t = tmp
        
        return t

/**
206. Reverse Linked List
Solved
Easy
Topics
conpanies iconCompanies

Given the head of a singly linked list, reverse the list, and return the reversed list.
 */
