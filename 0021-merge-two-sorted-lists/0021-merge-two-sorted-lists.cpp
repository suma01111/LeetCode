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

        ListNode* dummy = new ListNode(0); //IMP to create---dummy is the first node of LL3 , contain data zero
        ListNode* curr = dummy;

        while (list1 && list2 ){ //(list1 !=nullptr && list2 != nullptr)
            if(list1->val > list2->val){
                curr->next = list2;
                list2 = list2->next;
            }
            else {
                curr->next=list1;
                list1 = list1->next;
            }

            curr=curr->next; //moving curr ptr at every if-else
        }

        
        //remaining nodes
        curr->next = list1 ? list1 : list2; 
                                                    /*if (list1 != nullptr) {cur->next = list1};
                                                    else {cur->next = list2;} */

        //since we create a dummy node (0) , so LL3 will start from dummy->next
        return dummy->next;
    }
};