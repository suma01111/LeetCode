class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int startVal=1;
        int n=nums.size();

        while(true){
            int sum=startVal;
            bool ok = true;
            for(int j=0;j<n;j++){
                sum+=nums[j];
                if(sum<1){
                    ok=false;
                    break;
                } 
            }
            if(ok) return startVal;
            startVal++;
        }

        return -1;
    }
};