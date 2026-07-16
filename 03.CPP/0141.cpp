#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr ||  head->next == nullptr) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-1);
    
    head->next->next->next->next = head->next;

    Solution sol;

    std::cout << std::boolalpha << sol.hasCycle(head) << "\n";
    return 0;
}