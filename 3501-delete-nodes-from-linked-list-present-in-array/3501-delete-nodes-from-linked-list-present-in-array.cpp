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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(int i=0; i<nums.size();i++){
            st.insert(nums[i]);
        }
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
        if(st.find(head->val) != st.end()) {
            head = head->next;
            }
            curr = curr->next;
        }

        curr = head->next;
        prev=head;
        
        while(curr){
            if(st.find(curr->val) != st.end()){
                prev->next = curr->next;
                curr=prev->next;
                
            }
            else{
                prev=prev->next;
                curr =curr->next;
            }
        }

        return head;
    }
};

















/*class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        boolean set[] = new boolean[(int)1e5+1]; 
        for(int num : nums){
            set[num] = true;
        }
        ListNode prev = null;
        ListNode cur = head;
        while(cur!=null){
            if(set[cur.val]==true){
                if(prev == null){ //del at head
                    head = head.next;
                    cur.next = null;
                    cur = head;
                }else{ 
                    prev.next = cur.next;
                    cur.next = null;
                    cur = prev.next;
                }
            }else{
                prev = cur;
                cur = cur.next;
            }
        }
        return head;        
    }
};*/