class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
       map<string,int> m; //{arr[i],freq
       int cnt=0;

        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }

        for(string s:arr){
            if(m[s]==1){
                cnt++;
                if(cnt==k) return s;
            }
        }

        return "";
    }
};