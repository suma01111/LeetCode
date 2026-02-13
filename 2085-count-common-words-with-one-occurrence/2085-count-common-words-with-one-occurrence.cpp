class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> m1;
        unordered_map<string,int> m2;

        for(auto w : words1) m1[w]++; //w is string

        for(auto w : words2) m2[w]++;

        int cnt=0;
        for(auto it : m1){
            if(m1[it.first] ==1 && m2[it.first]==1) cnt++;
        }
        return cnt;
    }
};