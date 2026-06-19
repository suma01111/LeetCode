class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> s; //to find NG element

        //finding NG element of nums2 arr
        for(int i=nums2.size()-1;i>=0;i--){

            while(s.size()>0 && nums2[i]>= s.top()){ //IMP while loop
                s.pop();
            }

            if(s.empty())      m[nums2[i]] = -1 ;
            else               m[nums2[i]] = s.top();

            s.push(nums2[i]);
        }

        //taking reference with help of map
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(m[nums1[i]]);
        }

        return ans;
    }
};