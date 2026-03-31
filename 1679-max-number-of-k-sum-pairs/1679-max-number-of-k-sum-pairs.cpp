class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // sort first
        
        int i = 0, j = nums.size() - 1; //two pointers
        int cnt = 0;

        while(i < j) {
            int sum = nums[i] + nums[j];

            if(sum == k) {
                cnt++;
                i++;
                j--;
            }
            else if(sum < k) {
                i++;
            }
            else {
                j--;
            }
        }

        return cnt;
    }
};