class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq; //arr, cnt

        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

        int ans = -1;

        // Check if any number appears exactly as many times as its value
        for (auto it : freq) {
            if (it.first == it.second) {
                ans = max(ans, it.first); 
            }
        }

        return ans;
    }
};