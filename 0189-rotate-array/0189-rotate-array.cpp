//Three step process ,brute force submission1
//1) temp array mai k tak ke element store karege (0 to k tak loop)
//2) arr shift hoga , k+1 array =arr[0] (0 to n-k tak loop)
//3) last ke arr places temp sai fill karege  (n-k to n tak loop)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        k = k % n; // Handle cases where k > n

        
        vector<int> temp(k);
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i]; // Copy last 'k' elements into temp
        }

        // Shift the rest of the elements to the right
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }

        // Place the temporary array elements at the beginning
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
