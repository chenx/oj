# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class HeapNode:
    def __init__(self, node: ListNode):
        self.node = node
    
    def __lt__(self, other):
        return self.node.val < other.node.val

import heapq

class Solution2:
    def mergeKLists(self, lists: list[[ListNode]]) -> [ListNode]:
        minHeap = []

        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(minHeap, HeapNode(lists[i]))
        
        dummy = ListNode()
        tail = dummy
        while len(minHeap) > 0:
            heapNode = heapq.heappop(minHeap)
            node = heapNode.node
            if node.next:
                heapq.heappush(minHeap, HeapNode(node.next))
            
            tail.next = node
            tail = node

            node.next = None

        return dummy.next




class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

import heapq
class Solution:
    def mergeKLists(self, lists: list[[ListNode]]) -> [ListNode]:
        # use minHeap
        minHeap = []

        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(minHeap, (lists[i].val, lists[i]))
        
        dummy = ListNode()
        tail = dummy
        while len(minHeap) > 0:
            val, node = heapq.heappop(minHeap)
            if node.next:
                heapq.heappush(minHeap, (node.next.val, node.next))
            
            tail.next = node
            tail = node

            node.next = None

        return dummy.next

s = Solution()
lists = [
    ListNode(1, ListNode(6)),
    ListNode(2, ListNode(3, ListNode(5))),
]
x = s.mergeKLists(lists)
while x:
 print(x.val)
 x = x.next


/**
23. Merge k Sorted Lists
Solved
Hard
Topics
conpanies iconCompanies

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
 */
