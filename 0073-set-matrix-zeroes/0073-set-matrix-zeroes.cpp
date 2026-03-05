//Optimal , space complexity is O(1) IMP , TC = (MN) same as better 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // Check first row
        for(int j = 0; j < m; j++)
            if(matrix[0][j] == 0)
                firstRowZero = true;
        
        // Check first column
        for(int i = 0; i < n; i++)
            if(matrix[i][0] == 0)
                firstColZero = true;
        
        // Use first row & column as markers
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Set zeros based on markers
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Handle first row
        if(firstRowZero){
            for(int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }
        
        // Handle first column
        if(firstColZero){
            for(int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};