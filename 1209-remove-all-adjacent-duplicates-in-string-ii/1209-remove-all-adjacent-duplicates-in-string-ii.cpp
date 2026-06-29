// Use a stack of: pair<char, int>
// first = character
// second = count of consecutive occurrences

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;

        for (char ch:s) {
            if (!st.empty() && st.top().first==ch) {
                st.top().second++;

                if(st.top().second==k)
                    st.pop();
            }
            else {
                st.push({ch,1});
            }
        }

        string ans = "";
        while (!st.empty()) {
            //IMPPP , ans.append(count, character);
            ans.append(st.top().second,st.top().first); 
            //ans.append(2, 'a');becomes ans = "aa"
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};