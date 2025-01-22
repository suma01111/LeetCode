class Solution {
    //checking if x and y corsinate is valid or not
    bool isValid(int& x, int& y,int& m,int& n){
        return(x>=0 and x<m and y>=0 and y<n);
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>> q; //row,col
        int m = isWater.size();
        int n = isWater[0].size();

        //height matrix
        vector<vector<int>> height(m,vector<int>(n,0));

        //step1 : push all source points  in queue 
        vector<vector<int>> visited(m,vector<int>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push(make_pair(i,j));
                    visited[i][j]= true;
                }
            }
        }

        //step2: Multi-source BFS LevelOrder
        vector<int> dir = {-1,0,1,0,-1}; //4 -directional call: URDL
        int level =0;
        while(!q.empty()){
            int size= q.size();
            for(int i=0;i<size;i++){
                pair<int,int> curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                for(int d=0;d<4;d++){
                    int newX = x + dir[d];
                    int newY = y + dir[d+1];

                    if(isValid(newX,newY,m,n) and !visited[newX][newY]){
                        q.push(make_pair(newX,newY));
                        height[newX][newY]=1+level;
                        visited[newX][newY] = true;
                    }
                }
            }
            level++;
        }
        return height;
    }
};