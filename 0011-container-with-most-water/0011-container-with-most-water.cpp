class Solution {
public:
    int maxArea(vector<int>& height) {
        //left and right are index num
        int left =0;
        int right = height.size()-1;
        int max=0;

        while(left<right){
            int ht_left = height[left];
            int ht_right = height[right];

            int length = (right-left);
            int min_ht = min(ht_left,ht_right);
            int area = (length * min_ht);

            //updating max area
            max = std::max(max,area);

            if(ht_left<ht_right) left++;
            else right--;
        }
        return max;
    }
};