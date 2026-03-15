struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* secondHalf = reverseList(slow->next);
    ListNode* copySecondHalf = secondHalf;

    ListNode* firstHalf = head;
    bool palindrome = true;

    while (secondHalf) {
      if (firstHalf->val != secondHalf->val) {
        palindrome = false;
        break;
      }
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    slow->next = reverseList(copySecondHalf);
    return palindrome;
  }

private:
  ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr) {
      ListNode* nextTemp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nextTemp;
    }
    return prev;
  }
};
