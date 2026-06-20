//Approach 1: Prefix/Suffix MAX Arrays (O(n) Space) i.e LeftMax and RtMAx

//at zero ht ->(Left highest , rt highest)-> final ans is smaller ht from these
//trapping water at each ht -> min(l_max,h_max)- ht of curr bar

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        //Cal LeftMAX, PrefixMax
        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
            leftMax[i]=max(height[i],leftMax[i-1]);
        }

        //Cal rightMAX, SuffixMAx
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i]= max(height[i],rightMax[i+1]);
        }

        //cal Trapping water
        int sum=0;
        for(int i=0;i<n;i++){
            if(height[i]<leftMax[i] && height[i]<rightMax[i]){
                sum+= min(leftMax[i],rightMax[i]) - height[i];
                //cout<<i<<"."<<sum<<endl;
            }
        }

        return sum;
    }
};