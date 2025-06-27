
class Solution {
public:
    int maxDepth(string s) {
        int currDepth =0;
        int maxDepth = 0;

        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                currDepth++;
                maxDepth = max(maxDepth, currDepth);
            }
            if(s[i]==')') currDepth--;
        }
        return maxDepth;
    }
};