/**
Approach
    Base case:Empty list or one node → already sorted.
    Find the middle using slow & fast pointers.
    Split the list into two halves.
    Recursively sort both halves.
    Merge the two sorted lists.
    Return merged head.
 */

class Solution {

    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        // Attach remaining nodes
        if (left)
            tail->next = left;
        else
            tail->next = right;

        return dummy.next;
    }

public:
    ListNode* sortList(ListNode* head) {
        // Base case
        if (!head || !head->next)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two halves
        ListNode* right = slow->next;
        slow->next = nullptr;

        ListNode* left = head;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge sorted halves
        return merge(left, right);
    }
};
