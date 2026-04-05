class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        for(char c : moves){
            if(c == 'U') j++;
            if(c == 'D') j--;
            if(c == 'L') i--;
            if(c == 'R') i++;
        }

        if(i==0 && j==0) return true;
        return false;
    }
};