#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode temp = new ListNode(0);
  temp->next = head;

  ListNode* fast = temp;
  ListNode* slow = temp;

  for (int i = 0; i <= n; ++i) {
    fast = fast->next;
  }

  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }

  slow->next = slow->next->next;
  return temp->next;
}
