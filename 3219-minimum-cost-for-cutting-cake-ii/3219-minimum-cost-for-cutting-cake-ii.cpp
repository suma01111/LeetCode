
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horCut, vector<int>& verCut) {

        sort(horCut.begin(), horCut.end(), greater<int>());
        sort(verCut.begin(), verCut.end(), greater<int>());

        long long cost = 0;

        int horPieces = 1;
        int verPieces = 1;

        int i = 0, j = 0;

        while (i < horCut.size() && j < verCut.size()) {

            if (horCut[i] >= verCut[j]) {
                cost += 1LL * horCut[i] * verPieces;
                horPieces++;
                i++;
            }
            else {
                cost += 1LL * verCut[j] * horPieces;
                verPieces++;
                j++;
            }
        }

        while (i < horCut.size()) {
            cost += 1LL * horCut[i] * verPieces;
            horPieces++;
            i++;
        }

        while (j < verCut.size()) {
            cost += 1LL * verCut[j] * horPieces;
            verPieces++;
            j++;
        }

        return cost;
    }
};