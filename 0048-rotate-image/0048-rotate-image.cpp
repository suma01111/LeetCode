class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose and reverse then

        
        int row = matrix.size();
        for(int i=0;i<row;i++){//rows
            for(int j=0;j<i;j++){//coloums
                swap(matrix[i][j], matrix[j][i]); //transpose Cij <-> Cji
            }
        }
        for(int i=0;i<row;i++){ //reversing row
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};