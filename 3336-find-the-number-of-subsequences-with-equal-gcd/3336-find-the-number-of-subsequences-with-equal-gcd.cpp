
class Solution {
public:
    const int MOD=1e9+7;
    int memo[205][201][201];

    int solve(int idx,int g1,int g2,vector<int>& nums){
        if(idx==nums.size()){
            if(g1==g2 && g1!=0)
                return 1;
            return 0;
        }

        if(memo[idx][g1][g2]!=-1)
            return memo[idx][g1][g2];
        long long ans=0;

        // Skip
        ans+=solve(idx+1,g1,g2,nums);

        // Put in seq1
        ans+=solve(idx+1,
                   gcd(g1,nums[idx]),
                   g2,
                   nums);

        // Put in seq2
        ans+=solve(idx+1,
                   g1,
                   gcd(g2,nums[idx]),
                   nums);
        return memo[idx][g1][g2]=ans%MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        return solve(0,0,0,nums);
    }
};