//use priority queue , min heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        unordered_map<int,int> m; // {nums,freq}
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq; //{freq,nums}
        for(auto it : m){
            pq.push({it.second,it.first});
        }

        while(k--){ //Run the loop exactly k times (if k > 0),After each check, decrease k by 1
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};