/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = 0;
    temp->next = head;

    struct ListNode *slow = temp;
    struct ListNode *fast = temp;

    for (int i = 0; i <= n && fast != NULL; ++i) {
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    struct ListNode* newHead = temp->next;
    free(temp);

    return newHead;
}
