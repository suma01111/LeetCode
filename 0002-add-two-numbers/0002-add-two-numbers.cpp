/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head for the result list
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            // Add values from l1 and l2 if they exist
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Calculate the new digit and update the carry
            carry = sum / 10;
            int newDigit = sum % 10;

            // Append newDigit to the result list
            current->next = new ListNode(newDigit);
            current = current->next;
        }

        // Return the result list (skip dummy head)
        return dummyHead->next;
    }
};
