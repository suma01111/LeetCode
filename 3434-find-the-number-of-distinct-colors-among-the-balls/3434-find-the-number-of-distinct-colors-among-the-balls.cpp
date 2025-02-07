#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        unordered_map<int, int> ballMap;  // Stores ball -> color
        unordered_map<int, int> colorMap; // Stores color -> frequency

        for (int i = 0; i < n; i++) {
            int ball = queries[i][0], color = queries[i][1];

            // If ball already has a color, remove the old color from frequency map
            if (ballMap.count(ball)) {
                int prevColor = ballMap[ball];
                colorMap[prevColor]--;

                // Remove color if no balls have it anymore
                if (colorMap[prevColor] == 0) 
                    colorMap.erase(prevColor);
            }

            // Paint the ball with new color
            ballMap[ball] = color;
            colorMap[color]++;

            // Store the count of distinct colors
            result[i] = colorMap.size();
        }
        return result;
    }
};
