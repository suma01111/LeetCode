class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& as) {
        long long sum=mass;
        sort(as.begin(), as.end());

        for(int i=0;i<as.size();i++){
            if(sum>=as[i]){
                sum+=as[i];
            }
            else {
                return false;
            }
        }
        return true;
    }
};