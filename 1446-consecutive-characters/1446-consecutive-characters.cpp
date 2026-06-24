class Solution {
public:
    int maxPower(string s) {
        int maxii=1, cnt=1; 

        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else cnt=1;

            maxii=max(maxii,cnt);
        }

        return maxii;
    }
};

//MAXII should be 1,
// CASE Wrong Answer
// 332 / 333 testcases passed

// Input s ="j"
// Output 0
// Expected 1