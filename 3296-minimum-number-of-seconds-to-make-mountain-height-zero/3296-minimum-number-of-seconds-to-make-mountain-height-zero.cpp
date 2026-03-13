//Binary search
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l =1; //lowest time

        // int t_max = 0;
        // for(int i=0;i<workerTimes.size();i++){
        //     t_max = max(t_max,workerTimes[i]);
        // }
        int t_max = *max_element(workerTimes.begin(), workerTimes.end());


        long long h = 1LL * t_max * mountainHeight * (mountainHeight + 1) / 2;  //highest time 
        long long result = h;

        while(l<=h){
            long long mid = l+(h-l)/2 ;  //mid time
            if(check(mid,mountainHeight, workerTimes )){ //recursion call;
                result = mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return result;
    }

    bool check(long long midTime, int mountainHeight, vector<int>& workerTimes){
        long long totalHeight = 0; //height
        for(int t : workerTimes){
            //sum of all reducinh height of worker at midTime
            totalHeight += (sqrt((2.0 * midTime) / t + 0.25) - 0.5);
 

            if(totalHeight>=mountainHeight) return true; 
        }
        return  false;//h>=mountainHeight
    }
    
};