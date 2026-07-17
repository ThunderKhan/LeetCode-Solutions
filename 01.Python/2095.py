from typing import Optional

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = None
    
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if ((head is None) or (head.next is None)):
            return None
        
        slow = head
        fast = head
        prev = None

        while ((fast) and (fast.next)):
            prev = slow
            slow = slow.next
            fast = fast.next.next
        
        prev.next = slow.next

        return head