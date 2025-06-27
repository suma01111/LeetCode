class Solution {
public:
    string removeOccurrences(string s, string part) {

        while(s.size()>0 && s.find(part)<s.length()){
            s.find(part);
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

//2 step Q
// string.find(part) will give you first occurence index
//string.erase , will remove that part from s