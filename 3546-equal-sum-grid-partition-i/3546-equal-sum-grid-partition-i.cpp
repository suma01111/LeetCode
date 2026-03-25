//optimal O(M*N) , SC=O(M+N);

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long prefix=0;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> row(m,0);
        vector<long long> col(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i] += grid[i][j]; //Understand this IMPP
                col[j] += grid[i][j];//--||--, storing row and col sum in one n^2 loop

                prefix += grid[i][j];
            }
        }

        if(prefix % 2==1){ return false;}

        long long target = prefix/2;

        //horizontal cut
        long long Rsum =0;
        for(int i=0;i<m;i++){
            Rsum += row[i];
            if(Rsum==target) return true;
        }

        //verticatal cut
        long long Csum =0;
        for(int j=0;j<n;j++){
            Csum += col[j];
            if(Csum==target) return true;
        }

        return false;
    }
};