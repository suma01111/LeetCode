class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas =0;
        int totalCost =0;

        for(int i=0;i<gas.size();i++){  //for (int val : gas) {totGas += val};
            totalGas += gas[i];
        }
        for(int i=0;i<cost.size();i++){
            totalCost += cost[i];
        }

        //base case
        if(totalGas < totalCost) return -1;

        int currGas = 0, start =0;
        for(int j=0; j<gas.size();j++){
            currGas += gas[j]-cost[j];
            if(currGas < 0){
                currGas =0;
                start = j+1;
            }
        }
        return start;
    }
};