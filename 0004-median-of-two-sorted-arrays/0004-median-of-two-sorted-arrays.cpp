class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> ans;
        
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]>nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }
            else {
                ans.push_back(nums1[i]);
                i++;
            }
        }

        //remaining
        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            ans.push_back(nums2[j]); 
            j++;
        }


        int s = ans.size();
        double N=0;
        if(s%2==1) N = ans[s/2]; //odd
        else N = (ans[s/2]+ans[s/2 - 1]) / 2.00; //even

        return N;
    }
};