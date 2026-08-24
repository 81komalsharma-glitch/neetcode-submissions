/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Dummy node helps us build the answer
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        // Compare nodes while both lists have elements
        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            // Move tail forward
            tail = tail->next;
        }

        // Attach the remaining nodes
        if (list1 != NULL) {
            tail->next = list1;
        }
        else {
            tail->next = list2;
        }

        return dummy.next;
    }
};
