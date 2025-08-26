class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = -1;  // store max diagonal squared
        int maxArea = -1;  // store max area for tie cases

        for (auto& rect : dimensions) {
            int w = rect[0], h = rect[1];
            int diag = w*w + h*h;   // diagonal squared
            int area = w*h;         // area

            // check if we found a better rectangle
            if (diag > maxDiag || (diag == maxDiag && area > maxArea)) {
                maxDiag = diag;
                maxArea = area;
            }
        }
        return maxArea;
    }
};