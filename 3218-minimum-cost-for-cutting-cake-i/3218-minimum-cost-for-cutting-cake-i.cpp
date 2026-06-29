class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {

        int horizontalCuts=horizontalCut.size();
        int verticalCuts=verticalCut.size();

        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());
        sort(verticalCut.begin(),verticalCut.end(),greater<int>());

        int i=0; // Index for horizontal cuts
        int j=0; // Index for vertical cuts

        int horizontalPieces=1;
        int verticalPieces=1;

        int result = 0;//cost

        while (i<horizontalCuts && j<verticalCuts) {//i=m-1, j=n-1

            if (horizontalCut[i]>=verticalCut[j]) {
                result+= horizontalCut[i] *verticalPieces;
                horizontalPieces++;
                i++;
            } 
            else {
                result+=verticalCut[j] *horizontalPieces;
                verticalPieces++;
                j++;
            }
        }

        while (i<horizontalCuts) {
            result+=horizontalCut[i] * verticalPieces;
            horizontalPieces++;
            i++;
        }

        while (j<verticalCuts) {
            result += verticalCut[j] * horizontalPieces;
            verticalPieces++;
            j++;
        }

        return result; //cost
    }
};