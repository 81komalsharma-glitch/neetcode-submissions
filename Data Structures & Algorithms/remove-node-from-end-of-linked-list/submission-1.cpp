class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If we need to delete the head
        if (fast == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // Stop slow one node before the node to delete
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete slow->next
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};