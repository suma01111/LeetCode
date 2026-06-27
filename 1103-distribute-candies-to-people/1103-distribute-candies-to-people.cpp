class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);

        int give=1;
        int i=0;

        while (candies>0) {
            ans[i]+=min(candies, give);
            candies-=min(candies, give);

            give++;
            i=(i+1)%num_people;
        }

        return ans;
    }
};