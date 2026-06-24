class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n=cardPoints.size();

        int leftSum=0;

        // take all k cards from left initially
        for (int i=0;i<k;i++)
            leftSum+=cardPoints[i];

        int ans=leftSum;
        int rightSum=0;

        // replace left cards one by one with right cards
        for (int i = 1; i <= k; i++) {

            leftSum-=cardPoints[k - i];
            rightSum+=cardPoints[n - i];

            ans=max(ans,leftSum+rightSum);
        }

        return ans;
    }
};

/*
Try all possibilities:

k from left, 0 from right
k-1 from left, 1 from right
k-2 from left, 2 from right
...
0 from left, k from right

and take the maximum sum.

Time: O(k)
Space: O(1)
*/