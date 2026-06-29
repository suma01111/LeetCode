class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();       
        int n=grid[0].size();   

        vector<vector<int>> temp(m,vector<int>(n,0));

        for (int r=0;r<m;r++) {
            for (int c=0;c<n;c++) {

                // Convert (r, c) to 1D index and shift by k
                int newVal = ((r*n + c)+k) % (m*n); 
                //row*totalNum of Col + current col -> give you idx in 1D, to shift +k

                // Convert shifted 1D index back to 2D coordinates
                int newr=newVal/n;
                int newc =newVal%n;

                temp[newr][newc]=grid[r][c];
            }
        }

        return temp;
    }
};