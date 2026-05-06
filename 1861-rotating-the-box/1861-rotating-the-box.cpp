class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> res(n, vector<char>(m));
        //90 deg rotation -> transpose + reverse(every row);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = boxGrid[j][i];
            }
        }
        for(int i=0;i<n;i++){
            reverse(res[i].begin(), res[i].end());
        }


//Apply gravity to let stones fall to lowest possible empty cell in-> USE POINTERS from bottom left
        for (int j = 0; j < m; j++) { // each column
            for(int i=n-1;i>=0;i--){  //bottom to top processing

                if(res[i][j]=='.'){ //empty
                    int nextRowWithStone =-1;

                    for(int k=i-1;k>=0;k--){
                        if(res[k][j]=='*') break; //obstracle
                        if(res[k][j]=='#') { //stone
                            nextRowWithStone = k;
                            break;
                        }
                    }

                    if(nextRowWithStone !=-1){
                        res[nextRowWithStone][j] = '.';
                        res[i][j] = '#';
                    }
                }
            }
        }

        return res;
    }
};

//Time complexity: O(m×n^2)
