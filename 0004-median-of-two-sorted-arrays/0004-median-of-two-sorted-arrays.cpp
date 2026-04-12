//Optimal BS ->. TC = O(log(min(m,n)))  SC= O(1) , IMPPP
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() > nums2.size()) {//num1 size should be less then num2
            return findMedianSortedArrays(nums2,nums1); //IMPP
            }

        int m = nums1.size();
        int n=nums2.size();

        int l=0, h=m; //IMPP
        while(l<=h){
            int Px = l+(h-l)/2 ; //mid.. nums1 partion till mid indx, X1
            int Py = (m+n+1)/2 - Px ; //nums2 partion, X2

            //left half
            int x1  = (Px == 0) ? INT_MIN : nums1[Px-1];
            int x3 = (Px == m) ? INT_MAX : nums1[Px];
            
            //right half
            int x2  = (Py == 0) ? INT_MIN : nums2[Py-1];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];
            
            if(x1 <= x4 && x2 <= x3) { //median
                if((m+n)%2 == 0)
                    return (max(x1, x2) + min(x3, x4))/2.0; 
                else return max(x1, x2);

            } 
            else if(x1 > x4) {
                h = Px-1;
            } 
            else {
                l = Px+1;
            }


        }

        return -1 ;
    }
};