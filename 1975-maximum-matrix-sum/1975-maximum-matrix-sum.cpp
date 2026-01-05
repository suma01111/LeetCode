/*
logic : if negative cnt is even , sum all elements 
        else neg cnt id odd, sum - 2(smallest number ) 
        ;;;;;;; 2 multiply because we first counted that number in sum so to        remove     it we multiplied 2
*/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long sum =0;
        long long negCnt =0;
        long long smallest = LLONG_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0){
                    negCnt++;
                }
                long long val = llabs(matrix[i][j]);
                sum +=val;
                smallest = min(smallest, val);
            }
        }
        if(negCnt % 2==0) return sum;
        else return (sum-2*(smallest));
    }
};