//rotation 90 degree -> Transpose + reverse

class Solution {
public:

    void rotate90(vector<vector<int>>& mat) {
        int n = mat.size();

        // transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }


    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
// k < 4 ? becoz a sq mat has only 4 possible orientations:original,90°,180°,270°
        for(int k = 0; k < 4; k++) {
            if(mat == target) return true; 

            rotate90(mat); // rotate for next check
        }
        return false;
    }
};;