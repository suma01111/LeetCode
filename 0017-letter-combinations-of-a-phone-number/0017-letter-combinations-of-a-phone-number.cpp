class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> arr = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string> ans;
        string curr;

        helper(digits,ans,arr,0, curr);
        return ans;
    }

    void helper(string digits, vector<string>& ans, vector<string> &arr, int i,string curr){
        
        //base case 
        if(i==digits.size()) {
            ans.push_back(curr);
            return;
            }
        
        int key = digits[i] - '0';

        for(auto it : arr[key]){
            curr.push_back(it);
            helper(digits,ans,arr,i+1,curr);
            curr.pop_back();
        }

        
    }
};