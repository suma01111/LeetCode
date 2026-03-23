//Optimal , space complexity is O(1) IMP , TC = (MN) same as better 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 =1;
        int m = matrix.size();
        int n = matrix[0].size();

        // Mark rows & cols
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0; //update col[0] first

                    if(j!=0){
                        matrix[0][j]=0; //leave zeroth col 
                    }
                    else{
                        col0 =0; //else update 0th col
                    }
                }
            }
        }

        //step 01 : update - traverse submatrix leaving col 0 and row 0
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        //step02: now update row(0th) first
        if(matrix[0][0]==0){
            for(int j=0;j<n;j++) matrix[0][j]=0; //making whole 0th col =0 if mat[0][0]=0
        }

        //step03: now update col(0th)
        if(col0==0){
            for(int i=0;i<m;i++) matrix[i][0]=0;
        }


    }
};