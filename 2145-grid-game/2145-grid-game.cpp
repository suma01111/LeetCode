class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        #define ll long long

        int n = grid[0].size();
        if(n < 2) return 0;

        ll top_sum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        ll bottom_sum = 0;
        ll min_sum = LONG_MAX;
        
        // pp is partition pt where row one move to row2
        for(int pp=0;pp<n;pp++){
            top_sum -= grid[0][pp];
            min_sum = min(min_sum , max(top_sum,bottom_sum));
            bottom_sum += grid[1][pp]; 
        }
        return min_sum;
    }
};