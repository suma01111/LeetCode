//Approach (Using same concept as finding subarrays having all 1s in a 1D Array)
//T.C : O(m * m * n)
//S.C : O(n)

class Solution {

    int OnedArrayCount(vector<int>& vec) {
        int cons = 0;
        int subCount = 0;

        for(int &val : vec) {
            if(val == 0) {
                cons = 0;
            } else {
                cons++;
            }

            subCount += cons;
        }

        return subCount;
    }

public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(); //row
        int n = mat[0].size(); //col
        int result =0;

        for(int startRow = 0; startRow<m ; startRow++){

            vector<int> vec(n, 1); //columns
            for(int endRow=startRow ; endRow<m; endRow++){
                for(int col = 0; col < n; col++) {
                    vec[col] = vec[col] & mat[endRow][col];
                }

                result += OnedArrayCount(vec);
            }
        }
        return result;
    }
};
