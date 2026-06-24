class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int n=num.size();
        int l=0;
        int r=n-1;
        while(l<r){
            if(target==num[l]+num[r]) return {l+1,r+1};
            else if(target > num[l]+num[r] ) l++;
            else r--;
        }

        return {-1,-1};
    }
};