class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();

        vector<int> temp(n,0);
        int k=0,i=0;

        while(k<n && i<n){
            if(arr[i]!=0){
                temp[k]=arr[i];
                cout<<"X";
                k++;
                i++;
            }
            else{ //arr[i]==0
            cout<<"Y";
                temp[k]=arr[i];
                k++;
                if(k<n)temp[k++] = arr[i];
                i++;
            }
        }

        for(int i=0;i<n;i++){
            arr[i]=temp[i];
        }
    }
};