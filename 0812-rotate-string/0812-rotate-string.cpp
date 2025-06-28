class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length()) return false;

        string doubledString = s + s;

        //if find(goal) indeax is less than or we can say found in doubledstring 
        
        return doubledString.find(goal) < doubledString.length();
        //return doubledString.find(goal) != string::npos;

//This searches for the substring goal inside doubledString.
// If found, it returns the index (position) of the first character where it starts.
// If not found, it returns a special constant: string::npos.It represents "not found".It has a very large value (like 2^64 - 1), since it's an unsigned integer.

    }
};