class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n,-1);
        
// imp is  we are traversing index as twice of nums array (2N), i.e using [i%n]
        for(int i=(2*n-1); i>=0;i--){
            while(s.size()>0 &&  nums[i%n]>= s.top()){
                s.pop();
            }
            if(s.empty()) ans[i%n] = -1;
            else ans[i%n] = s.top();

            s.push(nums[i%n]);
        }
        return ans;
    }
};