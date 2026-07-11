class Solution {
public:
    vector<int> parent, size;

    // Find the ultimate parent (with Path Compression)
    int findParent(int node) {
        if (node==parent[node])
            return node;
        return parent[node]=findParent(parent[node]);
    }

    // Merge two components using Union by Size
    void unionBySize(int pu, int pv) {
        if (size[pu]<size[pv]) {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }

    // Approach:
    // 1. Each account index is treated as a DSU node.
    // 2. Map every email to the first account in which it appears.
    // 3. If an email appears again, union both account indices.
    // 4. After all unions, group emails according to the parent account.
    // 5. Sort emails of each component and prepend the account name.

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();

        parent.resize(n);
        size.assign(n,1);

        for (int i=0;i<n;i++) parent[i]=i;

        unordered_map<string,int> mailToNode;//emailn0,idx of accounts array

        // Map each email to an account
        for (int i=0;i<n;i++) {
            for (int j=1;j<accounts[i].size();j++) {
                string mail=accounts[i][j];

                // First occurrence of this email in map
                if (mailToNode.find(mail)==mailToNode.end()) { //not in map
                    mailToNode[mail]=i; //email -> acc index
                }
                else { //mail exit in map but index is diff
                    int pu=findParent(i);
                    int pv=findParent(mailToNode[mail]);

                    if (pu!=pv)
                        unionBySize(pu,pv); 
                }
            }
        }

        // mails[parent] -> all emails belonging to that component
        vector<vector<string>> mergedMail(n);
        for (auto it: mailToNode) {
            string mail=it.first;
            int node=it.second;

            int parentNode=findParent(node);

            mergedMail[parentNode].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i=0;i<n;i++) {
            if (mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());//sorting every level

            vector<string> temp;
            // Account name
            temp.push_back(accounts[i][0]);

            // All merged emails
            for (auto &mail : mergedMail[i])
                temp.push_back(mail);
            ans.push_back(temp);
        }

        return ans;
    }
};