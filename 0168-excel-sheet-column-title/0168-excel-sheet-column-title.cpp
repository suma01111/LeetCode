class Solution {
public:
    string convertToTitle(int colNum) {
        string ans;
        while(colNum>0){
            colNum --;

            int remainder = colNum%26;
            ans+= remainder +'A';
            colNum = colNum/26;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};