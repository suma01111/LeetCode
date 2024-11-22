class Solution {
public:
    int romanToInt(string s) {
        int result =0;
        unordered_map<char,int> roman={
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        for (int i=0;i<s.size();i++){
            if(roman[s[i]]<roman[s[i+1]]){
                result-=roman[s[i]];
            }
            else {
                result+=roman[s[i]];
            }
        }
        return result;
    }
};

/* example MCMXCIV
i=0; M -> 1000
i=1; M-C =900
i=2; 900+1000=1900
i=3; 1900-10 = 1890
i=4 ; 1890+100= 1990
i=5; 1990 -1=1899
i=6; 1899+5=1994
*/