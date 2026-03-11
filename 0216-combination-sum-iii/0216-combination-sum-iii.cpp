class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans; 
        vector<int> curr;
        int sum=0;
        int temp =1;
        helper(0,k,n,ans,curr,0,1);
        return ans;
    }

    void helper(int t,int k, int n , vector<vector<int>>& ans, vector<int>& curr,int sum, int temp){
        //base
        if(t==k){
            if(sum == n) {
                ans.push_back(curr);
                cout<<'hello';
                return ;
                }
            else return;
        }

        for(int i=temp;i<=9;i++){
            cout<<t;
            curr.push_back(i);
            sum+= curr.back();
            helper(t+1,k,n,ans,curr,sum,i+1);
            sum-=curr.back();
            curr.pop_back();

        }
    }
};