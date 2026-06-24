class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m_t;
        for(int c: t) m_t[c]++;

        int cnt=t.size();
        int minLen = INT_MAX;
        int start=0; //remember out we want strinf so this is start
        int l=0;

        for(int r=0;r<s.size();r++){

                //If curr char is still needed,reduce remaining required character count
                if(m_t[s[r]] >0) cnt--;
                m_t[s[r]]--; //Include current character in window

                while(cnt==0){ //Window is valid when count becomes 0
                    if(r-l+1< minLen){
                        minLen=r-l+1;
                        start=l;
                    }

                    m_t[s[l]]++; // Remove leftmost character from window

                    if(m_t[s[l]]>0) cnt++;

                    l++;
                }
        }


        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
