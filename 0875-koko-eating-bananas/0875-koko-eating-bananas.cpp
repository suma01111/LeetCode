class Solution {

public:
    long long ceil(vector<int>& piles, int h, int mid, long long cnt){
        for(int i=0;i<piles.size();i++){
            cnt += ((long long)piles[i] + mid - 1) / mid; //piles[i]% mid;NOT THIS
        }
        return cnt;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r= *max_element(piles.begin(),piles.end());

        while(l<=r){
            int mid = l+(r-l)/2;

            long long hours = ceil(piles,h,mid,0);//IMPP

            if(hours > h){
                l=mid+1;
            }
            else r=mid-1; 
        }

        return l;
    }
};