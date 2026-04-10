class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int> > m; //IMPP
        int n=nums.size();

        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i); //nums[i], [idx1,idx2,idx3...]
        }

        int minii = INT_MAX;
        for(auto it:m){
            vector<int> &v = it.second; //IMPP

            if(v.size()>=3){
                for(int i=0;i+2<v.size();i++){
                    int dist = 2*(v[i+2]-v[i]); //simply formula
                    minii=min(dist,minii);
                }
            }
        }

        return (minii==INT_MAX) ? -1 : minii;
    }
};