class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        int layer= min(m,n)/2;//layer l
        for(int l=0;l<layer;l++){
            vector<int> arr;

            //top
            for(int i=l;i<n-l;i++){ 
                arr.push_back(grid[l][i]);
            }
            //right
            for(int j=l+1;j<m-l;j++){
                arr.push_back(grid[j][n-l-1]);
            }
            //bottom
            for(int i=n-l-2;i>=l;i--){
                arr.push_back(grid[m-l-1][i]);
            }
            //left
            for(int j=m-l-2;j>l;j--){
                arr.push_back(grid[j][l]);
            }

            int s=arr.size();
            // for(int i=0;i<s;i++){
            //     cout<< arr[i]<<",";
            // }
            vector<int> rot(s,0);
            for(int i=0;i<s;i++){
                rot[i]=arr[ (i+k)%s ];
            }

            int idx=0;

            //push back rotated array values to grid
            //top
            for(int i=l;i<n-l;i++){ 
                grid[l][i] = rot[idx];
                idx++;
            }
            //right
            for(int j=l+1;j<m-l;j++){
                grid[j][n-l-1] = rot[idx];
                idx++;
            }
            //bottom
            for(int i=n-l-2;i>=l;i--){
                grid[m-l-1][i] = rot[idx];
                idx++;
            }
            //left
            for(int j=m-l-2;j>l;j--){
                grid[j][l] = rot[idx];
                idx++;
            }

            // for(int i=0;i<m;i++){
            //     for(int j=0;j<n;j++){
            //         cout<<grid[i][j]<<",";
            //     }
            // }

        }


        return grid;
    }
};