class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // (Linklist cycle)
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);  //loop runs till slow is not equal to fast


        //find the starting (entrance) point of cycle
        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
}; //O(n)