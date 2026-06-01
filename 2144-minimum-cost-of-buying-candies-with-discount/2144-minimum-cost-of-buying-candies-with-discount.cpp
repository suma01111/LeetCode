class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(), greater<int>());

        int totalcost=0;
        for(int i=0;i<cost.size();i++){
            //skip every 3rd candy
            if(((i+1)%3)!=0) totalcost += cost[i];
        }

        return totalcost;

    }
};