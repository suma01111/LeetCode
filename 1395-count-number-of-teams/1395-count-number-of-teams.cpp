// Approach 1: Fix the Middle Soldier (Optimal for n ≤ 1000)
// Instead of choosing all (i, j, k), fix the middle soldier j.

// For every j, count:

// leftSmaller = elements before j that are smaller.
// leftGreater = elements before j that are greater.
// rightGreater = elements after j that are greater.
// rightSmaller = elements after j that are smaller.

// Then
// Increasing teams = leftSmaller * rightGreater
// Decreasing teams = leftGreater * rightSmaller

// Add both.

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;

        for (int j = 0; j < n; j++) {

            int leftSmaller = 0, leftGreater = 0;
            int rightSmaller = 0, rightGreater = 0;

            // Left side
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j])
                    leftSmaller++;
                else
                    leftGreater++;
            }

            // Right side
            for (int k = j + 1; k < n; k++) {
                if (rating[k] > rating[j])
                    rightGreater++;
                else
                    rightSmaller++;
            }

            ans += leftSmaller * rightGreater;
            ans += leftGreater * rightSmaller;
        }

        return ans;
    }
};