class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minii=INT_MAX;

        for (int i=0; i<n;i++) {
            if (words[i]==target) {
                int dist = abs(i - startIndex);
                minii = min(minii, min(dist, n - dist)); 
                //(dist, n - dist) checking right and left side both , 
            }
        }

        if(minii == INT_MAX) return -1;
        return minii;
    }
};