//two pointer

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        int i=0,j=0;

        while(i<n || j<m){
            int num1 = 0, num2=0;

            //extract num1
            while(i<n && version1[i] != '.'){
                num1 = num1*10 + (version1[i] - '0');
                i++;
            }

            //extract num2
            while(j<m && version2[j] != '.'){
                num2 = num2*10 + (version2[j] - '0');
                j++;
            }

            //compare 
            if(num1 > num2) return 1;
            if(num2 > num1) return -1;

            i++; //skip dots
            j++;

        }
        return 0 ;
    }
    
};