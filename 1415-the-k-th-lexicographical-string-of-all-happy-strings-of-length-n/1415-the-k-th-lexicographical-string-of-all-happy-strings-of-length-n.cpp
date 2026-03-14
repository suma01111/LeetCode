//the total number of happy strings is: 3 * 2^(n-1), TC=O(2^n)
class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> res;
        string curr="";
        helper(n,curr,res);

        if(res.size()<k) return "";
        return res[k-1];
    }


    void helper(int n,string& curr,vector<string>& res){
        //base case
        if(curr.size()==n){
            res.push_back(curr);
            return;
        }
        for(char ch : {'a','b', 'c' }){
            if(curr.empty() || curr.back()!=ch){
                curr.push_back(ch);
                helper(n,curr,res);
                curr.pop_back(); //backtrack
            }
        }
        
    }
};

/*
"" → a → ab → aba
               abc
        → ac → aca
               acb so on..
*/