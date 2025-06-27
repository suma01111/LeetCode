class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt =0;
        string result = "";

        for(char ch : s){
            if(ch=='('){
                if(cnt>0) result+=ch;
                cnt++;
            }
            else if(ch == ')'){
                cnt--;
                if(cnt>0) result+=ch;
            }
        }
        return result;
    }
};