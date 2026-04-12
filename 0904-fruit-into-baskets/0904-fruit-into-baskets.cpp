class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;
        int maxii = INT_MIN;
        int cnt=0;
        int leng=0;

        for(int i=0;i<fruits.size();i++){

            if(m.size()>0 && m.find(fruits[i]) != m.end()) {
                cnt++;
                leng++; }

            if(cnt>2) {
                cnt=0;
                maxii = max(leng, maxii);
                leng =0;
            }

            m[fruits[i]]++;
        }

        return leng;
    }
};