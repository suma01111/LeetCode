class Solution {
public:
    string removeOuterParentheses(string s) {
//two if else condition required , focus on cnt increase and decrease
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