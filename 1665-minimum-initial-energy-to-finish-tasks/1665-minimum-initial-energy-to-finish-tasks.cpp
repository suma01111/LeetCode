
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }


    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp);

        int energy = 0;
        int ans = 0;

        for(auto &task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            // add extra energy if needed
            if(energy < minimum) {
                ans += (minimum - energy);
                energy = minimum;
            }

            // perform task
            energy -= actual;
        }

        return ans;
    }
};