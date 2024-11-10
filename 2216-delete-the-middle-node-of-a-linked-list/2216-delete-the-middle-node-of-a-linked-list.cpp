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
    ListNode* deleteMiddle(ListNode* head) {

        if (!head || !head->next) {
            return nullptr;
        }

        ListNode* temp = head;
        int cnt = 0;

        while(temp){
            temp=temp->next ;
            cnt++;
        }

        int mid = cnt/2 ;
        ListNode* tempt = head;
        ListNode* prev = NULL;
        
            for(int i=0;i<mid ; i++){
                prev = tempt;
                tempt=tempt->next;
            }
            prev->next = tempt->next;
            delete tempt;
        

        return head;
    }
};