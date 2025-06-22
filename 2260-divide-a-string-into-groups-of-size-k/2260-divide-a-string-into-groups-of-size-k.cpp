class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for(int i=0;i<s.size();i=i+k){
            string temp = s.substr(i,k);

            if(temp.size()<k){
                temp.append(k - temp.size(), fill); //count,what to fill
            }
            res.push_back(temp);
        }
        return res;
    }
};