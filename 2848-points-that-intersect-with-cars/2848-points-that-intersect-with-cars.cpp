class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> fullarr(101,0);

        for(auto it : nums){
            int start=it[0];
            int end=it[1];

            for(int i=start;i<=end;i++){
                fullarr[i]=1;
            }
        }

        int cnt=0;
        for(int i=0;i<101;i++){
            if(fullarr[i]==1) cnt++;
        }

        return cnt;
    }
};