class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> charMap;

        //base case
        if(s.size() != t.size()) return false;

        //loop to iterate and compare both s and t
        for(int i =0;i<s.size();i++){
            char original = s[i]; //key
            char replacement = t[i]; //value

            //mapping char if they dont exit yet 
            if(charMap.find(original) == charMap.end()){
                //for (pair<char, char> pair : charMap)
                for( auto pair : charMap)  {
                    if(pair.second == replacement) return false;
                }
                charMap[original] = replacement; //key->value
            }

            //exit mapping didnt match
            else {
                if (charMap[original] != replacement) {
                    return false;
                }
            }
        }
    return true;
    }
};