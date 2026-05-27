class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
// If the current element is greater than the target, move left to the next column (because elements to the left are smaller).

// If the current element is less than the target, move down to the next row (because elements below are larger). --- O(m+n)
        
        //base case
        if(matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size(); //row
        int n = matrix[0].size(); //col
        
        // Start at the top-right corner
        int i=0 , j =n-1;  

        while(i<m && j>=0) {
            int curr = matrix[i][j];

            if(curr == target){
                return true;
            }
            else if (curr > target){
                j--; //col decrease
            }
            else {
                i++; //row increase
            }
        }
        return false;
    }
};