from typing import List, Optional


class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head

        while curr:
            nextTemp = curr.next
            prev = curr
            curr = nextTemp

        return prev

    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        slow = fast = head

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        secondHalf = self.reverseList(slow.next)
        copySecondHalf = secondHalf

        firstHalf = head
        palindrome = True

        while secondHalf:
            if firstHalf.val != secondHalf.val:
                palindrome = False
                break

            firstHalf = firstHalf.next
            secondHalf = secondHalf.next

        slow.next = self.reverseList(copySecondHalf)
        return palindrome
