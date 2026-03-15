public class ListNode {
  int val;
  ListNode next;
  ListNode() {}
  ListNode(int val) { this.val = val; }
  ListNode(int val, ListNode) { this.val = val; this.next = next; }
}

class Solution {
  private ListNode reverseList(ListNode head) {
    ListNode prev = null;
    ListNode curr = head;

    while (curr) {
      ListNode nextTemp = curr.next;
      curr.next = prev;
      prev = curr;
      curr = nextTemp;
    }

    return prev;
  }

  public boolean isPalindrome (ListNode head) {
    if (!head || !head.next) return true;

    ListNode slow = head;
    ListNode fast = head;

    while (fast.next && fast.next.next) {
      slow = slow.next;
      fast = fast.next.next;
    }

    ListNode secondHalf = reverseList(slow.next);
    ListNode copySecondHalf = secondHalf;

    ListNode firstHalf = head;
    boolean palindrome = true;

    while (secondHalf) {
      if (firstHalf.val != secondHalf.val) {
        palindrome = false;
        break;
      }
      firstHalf = firstHalf.next;
      secondHalf = secondHalf.next;
    }

    slow.next = reverseList(copySecondHalf);
    return palindrome;
  }
}
