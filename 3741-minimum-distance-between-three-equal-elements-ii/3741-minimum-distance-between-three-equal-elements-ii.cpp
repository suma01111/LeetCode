class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }

        int minii=INT_MAX;
        for(auto it: m){
            vector<int> v=it.second;

            if(v.size()>=3){
                for(int i=0;i+2<v.size();i++){
                    int dist = 2*(v[i+2]-v[i]);
                    minii = min(minii,dist);
                }
            }
        }

        if(minii == INT_MAX) return -1;
        return minii;
    }
};