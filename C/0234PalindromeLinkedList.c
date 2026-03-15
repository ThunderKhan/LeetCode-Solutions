struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
  struct ListNode* prev = NULL;
  struct ListNode* curr = head;

  while (curr != NULL) {
    struct ListNode* nextTemp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextTemp;
  }
  return prev;
}

bool isPalindrom(struct ListNode* head) {
  if (head == NULL || head->next == NULL) return true;

  struct ListNode* slow = head;
  struct ListNode* fast = head;

  while (fast->next != NLL && fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  struct ListNode* secondHalf = reverseList(slow->next);
  struct ListNode* copySecondHalf = secondHalf;
  
  struct ListNode* firstHalf = head;
  bool palindrome = true;

  while (secondHalf != NULL) {
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
