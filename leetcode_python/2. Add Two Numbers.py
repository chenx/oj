class Solution2:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def add(sum, tail):
            if sum >= 10:
                sum -= 10
                carry = 1
            else:
                carry = 0
            
            tail.next = ListNode(sum)
            tail = tail.next
            return carry, tail  # tail is passed by value, it must be returned.

        dummy = ListNode()
        tail = dummy
        carry = 0

        while l1 and l2:
            carry, tail = add(l1.val + l2.val + carry, tail)
            l1, l2 = l1.next, l2.next
        
        while l1:
            carry, tail = add(l1.val + carry, tail)
            l1 = l1.next
        
        while l2:
            carry, tail = add(l2.val + carry, tail)
            l2 = l2.next
        
        if carry == 1:
            carry, tail = add(carry, tail)
        
        return dummy.next
        


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def add(sum):
            if sum >= 10:
                sum -= 10
                carry = 1
            else:
                carry = 0
            return sum, carry

        dummy = ListNode()
        tail = dummy
        carry = 0

        while l1 and l2:
            sum, carry = add(l1.val + l2.val + carry)
            tail.next = ListNode(sum)
            tail = tail.next
            l1, l2 = l1.next, l2.next
        
        while l1:
            sum, carry = add(l1.val + carry)
            tail.next = ListNode(sum)
            tail = tail.next
            l1 = l1.next
        
        while l2:
            sum, carry = add(l2.val + carry)
            tail.next = ListNode(sum)
            tail = tail.next
            l2 = l2.next
        
        if carry == 1:
            tail.next = ListNode(carry)
            tail = tail.next
        
        return dummy.next
        



/**
2. Add Two Numbers
Solved
Medium
Topics
conpanies iconCompanies

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */
