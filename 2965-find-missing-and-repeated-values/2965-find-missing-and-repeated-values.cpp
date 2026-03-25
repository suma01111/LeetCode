//better apporach, TC=SC= O(m × n)

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mp;

        int m = grid.size();
        int n = grid[0].size();


        for(int i=1;i<=m*n;i++){
            cout<<'1';
            mp[i]++;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<'2';
                mp[grid[i][j]]++;
            }
        }

        int repeating =-1, missing=-1;
        for(auto it : mp){
            cout<<'3';
            if(it.second == 1) missing = (it.first);
            else if(it.second == 3) repeating = (it.first);
            else continue;
        }

        return {repeating,missing};
    }
};