
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        // component[i] = connected component of node i
        vector<int> component(n);

        int comp = 0;
        component[0]=0;

        // Build connected components
        for (int i=1;i<n;i++) {
            // Gap too large -> new component
            if (nums[i]-nums[i-1]>maxDiff) comp++;

            component[i]=comp;
        }

        vector<bool> ans;

        // Two nodes are connected iff they belong
        // to the same component.
        for (auto &q : queries) {
            ans.push_back(component[q[0]]==component[q[1]]);
        }

        return ans;
    }
};