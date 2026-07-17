struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
    if ((head == NULL) || (head->next == NULL)) {
        return NULL;
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    return head;
}