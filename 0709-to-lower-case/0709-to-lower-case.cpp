// Uppercase (A–Z): 65–90
// Lowercase (a–z): 97–122
// 97-65=32

class Solution {
public:
    string toLowerCase(string s) {
        string result = "";

        for(auto it: s){
            if(it>=65 && it<=90){
                result += it+32;
            }
            else result+= it;
        }


        return result;
    }
};