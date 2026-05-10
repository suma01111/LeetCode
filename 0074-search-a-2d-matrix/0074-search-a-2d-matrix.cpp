class Solution {
public:
//with help of binary search 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); //row
        int n = matrix[0].size(); //col

        int l = 0 , r = m*n-1; //left and right , starting binary search

        while(l<=r){
            int mid = l + (r-l)/2 ;
            int midElement = matrix[mid/n][mid%n]; // IMP<<<getting actual middle element from 2D matrix, [mid/n][mid%n] gives (i,j) of mid (// convert 1D index -> 2D index) 

            if(midElement == target) {
                return true;}
            else if (midElement < target){
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return false;
    }
};
//row and col are also interconnected so we can convert this into 1D array and then apply binary search