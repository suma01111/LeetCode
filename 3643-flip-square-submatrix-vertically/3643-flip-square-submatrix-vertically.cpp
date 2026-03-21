class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        stack<int> st;
        int m = grid.size();
        int n = grid[0].size();

        for(int j=y;j<y+k;j++){
            for(int i=x;i<x+k; i++){
                st.push(grid[i][j]);
            }
            
            int z=x; 
            while(!st.empty()){
                grid[z][j]=st.top();
                z++;
                st.pop();
            }
        }

        return grid;
    }
};