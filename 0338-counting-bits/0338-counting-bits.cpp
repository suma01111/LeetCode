class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);

        for(int i = 1; i <= n; i++){
            ans[i] = ans[i & (i-1)] + 1;
        }

        return ans;
    }
};

/*
Small Dry Run (n = 5)
i	binary	i&(i-1)	ans[i]
0	000	        —	0
1	001	        0	1
2	010	        0	1
3	011	        2	2
4	100	        0	1
5	101	        4	2
OUTPUT: [0,1,1,2,1,2]
*/