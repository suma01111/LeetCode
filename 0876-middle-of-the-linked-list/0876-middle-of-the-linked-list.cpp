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

 //BY me
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int n=0;
        while(curr!=NULL){
            curr =curr->next;
            n++;
        }

        curr = head;
        if(n%2==1){
            int odd=0;
            while(odd<n/2){
                curr=curr->next;
                odd++;
            }
            return curr;
        }

        else{
            int even=0;
            while(even < n/2){
               curr=curr->next;
                even++;
            }
            return curr;
        }

        return head;
    }
};