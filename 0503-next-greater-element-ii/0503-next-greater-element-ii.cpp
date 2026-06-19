//solution 2 striver

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

// imp is  we are traversing index as twice of nums array (2N), i.e using [i%n]
        for(int i = 2*n-1; i >= 0; i--) {

                while(!st.empty() && st.top() <= nums[i % n]) {
                    st.pop();
                }

                if(i < n) {
                    nge[i] = st.empty() ? -1 : st.top();
                }

                st.push(nums[i % n]);
        }

        return nge;
    }
};