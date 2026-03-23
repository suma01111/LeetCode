//Better approach O(n^2)=TC=SC

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows); 

        for(int i=0;i<numRows;i++){
            result[i].resize(i+1);
        }
        result[0][0] = 1; //row 0th

        for(int i=1;i<numRows;i++){
            for(int j=0;j<=i;j++){
                if(j==0) result[i][j]=1; //first element of every row start from (1th)
                else if(i==j) result[i][j]=1; //last element 
                else{
                    result[i][j]=result[i-1][j-1] + result[i-1][j];
                }
            }
        }
        return result;
    }
};