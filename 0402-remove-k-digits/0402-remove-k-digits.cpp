
class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        for(char ch : num) {

            while(!st.empty() && k>0 && (st.top()-'0') > (ch-'0')) {
                st.pop();
                k--;
            }

            st.push(ch);
        }

        // If k still remains
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Stack -> string
        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while(i < ans.size() && ans[i] == '0')
            i++;

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};