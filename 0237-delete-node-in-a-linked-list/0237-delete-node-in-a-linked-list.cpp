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
    void deleteNode(ListNode* node) {
        //shifting/updating value of node from its next node
        node->val = node->next->val;  

        ListNode* temp = node->next;
        node->next = node->next->next;

        delete temp;
    }
};