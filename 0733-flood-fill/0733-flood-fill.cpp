// Store the original color.
// If original color is already equal to color, return the image.
// Start DFS from (sr, sc).
// Visit only valid neighbours having the original color.
// Recolor them and continue DFS.

class Solution {
    
    void dfs(int row, int col, vector<vector<int>>& image, int oldColor, int newColor){
        // Mark current cell as recolored (also acts as visited)
        image[row][col]= newColor;

        int dr[]={-1,+1,0,0};
        int dc[]={0,0,-1,+1};

        int n=image.size();
        int m=image[0].size();

        for(int k=0;k<4;k++){
            int nr=row+dr[k];
            int nc=col+dc[k];

            if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc]==oldColor){
                dfs(nr,nc,image,oldColor,newColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];
        if(oldColor==color) return image;// Prevent infinite recursion

        dfs(sr,sc,image,oldColor,color);

        return image;
    }
};