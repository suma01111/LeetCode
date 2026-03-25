// ✅ Optimal Approach (Moore’s Voting Extended)
// We can have at most 2 elements appearing more than ⌊n/3⌋ times
// So we maintain:
// candidate1, candidate2
// count1, count2

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0, cnt2=0;
        int ele1 = INT_MIN; //candidate 1
        int ele2 = INT_MIN; //candidate 2

        for(int i=0;i<nums.size();i++){

            if(cnt1 ==0 && nums[i]!= ele2){
                cnt1++;
                ele1 = nums[i];
            }

            else if(cnt2 ==0 && nums[i]!= ele1){
                cnt2++;
                ele2 = nums[i];
            }

            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;

            else {
                cnt1--; cnt2--;
            }
        }

        // verification step
        cnt1 = cnt2 = 0;
        for(int num : nums){
            if(num == ele1) cnt1++;
            else if(num == ele2) cnt2++;
        }

        vector<int> ans;
        if(cnt1 > nums.size()/3) ans.push_back(ele1);
        if(cnt2 > nums.size()/3) ans.push_back(ele2);

        return ans;
    }
};