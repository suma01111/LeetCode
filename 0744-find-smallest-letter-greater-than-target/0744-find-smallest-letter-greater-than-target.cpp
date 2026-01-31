class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l=0;
        int h = n-1;
        char ans = letters[0];   
        while(l<=h){
            int m = l+ (h-l)/2;
            if(letters[m]>target){
                 h=m-1;
                 ans = letters[m];
            }
            else l=m+1;
        }
        return ans;
    }
};