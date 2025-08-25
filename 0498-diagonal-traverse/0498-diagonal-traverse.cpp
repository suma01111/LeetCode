class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        map<int,vector<int>> mp;
        vector<int> result; 

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i+j].push_back(mat[i][j]);
            }             
        }
        //extracting values from map and alternative resverse order 
        for(auto it : mp){
            if(it.first %2 ==0) {
                reverse(it.second.begin(), it.second.end());
            }

            for(int num : it.second){
                result.push_back(num);
            }
        }
        return result;
    }
};