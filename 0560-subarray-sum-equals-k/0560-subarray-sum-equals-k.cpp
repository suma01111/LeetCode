class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> pSum_cnt;
        pSum_cnt[0] = 1; //prefixSum=0 and cnt = 1;

        int prefixSum = 0;
        int cnt =0;


        for(int i=0;i<nums.size();i++){
            prefixSum+= nums[i];

            int remove = prefixSum - k ;
            cnt+= pSum_cnt[remove];
            pSum_cnt[prefixSum] +=1;
        }
        return cnt;
    }
};