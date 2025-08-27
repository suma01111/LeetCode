class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDia = 0;
        int maxArea=0;
        for(auto &dim : dimensions){
            int l = dim[0];
            int b = dim[1];
            int dia = l*l + b*b;
            int area = l*b;

            if(maxDia<dia){
                maxDia = dia;
                maxArea = area;
            } 
            else if(dia == maxDia) {
                maxArea = max(maxArea,area);
            }
        }
        return maxArea;
    }
};




