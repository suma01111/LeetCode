class Solution {
    bool dfs(vector<int>& arr, int i,vector<int>& vis){
        if(i<0 || i>=arr.size()) return false; //out of bound

        if(vis[i]) return false; //already visited

        //found zero
        if(arr[i]==0) return true;
        vis[i]=1;

        //try both side jumps
        return dfs(arr,i+arr[i],vis) || dfs(arr,i-arr[i],vis);

    }

public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(),0);
        return dfs(arr,start,vis);
    }
};
    
/*
5
├── 6
│    ├── 8 (invalid)
│    └── 4
│          ├── 7 (invalid)
│          └── 1
│                ├── 3  ← FOUND 0
│                └── -1 invalid
│
└── 4
      ├── 7 invalid
      └── 1
            ├── 3 ← FOUND 0
            └── -1 invalid
*/