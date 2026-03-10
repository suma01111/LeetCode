class Solution {
public:

    long long hoursNeeded(vector<int>& piles, int k){
        long long hours = 0;
        
        for(int pile : piles){
            hours += ceil((double)pile / k);
        }
        
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        
        while(low <= high){
            
            int mid = (low + high) / 2;
            
            if(hoursNeeded(piles, mid) <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};