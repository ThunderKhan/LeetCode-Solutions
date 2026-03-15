struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* tempNext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tempNext;
    }
    return prev;
}
