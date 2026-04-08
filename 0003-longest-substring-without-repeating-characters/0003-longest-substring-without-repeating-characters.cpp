//brute force 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int maxii = 0;

        while(i<s.size()){
            int cnt=0;
            set<char> st;
            for(int j=i;j<s.size();j++){
                if(st.find(s[j])==st.end()){
                    st.insert(s[j]);
                    cnt++;
                }
                else break;
                maxii = max(maxii,cnt);
            }

            i++;
        }

        return maxii;
    }
};