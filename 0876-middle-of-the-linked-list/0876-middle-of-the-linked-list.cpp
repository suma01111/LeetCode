//by me : TC=O(2N), SC=O(1)

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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int cnt=0;

        if(head == NULL)return NULL;

        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }

        temp = head;

        if(cnt % 2 ==1){
            int odd = 1;
            while(odd< (cnt+1)/2){
                temp = temp->next;
                odd++;
            }
            return temp;
        }

        if(cnt%2==0){
            int even = 1;
            while(even < (cnt/2 + 1)){
                temp=temp->next;
                even++;
            }
            return temp;
        }
        return head;
    }
};