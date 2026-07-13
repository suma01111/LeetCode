// Judge Conditions // A person is the judge if:
// Everyone else trusts them → indegree = n-1
// They trust nobody → outdegree = 0

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> indegree(n+1,0); //1tonth idxing
        vector<int> outdegree(n+1,0);

        for (auto &t : trust) {
            outdegree[t[0]]++; //u
            indegree[t[1]]++;//v
        }

        for (int i=1;i<=n;i++) {
            if (indegree[i]==n-1 && outdegree[i]==0)
                return i;
        }

        return -1;
        
    }
};
