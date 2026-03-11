class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        vector<string> ans;
        string curr;
        helper(n,0,0,ans,curr);
        return ans;
    }

    void helper(int n, int open, int close,vector<string>& ans, string curr){
        //base case
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }

        if(open<n){
            curr.push_back('(');
            helper(n,open+1,close,ans,curr);
            curr.pop_back();
        }

        if(close<open){
            curr.push_back(')');
            helper(n,open,close+1,ans,curr);
            curr.pop_back();
        }
    }
};