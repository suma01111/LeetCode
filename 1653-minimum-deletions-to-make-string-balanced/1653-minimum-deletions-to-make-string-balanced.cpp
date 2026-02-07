class Solution {
public:
    int minimumDeletions(string s) {
        int cnt =0; // number of 'b' seen so far
        int del = 0; // minimum deletions needed
        for(char ch : s){    
            if(ch =='b') cnt++;
            else{       // ch == 'a'
                del = min(del+1,cnt);
            }
        }
        return del;
    }
};