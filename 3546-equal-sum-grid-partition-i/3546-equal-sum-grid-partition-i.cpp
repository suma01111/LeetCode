class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long prefix=0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prefix += grid[i][j];
            }
        }

        if(prefix % 2==1){ return false;}

        long long target = prefix/2;

        //horizontal
        long long Rsum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<"x";
                Rsum +=grid[i][j];
            }
            if(Rsum == target) return true;
        }

        //vertical
        long long Csum=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                // cout<<"y";
                Csum +=grid[i][j];
            }
            if(Csum == target) return true;
        }

        return false;
    }
};