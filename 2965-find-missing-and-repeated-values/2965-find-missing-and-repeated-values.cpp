//better apporach, TC=SC= O(m × n)

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;

        int m = grid.size();
        int n = grid[0].size();

        //build map from 1 to m*n
        for(int i=1;i<=m*n;i++){
            cout<<'1';
            mp[i]++;
        }

        //traversing map, incresing freq if matched in map
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<'2';
                mp[grid[i][j]]++;
            }
        }

        int repeating =-1, missing=-1;
        for(auto it : mp){
            cout<<'3';
            if(it.second == 1) missing = (it.first);            //missed
            else if(it.second == 3) repeating = (it.first);     //repeated
            else continue;
        }

        return {repeating,missing};
    }
};