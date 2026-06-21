class Solution {
public:

    bool valid(long long sum, int x){
        if(sum % 10 != x)
            return false;
        while(sum >= 10) //Remember
            sum /= 10;

        return sum == x;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++){
            long long sum = 0;
            for(int j = i; j < nums.size(); j++){
                sum += nums[j];

                if(valid(sum, x))
                    cnt++;
            }
        }

        return cnt;
    }
};