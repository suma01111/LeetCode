class Solution {
    #define ll long long
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll , vector<ll>, greater<ll>> min_heap(nums.begin(),nums.end());

    int cnt=0;

    while(min_heap.top()<k){
        ll x = min_heap.top();
        min_heap.pop();
        ll y = min_heap.top();
        min_heap.pop();
        min_heap.push(min(x,y)*2 + max(x,y));
        cnt++;
    }

        return cnt;
    }
};