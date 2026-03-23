//optimal TC=O(N^2) , SC = O(1)

class Solution {
public:
    vector<int> generateRow(int row) {
        vector<int> ans;

        int val = 1;
        ans.push_back(val);

        for(int col = 1; col < row; col++){
            val = val * (row - col) / col; //IMP
            ans.push_back(val);
        }

        return ans;
    }



    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for(int i = 1; i <= numRows; i++){
            result.push_back(generateRow(i)); //get every row 
        }

        return result;
    }
};