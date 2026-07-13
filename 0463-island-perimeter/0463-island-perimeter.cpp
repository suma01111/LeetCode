class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int perimeter=0;
        
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    perimeter+=4; //REMMM
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                                perimeter--; //IMPP
                        }
                    }
                } 

            }
        }

        return perimeter;
    }
};
