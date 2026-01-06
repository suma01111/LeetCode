class Solution {
public:

    void getAllParts(string s, vector<string>& partitions, vector<vector<string>>& ans){
        //base case
        if(s.size()==0){
            ans.push_back(partitions);
            return;
        }
        //taking parts of string and then backtrack
        for(int i=0;i<s.size(); i++){
            string part= s.substr(0,i+1);
            if(isPalin(part)){
                partitions.push_back(part);
                getAllParts(s.substr(i+1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    //checking palindrome
    bool isPalin(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s2==s;
    }

    //main func
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);
        return ans;
    }
};