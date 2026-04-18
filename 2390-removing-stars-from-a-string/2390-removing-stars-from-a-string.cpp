class Solution {
public:
    string removeStars(string s) {
        stack<int> st;

        // process string into stack
        for(int i=0;i<s.size();i++){
            if(s[i]=='*') {
                if(!st.empty()) st.pop();
                }
            else st.push(s[i]);
        }

        string ans = "";
        while(!st.empty()){ //build answer from stack
            ans.push_back(st.top());
            st.pop();
        }


        reverse(ans.begin(),ans.end());
        return ans;
    }
};