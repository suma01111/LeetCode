class Solution {

public:
    bool ceil(vector<int>& piles, int h, int mid, int cnt){
        for(int i=0;i<piles.size();i++){
            cnt += piles[i] / mid; //give you divisor

            if(piles[i]%mid !=0) cnt++; 
            //% give you remainder (if R is thier then add 1)

            if(cnt > h) return false; //IMP, will help to avoid overflow
        }
        return cnt <= h;
    }


public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r= *max_element(piles.begin(),piles.end());

        while(l<=r){
            int mid = l+(r-l)/2;

            if(ceil(piles,h,mid,0)){ //IMP, if true, cnt <=h
                r=mid-1;
            }
            else l=mid+1; 
        }

        return l;
    }
};