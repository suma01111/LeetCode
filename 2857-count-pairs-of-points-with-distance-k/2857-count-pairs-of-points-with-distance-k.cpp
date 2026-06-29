class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {

        unordered_map<long long,int> mp;

        int ans=0;

        for(auto it:coordinates){
            int x1=it[0];
            int y1=it[1];

            for(int i=0;i<=k;i++){
                int x2=x1^i;
                int y2=y1^(k-i);

                long long key=((long long)x2<<32)|y2;
                ans+=mp[key];
            }

            long long key=((long long)x1<<32)|y1;
            mp[key]++;
        }

        return ans;
    }
};